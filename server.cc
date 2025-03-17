#include "server.h"
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

using namespace std;

namespace AssetInspection {

void MyServer::runServer() {
    string address("0.0.0.0:9000");
    AssetInspectionServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    unique_ptr<grpc::Server> server(builder.BuildAndStart());
    cout << "Server listening on " << address << endl;
    server->Wait();
}

} 