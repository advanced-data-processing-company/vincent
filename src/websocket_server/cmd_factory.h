#pragma once

#include "map"
#include "websocket_server/command.h"

namespace wscmd {

using std::map;

/**
 * @brief factory to create command, user of command should use this factory instead
 * of direct new/delete
 */
class CommandFactory {
    //    friend class adpctl::Singleton<wscmd::CommandFactory>;

   public:
    //    using CreateFunction = function<CmdPtr(vector<string> &&cmd_para)>;
    using CreateFunction = CmdPtr (*)(vector<string> &&cmdpara);

    /**
     * @brief create a command according to the given `name`
     * @param cmd_name  command name
     * @param para      command parameters
     *
     * @return nullptr on failure
     */
    static CmdPtr CreateCmd(const string &cmd_string);

    /**
     * @brief Register a command, every command should call this function before
     * program starts
     *
     * @param cmd_name      name of the command, must be unique in a process space
     * @param create_func   function to create a cmd
     * @return              true if succeed, else false
     */
    static bool Register(const string &cmd_name, CreateFunction &&create_func);

   private:
    CommandFactory()          = delete;
    virtual ~CommandFactory() = delete;

   public:
    static map<string, CreateFunction> cmd_create_map_;
};

}  // namespace wscmd
