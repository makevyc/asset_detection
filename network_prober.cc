// network_prober.cc
#include "network_prober.h"

NetworkProber::NetworkProber() : sock_(-1) {}

NetworkProber::~NetworkProber() {
    if (sock_ != -1) {
        close(sock_);
    }
}

unsigned short NetworkProber::checkSum(unsigned short *buffer, int length) {
    unsigned long sum = 0;
    while (length > 1) {
        sum += *buffer++;
        length -= 2;
    }
    if (length == 1) {
        sum += *(unsigned char*)buffer;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

bool NetworkProber::solveHostName(const std::string& hostname) {
    addrinfo hints{}, *result;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int ret = getaddrinfo(hostname.c_str(), nullptr, &hints, &result);
    if (ret != 0) {
        std::cerr << "DNS Error: " << gai_strerror(ret) << std::endl;
        return false;
    }

    for (auto p = result; p != nullptr; p = p->ai_next) {
        if (p->ai_family == AF_INET) {
            sockaddr_in* addr = (sockaddr_in*)p->ai_addr;
            char buf[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &addr->sin_addr, buf, sizeof(buf));
            resolved_ip_ = buf;
            freeaddrinfo(result);
            return true;
        }
    }
    freeaddrinfo(result);
    return false;
}

bool NetworkProber::initSocket(const std::string& host, const __suseconds_t timeout) {
    if (!solveHostName(host)) {
        std::cerr << "Failed to resolve hostname: " << host << std::endl;
        return false;
    }

    pid_ = getpid() & 0xFFFF;
    sock_ = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock_ < 0) {
        perror("socket");
        return false;
    }

    timeval tv = {timeout/1000, 0};
    setsockopt(sock_, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    
    dest_.sin_family = AF_INET;
    if (inet_pton(AF_INET, resolved_ip_.c_str(), &dest_.sin_addr) <= 0) {
        std::cerr << "Invalid IP address: " << resolved_ip_ << std::endl;
        close(sock_);
        sock_ = -1;
        return false;
    }
    return true;
}

void NetworkProber::createIcmp(int seq, IcmpPacket& pkt) {
    pkt.hdr_.type = ICMP_ECHO;
    pkt.hdr_.code = 0;
    pkt.hdr_.un.echo.id = htons(pid_);
    pkt.hdr_.un.echo.sequence = htons(seq);
    strncpy(pkt.datas_, "PINGTEST", sizeof(pkt.datas_) - 1);
    pkt.hdr_.checksum = 0;
    pkt.hdr_.checksum = checkSum(reinterpret_cast<unsigned short*>(&pkt), sizeof(pkt));
}

bool NetworkProber::recvPing(int timeout, int seq) {
    auto start = std::chrono::steady_clock::now();
    while (std::chrono::steady_clock::now() - start < std::chrono::microseconds(timeout * 1000)) {
        char buffer[1024];
        sockaddr_in src{};
        socklen_t src_len = sizeof(src);
        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(sock_, &read_set);
        timeval select_timeout{0, 10000}; //每个10ms检测一次，可以解决ping 本机地址 会收到两个数据包的情况

        if (select(sock_ + 1, &read_set, nullptr, nullptr, &select_timeout) <= 0)  continue;

        ssize_t recv_len = recvfrom(sock_, buffer, sizeof(buffer), 0, (sockaddr*)&src, &src_len);
        if (recv_len <= 0) continue;

        icmphdr* recv_hdr = nullptr;
        if (recv_len >= static_cast<ssize_t>(sizeof(iphdr) + sizeof(icmphdr))) {
            iphdr* ip_hdr = reinterpret_cast<iphdr*>(buffer);
            if (ip_hdr->version == 4 && ip_hdr->ihl >= 5) {
                int ip_hlen = ip_hdr->ihl * 4;
                recv_hdr = reinterpret_cast<icmphdr*>(buffer + ip_hlen);
            }
        }

        if (!recv_hdr || recv_hdr->type != ICMP_ECHOREPLY) continue;
        if (ntohs(recv_hdr->un.echo.id) != pid_ || 
            ntohs(recv_hdr->un.echo.sequence) != seq) continue;

        char src_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &src.sin_addr, src_ip, INET_ADDRSTRLEN);
        return resolved_ip_ == src_ip;
    }
    return false;
}

bool NetworkProber::sendPing(const int seq, const __suseconds_t timeout,int& success, double& total_rtt,timeval& send_time) {
    IcmpPacket pkt{};
    createIcmp(seq, pkt);
    gettimeofday(&send_time, nullptr);
    if (sendto(sock_, &pkt, sizeof(pkt), 0, (sockaddr*)&dest_, sizeof(dest_)) <= 0) {
        perror("sendto");
        return false;
    }
    return true;
}

bool NetworkProber::pingHost(const std::string& host, int& avg_delay, int& loss,const __suseconds_t timeout, const int count) {
    if (!initSocket(host, timeout)) return false;
    int success = 0;
    double total_rtt = 0.0;
    timeval send_time,recv_time;
    for(int i=0;i<count;i++){
        if(!sendPing(i, timeout, success, total_rtt,send_time)){
            //std::cout<<"seq = "<<i<<" sendPing fial! "<< std::endl;
            continue;
        }
        if(!recvPing(timeout, i)){
            //std::cout<<"seq = "<<i<<" recvPing fial! "<< std::endl;
            continue;
        }
        gettimeofday(&recv_time, nullptr);
        long long rtt_us = (recv_time.tv_sec - send_time.tv_sec) * 1000000LL + 
                            (recv_time.tv_usec - send_time.tv_usec);
        total_rtt += rtt_us / 1000.0;
        success++;
    }
    if ( 0 == success) {
        avg_delay = -1;
        loss = 100;
        return false;
    }
    avg_delay = static_cast<int>(total_rtt / success);
    loss = (count - success) * 100 / count;
    return true;
}

bool NetworkProber::probePort(const std::string& host, int port, int timeout) {
    if (!solveHostName(host)) return false;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return false;

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, resolved_ip_.c_str(), &addr.sin_addr);

    timeval tv_timeout{0, timeout * 1000};
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv_timeout, sizeof(tv_timeout));

    bool open = connect(sock, (sockaddr*)&addr, sizeof(addr)) == 0;
    close(sock);
    return open;
}