#include <iostream>

#include <xwm/Dispatcher.hpp>

int main(int argc, char **argv) {
  auto args = xwm::Vec<std::string>({argv, argv + argc});

  if (args.size() == 1) {
    std::cerr << "Please provide a command." << std::endl;
    return 1;
  }

  args.erase(args.begin());

  return xwm::Dispatcher(std::move(args)).dispatch();
}
