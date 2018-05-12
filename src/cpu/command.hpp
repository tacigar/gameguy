#ifndef GAMEGUY_CPU_COMMAND_HPP
#define GAMEGUY_CPU_COMMAND_HPP

#include "../config/config.hpp"
#include "../memory/memory.hpp"
#include "register.hpp"

#include <functional>
#include <memory>
#include <unordered_map>

namespace gameguy {

namespace memory {

class Memory;

} // namespace memory

namespace cpu {

class Command
{
  public:
    Command(const std::shared_ptr<gameguy::cpu::Register> reg,
            const std::shared_ptr<gameguy::memory::Memory> memory);
    auto execute(gameguy::Byte opcode) -> void;

  private:
    auto setupLoadCommands() -> void;
    auto setupJumpCommands() -> void;
    auto setupRotateShiftCommands() -> void;
    auto setupInterruptCommands() -> void;

  private:
    std::shared_ptr<gameguy::cpu::Register> m_register;
    std::shared_ptr<gameguy::memory::Memory> m_memory;
    std::unordered_map<
        gameguy::Byte, std::function<void()>> m_commands;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_COMMAND_HPP
