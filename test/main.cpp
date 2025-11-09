#include <iostream>

#include <xwm/cli.hpp>
#include <xwm/architecture.hpp>

class MyArchitecture : public xwm::Architecture {
public:
  MyArchitecture(xwm::Vec<std::string> args) : Architecture(std::move(args)) {}
  ~MyArchitecture() override = default;

  int run() noexcept override {
    std::cout << "Hello World!" << std::endl;
    return 0;
  }
};

XWM_EXPORT xwm::Architecture *load_architecture(xwm::Vec<std::string> args) {
  return new MyArchitecture(std::move(args));
}
