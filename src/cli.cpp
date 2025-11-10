#include <xwm/cli.hpp>
#include <xwm/commands.hpp>
#include <xwm/utils.hpp>
#include <xwm/version.hpp>

#include <algorithm>
#include <iostream>

namespace xwm {

Command::Command(std::string_view a, std::string_view desc,
                 std::function<int(Cli &)> h)
    : args(a), description(desc), handler(std::move(h)) {}

Cli::Cli() {
  register_command({"help", "Prints this help", [this](Cli &) {
                      print_help();
                      return 0;
                    }});

  register_command({"load", "Load architecture image with optional arguments",
                    [this](Cli &cli) { return load_architecture(cli); }});

  register_command({"version", "Prints xwm version", [this](Cli &) {
                      std::cout << "xwm version " << xwm::get_version()
                                << std::endl;
                      return 0;
                    }});
}

void Cli::register_command(Command cmd) { commands.push_back(std::move(cmd)); }

int Cli::run(const Vec<std::string> &args) {
  if (args.empty()) {
    log_message(LogLevel::_ERROR, "No command provided.");
    return 1;
  }

  this->args = args;

  const std::string_view cmd_name = args[0];
  auto it = std::find_if(
      commands.begin(), commands.end(),
      [&cmd_name](const Command &c) { return c.args == cmd_name; });

  if (it == commands.end()) {
    log_message(LogLevel::_ERROR, "Unknown command '", cmd_name, "'");
    return 1;
  }

  this->args.erase(this->args.begin());
  return it->handler(*this);
}

void Cli::print_help() const {
  std::cout << "Available commands:\n";
  for (const auto &cmd : commands) {
    std::cout << "  " << cmd.args << ": " << cmd.description << std::endl;
  }
}

} // namespace xwm
