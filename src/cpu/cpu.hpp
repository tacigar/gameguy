#ifndef GAMEGUY_CPU_CPU_HPP
#define GAMEGUY_CPU_CPU_HPP

#include <memory>

namespace gameguy {

namespace cpu {

class Command;
class Register;

class Cpu
{
  public:
    Cpu();

  private:
    std::shared_ptr<gameguy::cpu::Command> m_command;
    std::shared_ptr<gameguy::cpu::Register> m_register;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_CPU_HPP
