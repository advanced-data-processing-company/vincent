#include "websocket_server/log_cmd.h"
#include "common/common_define.h"
#include "config/config.h"
#include "cxxopts/cxxopts.hpp"
#include "log/log.h"
#include "websocket_server/cmd_factory.h"

namespace wscmd {

using std::make_unique;

using cxxopts::OptionAdder;
using cxxopts::Options;
using cxxopts::ParseResult;
using cxxopts::value;

const string LogCommand::cmd_name_ = "log";

bool LogCommand::is_registered_ = CommandFactory::Register("log", LogCommand::Create);

LogCommand::LogCommand(vector<string>&& cmd_para) : ICommand(std::move(cmd_para)) {}

CmdPtr LogCommand::Create(vector<string>&& cmd_para) {
    return make_unique<LogCommand>(std::move(cmd_para));
}

string LogCommand::Execute() {
    Options options(cmd_argv_[0], " - log configuration");

    try {
        // first create a option adder
        OptionAdder op_adder = options.add_options();

        // add options
        op_adder("l, level", "level", value<size_t>());
        op_adder("m,module", "module", value<size_t>());
        op_adder("h,help", "Print help");

        // add command and specify required options if needed
        options.cmd("set", {"l", "m"}, "set log level to `l` for module `m`");
        options.cmd("reset", {"m"}, "rest log level to default for module `m`");
        options.cmd("list", {}, "print all log info");
        auto result = options.parse(cmd_argc_, cmd_argv_);

        if (result.count("help")) {
            return options.help();
        }

        if (result.GotCommand("set")) {
            return cmd_handler_set(result["m"].as<size_t>(), result["l"].as<size_t>());
        }

        if (result.GotCommand("reset")) {
            return cmd_handler_reset(result["m"].as<size_t>());
        }

        if (result.GotCommand("list")) {
            return cmd_handler_list();
        }

    } catch (const cxxopts::OptionException& e) {
        return e.what();
    }

    return "nunkown error";
}

const string& LogCommand::Name() {
    return cmd_name_;
}

string LogCommand::cmd_handler_set(const size_t module, const size_t level) const {
    LOG.SetLevel(module, static_cast<adpc::LogLevel>(level));
    return "ok";
}

string LogCommand::cmd_handler_list() const {
    return LOG.PrintToString();
}

string LogCommand::cmd_handler_reset(const size_t module) const {
    // TODO should read from config file
    LOG.SetLevel(module, adpc::LogLevel::kwarn);
    return "ok";
}

}  // namespace wscmd
