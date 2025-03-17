#ifndef NETWORK_PROBER_H
#define NETWORK_PROBER_H
#include "grpc/text.grpc.pb.h"
#include "grpc/text.pb.h"
#include "network_prober.h"
#include <chrono>
#include <iomanip>
#include <sstream>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

namespace AssetInspection {

class AssetInspectionServiceImpl : public AssetInspectionService::Service {
public:
    grpc::Status CheckIP(grpc::ServerContext *context, const Check *request, IPResponse *response) override;
    grpc::Status CheckPort(grpc::ServerContext *context, const Check *request, TCPResponse *response) override;
private:
    void splitRequest(std::string &request, std::string &param1, int &param2, int &param3);
    std::string getCurrentTimeWithMilliseconds();//获取时间，用于打印日志

private:
    NetworkProber network_prober_;

};

} // namespace AssetInspection

#endif