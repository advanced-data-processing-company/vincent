#include "log/log.h"
#include "common/os.h"

#include "mutex"

namespace adpc {

using std::make_shared;
using std::make_unique;

static std::once_flag log_init_path_once_flag;
static const string   log_pattern{"[%C-%m-%d %H:%M:%S] [%^%l%$] [%n] [thread %t] %v"};

Log::Log()
    : daily_file_sink_{make_shared<spdlog::sinks::daily_file_sink_mt>("logs/daily", 2, 30, true)},
      terminal_sink_{make_shared<spdlog::sinks::stdout_color_sink_mt>()} {
    using namespace spdlog;
    logPtr log = make_unique<logger>("global", sinks_init_list{daily_file_sink_, terminal_sink_});
    log->set_level(level::warn);
    log->set_pattern(log_pattern.c_str());

    // number 0 is the default/global log
    logs_.push_back(std::move(log));
}

void Log::InitPath() {
    std::call_once(log_init_path_once_flag, []() -> void {
        if (!os::FileExists("./logs")) {
            system("mkdir logs");
        }
    });
}

void Log::SetLevel(const string &module_name, const LogSinkType type, const LogLevel level) {
    assert(level < LogLevel::off);

    auto &module_config = get_module_config(module_name);

    switch (type) {
        case kdaily_file: {
            module_config.daily_file_level_ = level;
            break;
        }
        case kterminal: {
            module_config.terminal_level_ = level;
        }
    }
}

void Log::Enable(const string &module_name, const LogSinkType type, const bool enable) {
    auto &module_config = get_module_config(module_name);

    switch (type) {
        case kdaily_file: {
            module_config.daily_file_enabled_ = enable;
            break;
        }
        case kterminal: {
            module_config.termial_enabled_ = enable;
        }
    }
}

LogConfiguration &Log::get_module_config(const string &module_name) {
    auto it = config_.find(module_name);
    assert(it != config_.end());
    return it->second;
}

size_t Log::AddModule(string &&module_name, const LogLevel level, const bool terminal,
                      const bool daily_file) {
    assert(terminal || daily_file);
    assert(!module_name.empty());
    unique_ptr<spdlog::logger> log;

    if (terminal && daily_file) {
        log = std::make_unique<spdlog::logger>(
            module_name, spdlog::sinks_init_list{daily_file_sink_, terminal_sink_});
    } else if (terminal) {
        log = std::make_unique<spdlog::logger>(module_name, terminal_sink_);
    } else if (daily_file) {
        log = std::make_unique<spdlog::logger>(module_name, daily_file_sink_);
    }

    log->set_level(static_cast<spdlog::level::level_enum>(level));
    log->set_pattern(log_pattern.c_str());

    logs_.push_back(std::move(log));
    return logs_.size() - 1;
}

}  // namespace adpc
