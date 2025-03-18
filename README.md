# 资产监控告警项目【第三批】C2组 

# 项目介绍
基于gRCP实现服务端Ping检测和TCP端口探测，server_cpp为服务器代码实现，test_code为客户端测试代码



# 使用方式
客户端可支持多种语言连接并调用服务器提供的 CheckIP 和 CheckPort 功能 ，用于资产检测 ，这里test_code 为C++的客户端测试代码 

1.部署gRPC相关开发环境

https://grpc.io/docs/languages/cpp/quickstart/

2.分别在server_cpp 和 test_code 目录下执行
mkdir build 
cd build/
cmake 
make

3.构建后先启动服务器
sudo ./server 
4.然后启动客户端 
./client
5.可实现客户端和服务器的通信



