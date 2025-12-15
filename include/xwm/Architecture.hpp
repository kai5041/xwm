#pragma once

#include <xwm/Dispatcher.hpp>
#include <xwm/defs.hpp>

namespace xwm {

class Architecture {
protected:
  Dispatcher *dispatcher;

public:
  Architecture(Dispatcher &dispatcher) : dispatcher(&dispatcher) {}
  virtual ~Architecture() = default;
  virtual u32 run() = 0;
};

} // namespace xwm

#if defined(__linux__) || defined(__APPLE__)
#define XWM_ENTRY(CLASS)                                                       \
  extern "C" CLASS *entry(xwm::Dispatcher &dispatcher) {                       \
    return new CLASS(dispatcher);                                              \
  }
#elif defined(_WIN32)
#define XWM_ENTRY(CLASS)                                                       \
  extern "C" __declspec(dllexport) CLASS *entry(xwm::Dispatcher &dispatcher) { \
    return new CLASS(dispatcher);                                              \
  }
#else
#error "Unsupported platform for XWM_ENTRY"
#endif

