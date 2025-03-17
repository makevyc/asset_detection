cmake_minimum_required(VERSION 3.5)
project(my_grpc_client CXX)

set(CMAKE_CXX_STANDARD 17)

# Find Protobuf and gRPC
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

# Set Protobuf and gRPC libraries
set(PROTOBUF_LIBRARIES protobuf::libprotobuf)
set(gRPC_LIBRARIES gRPC::grpc++ gRPC::grpc)

# Set the linker flags to link statically
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Source files
set(SOURCE_FILES
    client.cpp
    check.pb.cc
    check.grpc.pb.cc
)

# Create executable
add_executable(client ${SOURCE_FILES})

# Link libraries
target_link_libraries(client
    ${PROTOBUF_LIBRARIES}
    ${gRPC_LIBRARIES}
)