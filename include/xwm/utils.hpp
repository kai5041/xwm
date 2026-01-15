#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
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

inline void log_if_error(int err, std::string msg) {
  if (err) {
    std::cerr << "[" << colors::RED << "ERROR" << colors::RESET << "]" << " xwm: " << msg
              << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

} // namespace xwm
