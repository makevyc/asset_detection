#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "check.grpc.pb.h" // 确保包含生成的文
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <mutex>
using namespace std;

using namespace std;using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using AssetInspection::AssetInspectionService;
using AssetInspection::Check;
using AssetInspection::IPResponse;
using AssetInspection::TCPResponse;

class AssetInspectionClient {
    
public:
    explicit AssetInspectionClient(std::shared_ptr<Channel> channel)
        : stub_(AssetInspectionService::NewStub(channel)) {}

    void CheckIP(const std::string &ip) {
        Check request;
        request.set_target(ip);

        IPResponse response;
        ClientContext context;

        Status status = stub_->CheckIP(&context, request, &response);

        if (status.ok()) {
            //在这里输出合法的
            std::cout<<response.delay()<<endl;
            std::cout<<response.loss()<<endl;

        } else {
            std::cerr << "RPC failed: " << status.error_code() << ": " << status.error_message() << std::endl;
        }
    }

    void CheckPort(const std::string &ip, int port) {
        Check request;
        request.set_target(ip + ":" + std::to_string(port) + ":500");

        TCPResponse response;
        ClientContext context;

        Status status = stub_->CheckPort(&context, request, &response);

        if (status.ok()) {
            std::cout << "Port Check Result:"
                      << "Port " << ip << ":" << port << " is "
                      << (response.flag() ? "open" : "closed") << ".\n";
        } else {
            std::cerr << "RPC failed: " << status.error_code() << ": " << status.error_message() << std::endl;
        }
    }

private:
    std::unique_ptr<AssetInspectionService::Stub> stub_;
};


std::string GenerateVirtualIP(int timeout, int count) {
    std::ostringstream oss;
    // 随机生成IP地址
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 254);

    oss << dis(gen) << "." << dis(gen) << "." << dis(gen) << "." << dis(gen)
        << ":" << timeout << ":" << count;
    return oss.str();
}

//112.74.44.178

int main(int argc, char **argv) {
    std::string server_address("127.0.0.1:9000");
    AssetInspectionClient client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));

    const int NUM_THREADS = 100;  // 线程数量
    const int TIMEOUT = 100;      // 超时时间（ms）
    const int COUNT = 5;          // ping次数

    std::string ip ; 
    std::vector<std::string> domains = {
        "ouryun.cn",
        "zt.ouryun.cn",
        "baidu.com",
        "taobao.com",
        "jd.com",
        "sina.com.cn",
        "163.com",
        "sohu.com",
        "alibaba.com",
        "qq.com",
        "weibo.com",
        "douyin.com",
        "tencent.com",
        "youku.com",
        "meituan.com",
        "xiaomi.com",
        "douban.com",
        "bilibili.com",
        "sogou.com",
        "cctv.com",
        "zhihu.com",
        "360.com",
        "gome.com.cn",
        "letv.com",
        "baike.com",
        "jike.com",
        "mogu.com",
        "fudan.edu.cn",
        "pinduoduo.com",
        "yandex.cn",
        "v2ex.com",
        "tianya.cn",
        "chinaz.com",
        "guazi.com",
        "huangye88.com",
        "cnblogs.com",
        "hao123.com",
        "jumei.com",
        "wanmei.com",
        "z.cn",
        "turing.com",
        "yile.com",
        "58.com",
        "wanfangdata.com.cn",
        "chuangshi.qq.com",
        "cnki.net",
        "51job.com",
        "duowan.com",
        "iask.com",
        "acfun.cn",
        "youhui.baidu.com",
        "yq.aliyun.com",
        "127.0.0.1",
       "172.17.0.2",
        "127.0.0.1",
       "172.16.0.154",
        "google.com",
        "172.17.0.1"
    };
    for(int i=0;i<domains.size();i++){
        client.CheckIP(domains[i]+":500"+":1");
        //client.CheckPort(domains[i],80);
    }
    
    return 0;
}