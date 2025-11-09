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

  Architecture(const Architecture &) = delete;
  Architecture &operator=(const Architecture &) = delete;
  Architecture(Architecture &&) noexcept = default;
  Architecture &operator=(Architecture &&) noexcept = default;

  virtual void run() noexcept = 0;
};

} // namespace xwm
