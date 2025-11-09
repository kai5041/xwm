#include <xwm/cli.hpp>
#include <xwm/utils.hpp>

int main(int argc, char **argv) {
  if (argc == 1) {
    xwm::log_message(xwm::LogLevel::ERROR,
                     "No command provided. Please specify one.");
    return 1;
  }

  return xwm::Cli().run((xwm::Vec<std::string>(argv + 1, argv + argc)));
}
