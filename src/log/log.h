#pragma once

#include "adpctl/singleton.h"  // for singleton
#include "log/log_config.h"

#include <atomic>  // for thread save write to bool
#include <map>
#include <memory>  // for smart pointer
#include <string>

#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace adpc {

using std::map;
using std::shared_ptr;
using std::string;
using std::unique_ptr;

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
    /**
     * general log function
     * @{
     */
    template <typename... Args>
    void log(LogLevel lvl, const char *fmt, const Args &... args) {
        log_.log(static_cast<spdlog::level::level_enum>(lvl), fmt, args...);
    }

    //    template <typename... Args>
    //    void log(const char *file, int line, const char *func, LogLevel lvl, const char *fmt,
    //             const Args &... args) {
    //        log_.log({file, line, func}, static_cast<spdlog::level::level_enum>(lvl), fmt,
    //        args...);
    //    }

    //    void log(LogLevel lvl, const char *msg) {
    //        log_.log(static_cast<spdlog::level::level_enum>(lvl), msg);
    //    }
    //    void log(const char *file, int line, const char *func, LogLevel lvl, const char *msg) {
    //        log_.log({file, line, func}, static_cast<spdlog::level::level_enum>(lvl), msg);
    //    }
    /** @} */

    //    /**
    //     *special log function
    //     * @{
    //     */
    //    template <typename... Args>
    //    void trace(const char *fmt, const Args &... args);

    //    template <typename... Args>
    //    void debug(const char *fmt, const Args &... args);

    //    template <typename... Args>
    //    void info(const char *fmt, const Args &... args);

    //    template <typename... Args>
    //    void warn(const char *fmt, const Args &... args);

    //    template <typename... Args>
    //    void error(const char *fmt, const Args &... args);

    //    template <typename... Args>
    //    void critical(const char *fmt, const Args &... args);
    //    /** @}*/

    inline void SetLevel(const string &module_name, const LogSinkType type, const LogLevel level);
    inline void Enable(const string &module_name, const LogSinkType type, const bool enable);
    inline void AddModule(string &&module_name, const LogLevel level = LogLevel::warn,
                          const bool terminal = true, const bool daily_file = true);
    void        Init();

   private:
    Log();
    ~Log() = default;

    LogConfiguration &get_module_config(const string &module_name);
    void              create_log_directory();

   private:
    // one logger frontend and two backend
    shared_ptr<spdlog::sinks::daily_file_sink_mt>   daily_file_sink_{nullptr};
    shared_ptr<spdlog::sinks::stdout_color_sink_mt> terminal_sink_{nullptr};
    //    shared_ptr<spdlog::logger>                      log_{nullptr};
    spdlog::logger log_;

    /// module name <-> configuration
    map<string, LogConfiguration> config_;
};

#define LOG adpctl::Singleton<adpc::Log>::GetInstance()

}  // namespace adpc
