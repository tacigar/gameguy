#ifndef GAMEGUY_CPU_COMMAND_HPP
#define GAMEGUY_CPU_COMMAND_HPP

#include "../config/config.hpp"
#include "register.hpp"

#include <functional>
#include <memory>
#include <unordered_map>

namespace gameguy {

namespace cpu {

class Command
{
  public:
    Command(std::shared_ptr<gameguy::cpu::Register> reg);

  private:
    auto setupLoadCommands() -> void;
    auto setupJumpCommands() -> void;

  private:
    std::shared_ptr<gameguy::cpu::Register> m_register;
    std::unordered_map<
        gameguy::Byte, std::function<void()>> m_commands;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_COMMAND_HPP
