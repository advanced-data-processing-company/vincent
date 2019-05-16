#include "log/log.h"
#include "common/os.h"

#include "mutex"

namespace adpc {

using std::make_shared;

static std::once_flag log_init_path_once_flag;

Log::Log()
    : daily_file_sink_{make_shared<spdlog::sinks::daily_file_sink_mt>("logs/daily", 2, 30, true)},
      terminal_sink_{make_shared<spdlog::sinks::stdout_color_sink_mt>()},
      log_(spdlog::logger("vincent_log", {daily_file_sink_, terminal_sink_})) {}

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

}  // namespace adpc
