#ifndef SERVER_H
#define SERVER_H

#include <grpcpp/grpcpp.h>
#include "asset_detection.h"

namespace AssetInspection {

class MyServer {
public:
    void runServer();
};

} 

#endif 