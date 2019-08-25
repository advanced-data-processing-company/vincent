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

enum class LogSinkType { kdaily_file, kterminal };

/// copy from spdlog::level::level_enum
/// log level
enum class LogLevel {
  ktrace = SPDLOG_LEVEL_TRACE,
  kdebug = SPDLOG_LEVEL_DEBUG,
  kinfo = SPDLOG_LEVEL_INFO,
  kwarn = SPDLOG_LEVEL_WARN,
  kerr = SPDLOG_LEVEL_ERROR,
  kcritical = SPDLOG_LEVEL_CRITICAL,
  koff = SPDLOG_LEVEL_OFF,
};

class LogConfiguration {
  friend class Log;

  // configuration per sink
  bool termial_enabled_{true};
  bool daily_file_enabled_{true};
  LogLevel daily_file_level_{LogLevel::kinfo};
  LogLevel terminal_level_{LogLevel::kwarn};
  size_t id_{0}; // 0 for invalid
};

} // namespace adpc
