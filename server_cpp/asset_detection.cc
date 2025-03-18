
#include "asset_detection.h"

namespace AssetInspection {
grpc::Status AssetInspectionServiceImpl::CheckIP(grpc::ServerContext *context, const Check *request, IPResponse *response){
  // 数据格式为 ip:timeout:count
  std::string target = request->target();
  std::string ip;
  int timeout, count, delay = -1, loss = 100;
  splitRequest(target, ip, timeout, count);
  bool success = network_prober_.pingHost(ip, delay, loss, timeout, count);
  response->set_delay(success ? delay : -1);
  response->set_loss(success ? loss : 100);
    
  // 格式化输出
  std::ostringstream oss;
  oss << std::left << std::setw(24) << getCurrentTimeWithMilliseconds()
      << "===== " << std::setw(20) << "Ping检测  "
      << std::setw(20) << ip
      << std::setw(20) << ((success) ? "成功" : "失败")
      << "-->延时: " << std::setw(5) << delay << "ms, "
      << "丢包率: " << std::setw(3) << loss << "%";
  std::cout << oss.str() << std::endl;

  return grpc::Status::OK;
}

grpc::Status AssetInspectionServiceImpl::CheckPort(grpc::ServerContext *context, const Check *request, TCPResponse *response){
  // 数据格式为ip:port:timeout
  std::string target = request->target();
  std::string ip;
  int port, timeout;
  splitRequest(target, ip, port, timeout);
  bool is_open = network_prober_.probePort(ip, port, timeout);
  response->set_flag(is_open);

  //格式化输出
  std::ostringstream oss;
  oss << std::left << std::setw(24) << getCurrentTimeWithMilliseconds()
      << "===== " << std::setw(20) << "TCP 探测  "
      << std::setw(20) << port
      << std::setw(20) << ((is_open) ? "开放" : "关闭");
  std::cout << oss.str() << std::endl;
  return grpc::Status::OK;
}

void AssetInspectionServiceImpl::splitRequest(std::string &request, std::string &param1, int &param2, int &param3){
  size_t pos = request.find(":");
  param1 = request.substr(0, pos);
  request.erase(0, pos + 1);
  pos = request.find(":");
  param2 = stoi(request.substr(0, pos));
  request.erase(0, pos + 1);
  param3 = stoi(request);
}

std::string AssetInspectionServiceImpl::getCurrentTimeWithMilliseconds(){
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() % 1000;
  auto seconds = std::chrono::system_clock::to_time_t(now);
  std::tm tm_time = *std::localtime(&seconds);

  std::stringstream ss;
  ss << std::put_time(&tm_time, "%Y-%m-%d %H:%M:%S") << "." << std::setfill('0') << std::setw(3) << millis;
  return ss.str();
}

} // namespace AssetInspectionS