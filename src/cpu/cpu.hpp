#ifndef GAMEGUY_CPU_CPU_HPP
#define GAMEGUY_CPU_CPU_HPP

namespace gameguy {

namespace cpu {

class Cpu
{
  public:
    Cpu();

  private:
    gameguy::cpu::Register m_register;
    gameguy::cpu::Command m_command;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_CPU_HPP
