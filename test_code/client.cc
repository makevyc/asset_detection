#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "grpc/check.grpc.pb.h"
#include <vector>

using grpc::Channel;
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

    void CheckIP(const std::string &target) {
        Check request;
        request.set_target(target);

        IPResponse response;
        ClientContext context;

        Status status = stub_->CheckIP(&context, request, &response);

        if (status.ok()) {
            std::cout << "Ping Results for " << target << ":\n"
                      << "Average Delay: " << response.delay() << "ms\n"
                      << "Packet Loss: " << response.loss() << "%\n"
                      << "------------------------" << std::endl;
        } else {
            std::cerr << "RPC failed: " << status.error_code() << ": " 
                      << status.error_message() << std::endl;
        }
    }

    void CheckPort(const std::string &ip, int port) {
        Check request;
        request.set_target(ip + ":" + std::to_string(port) + ":100");

        TCPResponse response;
        ClientContext context;

        Status status = stub_->CheckPort(&context, request, &response);

        if (status.ok()) {
            std::cout << "Port Check: " << ip << ":" << port << " - "
                      << (response.flag() ? "OPEN" : "CLOSED") << "\n"
                      << "------------------------" << std::endl;
        } else {
            std::cerr << "RPC failed: " << status.error_code() << ": " 
                      << status.error_message() << std::endl;
        }
    }

private:
    std::unique_ptr<AssetInspectionService::Stub> stub_;
};

int main(int argc, char **argv) {
    std::string server_address("127.0.0.1:9000");
    AssetInspectionClient client(
        grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));

    // 测试目标列表（包含域名和IP）
    std::vector<std::string> targets = {
        "ouryun.cn",    "baidu.com",    "8.8.8.8",
        "1.1.1.1",     "example.com",  "github.com",
        "127.0.0.1",   "10.0.0.1",     "172.16.0.1",
        "192.168.1.1", "www.cloudflare.com", "api.weixin.qq.com"
    };

    // 常用端口列表
    std::vector<int> common_ports = {
        80,    // HTTP
        443,   // HTTPS
        22,    // SSH
        3389,  // RDP
        53,    // DNS
        3306,  // MySQL
        5432,  // PostgreSQL
        6379,  // Redis
        8080,  // HTTP Alt
        8443   // HTTPS Alt
    };

    // 执行检测
    for (const auto& target : targets) {
        // 格式：ip:timeout:count
        client.CheckIP(target + ":100:1");
        // 端口检测
        for (int port : common_ports) {
            client.CheckPort(target, port);
        }
    
    }


    return 0;
}