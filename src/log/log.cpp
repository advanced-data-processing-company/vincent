#include "log/log.h"
#include "common/os.h"

#include <mutex>

namespace adpc {

using std::make_shared;
using std::make_unique;

static const string log_pattern{"[%C-%m-%d %H:%M:%S] [%^%l%$] [%n][%@] [thread %t] %v"};

Log::Log() {
    using namespace spdlog;

    // create path if needed
    if (!os::FileExists("./logs")) {
        system("mkdir logs");
    }

    // sinks
    daily_file_sink_ = make_shared<sinks::daily_file_sink_mt>("logs/daily", 2, 30, true);
    terminal_sink_   = make_shared<spdlog::sinks::stdout_color_sink_mt>();

    // global log
    logPtr log = make_unique<logger>("global", sinks_init_list{daily_file_sink_, terminal_sink_});
    log->set_level(level::warn);
    log->set_pattern(log_pattern.c_str());

    // number 0 is the default/global log
    logs_.push_back(std::move(log));
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

void Log::Print() const {
    logs_[0]->debug(print_to_string_stream().str());
}

string Log::PrintToString() const {
    return print_to_string_stream().str();
}

stringstream Log::print_to_string_stream() const {
    stringstream ss;
    ss << "============================\n";
    for (size_t i = 0; i < logs_.size(); ++i) {
        ss << "[" << logs_[i]->name() << "]"
           << " [" << i << "]"
           << " [" << logs_[i]->level() << "]";
    }
    ss << "\n============================";

    return ss;
}

}  // namespace adpc
