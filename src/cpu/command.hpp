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
    Command(gameguy::cpu::Register reg);

  private:
    auto setupLoadCommands() -> void;

  private:
    gameguy::cpu::Register m_register;
    std::unordered_map<
        gameguy::Byte, std::function<void(gameguy::cpu::Register &)>> m_commands;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_COMMAND_HPP
