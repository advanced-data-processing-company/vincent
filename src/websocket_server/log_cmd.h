#pragma once

#include "websocket_server/command.h"

namespace wscmd {

using std::shared_ptr;

class LogCommand final : public ICommand {
   public:
    LogCommand(vector<string>&& cmd_para);
    ~LogCommand() override = default;
    static CmdPtr Create(vector<string>&& cmd_para);

    string        Execute() override;
    const string& Name() override;

   private:
    string cmd_handler_list() const;
    string cmd_handler_set(const size_t module, const size_t level) const;
    string cmd_handler_reset(const size_t module) const;

   private:
    static const string cmd_name_;

   public:
    static bool is_registered_;
};

}  // namespace wscmd
