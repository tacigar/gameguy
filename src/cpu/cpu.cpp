#include "command.hpp"
#include "cpu.hpp"
#include "register.hpp"

namespace gameguy {

namespace cpu {

Cpu::Cpu()
        : m_register(std::make_shared<gameguy::cpu::Register>())
        , m_command(std::make_shared<gameguy::cpu::Command>(m_register))
{
}

} // namespace cpu

} // namespace gameguy
