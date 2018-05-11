#ifndef GAMEGUY_CPU_CPU_HPP
#define GAMEGUY_CPU_CPU_HPP

#include <memory>
#include <vector>

namespace gameguy {

namespace memory {

class Mbc;
class Memory;

}

namespace cpu {

class Command;
class Register;

class Cpu
{
  public:
    Cpu(const std::vector<gameguy::Byte>& rawData);

    auto executeInstruction() -> void;

  private:
    std::vector<gameguy::Byte> m_rawData;
    std::shared_ptr<gameguy::cpu::Register> m_register;
    std::shared_ptr<gameguy::memory::Memory> m_memory;
    std::shared_ptr<gameguy::cpu::Command> m_command;
    std::shared_ptr<gameguy::memory::Mbc> m_mbc;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_CPU_HPP
