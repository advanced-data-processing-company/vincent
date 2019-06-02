/**
 * @file log.h
 * @author tonghao.yuan (michael.19@163.com)
 * @brief log module of vincent
 *
 * This log have multiple front-end and multiple back-end
 * every module can have its own front-end by call @sa AddModule
 * ervey module can have its own log level
 * @warning placehoder is `{}`
 *
 * @version 0.1
 * @date 2019-05-17
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "adpctl/singleton.h"  // for singleton
#include "common/common_define.h"
#include "log/log_config.h"

#include <atomic>  // for thread save write to bool
#include <map>
#include <memory>  // for smart pointer
#include <sstream>
#include <string>
#include <vector>

#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace adpc {

using std::map;
using std::shared_ptr;
using std::string;
using std::stringstream;
using std::unique_ptr;
using std::vector;

/**
 * @brief The log class for vincent
 *
 * contains one daily file and a color terminal
 *
 * destination path of log is ./log/
 *
 */
class Log {
    friend class adpctl::Singleton<Log>;

   public:
#define ADPC_LOG_NAME(lvl)                                                        \
    template <typename... Args>                                                   \
    void lvl(size_t      module,                                                  \
             const char *file,                                                    \
             int         line,                                                    \
             const char *func,                                                    \
             const char *fmt,                                                     \
             const Args &... args) {                                              \
        assert(module < logs_.size());                                            \
        logs_[module]->log({file, line, func}, spdlog::level::lvl, fmt, args...); \
    }

    ADPC_LOG_NAME(critical)
    ADPC_LOG_NAME(err)
    ADPC_LOG_NAME(warn)
    ADPC_LOG_NAME(info)
    ADPC_LOG_NAME(debug)
    ADPC_LOG_NAME(trace)

#undef ADPC_LOG_NAME

    /**
     * @brief SetLevel  set log level for a module
     * @param id        module id, retruned from @sa AddModule
     * @param level     level
     * @param type      type, terminal or daily file,**NOT USED NOW**
     */
    void SetLevel(const size_t &id, const LogLevel level = ktrace,
                  const LogSinkType type = kterminal) {
        assert(id < logs_.size());
        (void)type;

        logs_[id]->set_level(static_cast<spdlog::level::level_enum>(level));
    }

    /**
     * @brief add a log for a module
     * @param module_name   module name, show in the log message
     * @param level         default log level
     * @param terminal      whether show in terminal log
     * @param daily_file    whether show in daily file log
     * @return
     */
    size_t AddModule(string &&module_name, const LogLevel level = LogLevel::kwarn,
                     const bool terminal = true, const bool daily_file = true);

    /**
     * @brief Print log information
     */
    void Print() const;

    string PrintToString() const;

   private:
    Log();
    ~Log() = default;

    stringstream print_to_string_stream() const;

   private:
    using logPtr = unique_ptr<spdlog::logger>;

    // one logger frontend and two backend
    shared_ptr<spdlog::sinks::daily_file_sink_mt>   daily_file_sink_{nullptr};
    shared_ptr<spdlog::sinks::stdout_color_sink_mt> terminal_sink_{nullptr};
    vector<logPtr>                                  logs_;

    /// module name <-> configuration
    map<string, LogConfiguration> config_;
};

#define LOG adpctl::Singleton<adpc::Log>::GetInstance()

}  // namespace adpc
