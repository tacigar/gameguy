#ifndef GAMEGUY_CPU_COMMAND_HPP
#define GAMEGUY_CPU_COMMAND_HPP

#include "../config/type.hpp"
#include "register.hpp"

#include <functional>
#include <unordered_map>

namespace gameguy {

namespace cpu {

class Command
{
  public:
    Command(gamegoy::cpu::Register register);

  private:
    auto setupLoadCommands() -> void;

  private:
    gameguy::cpu::register m_register;
    std::unordered_map<gameguy::Byte, std::function<void()>> m_commands;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_COMMAND_HPP
