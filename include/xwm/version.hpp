#pragma once

#include <string>

namespace xwm {
constexpr int MAJOR = 0;
constexpr int MINOR = 1;
constexpr int PATCH = 1;

inline std::string get_version() {
  return std::to_string(MAJOR) + "." + std::to_string(MINOR) + "." +
         std::to_string(PATCH);
}

} // namespace xwm
