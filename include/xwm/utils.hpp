#pragma once

#include <iostream>
#include <sstream>

#include <xwm/defs.hpp>

namespace xwm {

namespace colors {
constexpr const char *RED = "\x1b[31m";
constexpr const char *GREEN = "\x1b[32m";
constexpr const char *YELLOW = "\x1b[33m";
constexpr const char *BLUE = "\x1b[34m";
constexpr const char *MAGENTA = "\x1b[35m";
constexpr const char *CYAN = "\x1b[36m";
constexpr const char *RESET = "\x1b[0m";
} // namespace colors

enum class LogLevel : u8 {
  NONE = 0,
  DEBUG,
  INFO,
  WARN,
  _ERROR,
  FATAL,
};

inline const char *log_level_to_color(LogLevel level) {
  switch (level) {
  case LogLevel::DEBUG:
    return colors::CYAN;
  case LogLevel::INFO:
    return colors::GREEN;
  case LogLevel::WARN:
    return colors::YELLOW;
  case LogLevel::_ERROR:
    return colors::RED;
  case LogLevel::FATAL:
    return colors::MAGENTA;
  default:
    return colors::RESET;
  }
}

inline const char *log_level_to_string(LogLevel level) {
  switch (level) {
  case LogLevel::DEBUG:
    return "DEBUG";
  case LogLevel::INFO:
    return "INFO";
  case LogLevel::WARN:
    return "WARN";
  case LogLevel::_ERROR:
    return "ERROR";
  case LogLevel::FATAL:
    return "FATAL";
  default:
    return "NONE";
  }
}

template <typename... Args>
inline void log_message(LogLevel level, Args &&...args) {
  std::stringstream ss;
  ss << "[" << log_level_to_color(level) << log_level_to_string(level)
     << colors::RESET << "]"
     << " ";
  (ss << ... << std::forward<Args>(args));
  ss << std::endl;
  std::cout << ss.str();
}

inline void set_log_level(LogLevel level) {
  static LogLevel &current_level = *new LogLevel(level);
  current_level = level;
}

inline bool should_log(LogLevel level) {
  static LogLevel &current_level = *new LogLevel(LogLevel::DEBUG);
  return static_cast<u8>(level) >= static_cast<u8>(current_level);
}

template <typename... Args>
inline void log_if(LogLevel level, bool condition, Args &&...args) {
  if (condition && should_log(level)) {
    log_message(level, std::forward<Args>(args)...);
  }
}

} // namespace xwm
