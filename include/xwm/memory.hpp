#pragma once

#include <xwm/defs.hpp>

namespace xwm {

template <typename AddressWidth> class Memory {
private:
  Map<AddressWidth, u8> memory;

public:
  void write(AddressWidth address, u8 value) { memory[address] = value; }

  u8 read(AddressWidth address) const {
    auto it = memory.find(address);
    return (it != memory.end()) ? it->second : 0;
  }
};

} // namespace xwm
