#include "websocket_server/cmd_factory.h"

#include "common/adpc_string.h"
#include "common/common_define.h"

namespace wscmd {

map<string, CommandFactory::CreateFunction> CommandFactory::cmd_create_map_;

CmdPtr CommandFactory::CreateCmd(const string &cmd_str) {
    auto vec = adpc::adpc_string::adpc_string_split(cmd_str, ' ');

    auto it = cmd_create_map_.find(vec[0]);

    if (it != cmd_create_map_.end()) {
        return it->second(std::move(std::move(vec)));
    } else {
        return nullptr;
    }
}

bool CommandFactory::Register(const string &cmd_name, CreateFunction &&create_func) {
    auto it = cmd_create_map_.find(cmd_name);

    printf("%s\n", __PRETTY_FUNCTION__);

    if (it == cmd_create_map_.end()) {
        cmd_create_map_[cmd_name] = std::move(create_func);
        return true;
    } else {
        ADPC_ASSERT(false, "command already exist");
        return false;
    }
}

}  // namespace wscmd
