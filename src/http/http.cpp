#include "http.h"

namespace adpc {
http::http() {}
http::~http() {}

bool http::sendRequest(void (*func)(char *)) const {

  if (!connectServer()) {
    return false;
  }

  func = nullptr;
  return false;
}

bool http::connectServer() const {

  if (!CFG.Load()) {
    return false;
  }

  // connect to server configured in .ini file
  std::string master_server_ip = CFG.GetString("MasterServer", "server_ip");
  int64_t master_server_port = CFG.GetInt("MasterServer", "port");
  return false;
}
} // namespace adpc
