#pragma once

#include <memory>  // for unique_ptr
#include <vector>

/**
 *  websocket command
 */
namespace wscmd {

using std::string;
using std::unique_ptr;
using std::vector;

// forward declare
class ICommand;
using CmdPtr = unique_ptr<ICommand>;

/**
 * @brief Commannd interface
 */
class ICommand {
   public:
    ICommand(vector<string> &&cmd_para);
    virtual ~ICommand() = default;

    /**
     * @brief Execute command
     */
    virtual string Execute() = 0;

    /**
     * @brief Name of the command, must be unique in the whole program
     * @return
     */
    virtual const string &Name() = 0;

   protected:
    vector<string> cmd_para_;

   protected:
    int    cmd_argc_{0};
    char **cmd_argv_{nullptr};
};

}  // namespace wscmd
