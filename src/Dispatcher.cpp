#include <iostream>
#include <xwm/Dispatcher.hpp>
#include <xwm/commands.hpp>
#include <xwm/version.hpp>

namespace xwm {

Dispatcher::Dispatcher(Vec<std::string> args) : args(std::move(args)) {

  commands["version"] = {
      "version",
      "Print version",
      [](Dispatcher & /*dispatcher*/) {
        std::cout << "xwm " << xwm::get_version() << "\n";
        std::cout << "Repository: https://github.com/kai5041/xwm" << std::endl;
        return 0;
      },
  };

  commands["help"] = {"help", "Print help", [](Dispatcher &dispatcher) {
                        std::cout << "Available commands:" << std::endl;
                        for (const auto &command : dispatcher.commands) {
                          std::cout << "  " << command.first << ": "
                                    << command.second.help << std::endl;
                        }
                        return 0;
                      }};

  commands["load"] = {
      "load",
      "Load architecture image with optional arguments",
      [](Dispatcher &dispatcher) { return xwm::load_architecture(dispatcher); },
  };
}

u32 Dispatcher::dispatch() {
  auto it = commands.find(args[0]);

  if (it == commands.end()) {
    std::cerr << "Command not found: " << args[0] << std::endl;
    return 1;
  }

  args.erase(args.begin());

  auto &cmd = it->second;

  auto result = cmd.func(*this);

  return result;
}

} // namespace xwm
