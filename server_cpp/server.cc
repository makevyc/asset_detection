#include "server.h"
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

namespace AssetInspection{

void MyServer::runServer(){
  std::string address("0.0.0.0:9000");
  AssetInspectionServiceImpl service;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << address << std::endl;
  server->Wait();
}

}//namespace AssetInspection