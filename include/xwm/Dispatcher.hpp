#pragma once

#include <functional>

#include <xwm/defs.hpp>

namespace xwm {

class Dispatcher;

struct Command {
  std::string name;
  std::string help;
  std::function<u32(Dispatcher &)> func;
};

class Dispatcher {
private:
  Vec<std::string> args;
  Map<std::string, Command> commands;

public:
  Dispatcher(Vec<std::string> args);
  inline auto &get_args() { return args; }

  u32 dispatch();
};

} // namespace xwm
