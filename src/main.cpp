#include <iostream>

#include <xwm/Dispatcher.hpp>
#include <xwm/utils.hpp>

int main(int argc, char **argv) {
  auto args = xwm::Vec<std::string>({argv, argv + argc});

  xwm::log_if_error(args.size() == 1, "Provide a command");

  args.erase(args.begin());

  return xwm::Dispatcher(std::move(args)).dispatch();
}
