#pragma once 
#include <iostream>
#include <memory>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cerrno>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <netdb.h>
#include <chrono>
#include <unistd.h>

#define PACKET_SIZE 64

class NetworkProber{
public:
  NetworkProber();
  ~NetworkProber();
  //ping 检测
  bool pingHost(const std::string &host, int &avg_delay, int &loss, const __suseconds_t timeout, const int count); 
  //TCP端口检测
  bool probePort(const std::string &host, int port, int timeout);                                                 

private:
  struct IcmpPacket{
    struct icmphdr hdr_;
    char datas_[PACKET_SIZE - sizeof(icmphdr)];
  };
  unsigned short checkSum(unsigned short *buffer, int length);
  bool solveHostName(const std::string &hostname);
  bool initSocket(const std::string &host, const __suseconds_t timeout);
  void createIcmp(int seq, IcmpPacket &pkt);
  bool recvPing(int timeout, int seq);
  bool sendPing(const int count, const __suseconds_t timeout, int &success, double &total_rtt, timeval &send_time);

private:
  int sock_;
  sockaddr_in dest_;
  std::string resolved_ip_;
  uint16_t pid_;
};
