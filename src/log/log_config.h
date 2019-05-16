/**
 * @file log_config.h
 * @author tonghao.yuan (michael.19@163.com)
 * @brief configuration for log sinks
 * @version 0.1
 * @date 2019-05-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

#include "spdlog/logger.h"

namespace adpc {

// forward declaration
class Log;

enum LogSinkType { kdaily_file, kterminal };

/// copy from spdlog::level::level_enum
/// log level
enum LogLevel {
    trace    = SPDLOG_LEVEL_TRACE,
    debug    = SPDLOG_LEVEL_DEBUG,
    info     = SPDLOG_LEVEL_INFO,
    warn     = SPDLOG_LEVEL_WARN,
    err      = SPDLOG_LEVEL_ERROR,
    critical = SPDLOG_LEVEL_CRITICAL,
    off      = SPDLOG_LEVEL_OFF,
};

class LogConfiguration {
    friend class Log;

    // configuration per sink
    bool     termial_enabled_{true};
    bool     daily_file_enabled_{true};
    LogLevel daily_file_level_{info};
    LogLevel terminal_level_{warn};
    size_t   id_{0};  // 0 for invalid
};

}  // namespace adpc
