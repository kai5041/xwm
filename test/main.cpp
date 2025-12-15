#include <cstdlib>
#include <iostream>
#include <xwm/Dispatcher.hpp>

#include <xwm/Architecture.hpp>

using namespace xwm;

class MyArchitecture : public xwm::Architecture {
public:
  MyArchitecture(Dispatcher &dispatcher) : Architecture(dispatcher) {}
  u32 run() override {
    std::cout << "Welcome to my architecture\n";
    for (int i = 0; i < dispatcher->get_args().size(); i++) {
      std::cout << "Argument " << i << ": " << dispatcher->get_args()[i]
                << std::endl;
    }
    exit(EXIT_FAILURE);
    return 0;
  }
};

XWM_ENTRY(MyArchitecture)
