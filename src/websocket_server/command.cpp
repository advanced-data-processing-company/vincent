#include "websocket_server/command.h"

namespace wscmd {

ICommand::ICommand(vector<string> &&cmd_para) : cmd_para_{std::move(cmd_para)} {
    cmd_argc_ = static_cast<int>(cmd_para_.size());
    cmd_argv_ = new char *[static_cast<size_t>(cmd_argc_)];
    for (size_t i = 0; i < cmd_para_.size(); ++i) {
        cmd_argv_[i] = const_cast<char *>(cmd_para_[i].c_str());
    }
}
}  // namespace wscmd
