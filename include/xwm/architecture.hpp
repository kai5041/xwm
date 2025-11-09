#pragma once

#include <xwm/defs.hpp>

namespace xwm {

class Architecture {
protected:
  Vec<std::string> args;

public:
  explicit Architecture(Vec<std::string> args) noexcept
      : args(std::move(args)) {}

  virtual ~Architecture() noexcept = default;

  virtual int run() noexcept = 0;
};

} // namespace xwm
