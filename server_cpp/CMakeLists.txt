cmake_minimum_required(VERSION 3.5)
project(my_grpc_server CXX)

set(CMAKE_CXX_STANDARD 17)

# 寻找 Protobuf 和 gRPC 静态库
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# 设置 Protobuf 和 gRPC 的静态库路径
set(PROTOBUF_LIBRARIES protobuf::libprotobuf)
set(gRPC_LIBRARIES gRPC::grpc++ gRPC::grpc)

# 指定静态链接
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

# 源文件
file(GLOB_RECURSE SOURCE_FILES "*.cc" "*.pb.cc" "grpc/*.cc" "grpc/*.pb.cc")
# 创建可执行文件
add_executable(server ${SOURCE_FILES})

# 添加目标包括目录
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 链接依赖库
target_link_libraries(server ${PROTOBUF_LIBRARIES} ${gRPC_LIBRARIES})