#pragma once

#include <map>
#include <string>

namespace wscmd {
class CommandFactory;
}

using std::map;
using std::string;
using wscmd::CommandFactory;

class WSServer {
   public:
    WSServer();
    ~WSServer() = default;

   private:
    void get_command_paramaters();

   private:
};
