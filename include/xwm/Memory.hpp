#pragma once

#include <ostream>
#include <xwm/defs.hpp>

namespace xwm {

class Memory {
protected:
  Map<u64, u8> memory;

public:
  u8 *at(u64 address) {
    auto it = memory.find(address);
    if (it != memory.end()) {
      return &it->second;
    }
    return nullptr;
  }

  u8 *operator[](u64 address) { return at(address); }

  auto &get_memory() const { return this->memory; }

  void write(u64 address, u8 value) { memory[address] = value; }
  u8 read(u64 address) { return memory.at(address); }
};

} // namespace xwm

inline std::ostream &operator<<(std::ostream &os, const xwm::Memory &memory) {
  for (const auto &entry : memory.get_memory()) {
    os << std::uppercase << std::hex << entry.first << ": " << std::uppercase << std::hex << entry.second
       << std::endl;
  }

  return os;
}