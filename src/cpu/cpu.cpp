#include "../config/config.hpp"
#include "../memory/mbc.hpp"
#include "../memory/mbc3.hpp"
#include "../memory/memory.hpp"
#include "command.hpp"
#include "cpu.hpp"
#include "register.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

namespace gameguy {

namespace cpu {

Cpu::Cpu(const std::vector<gameguy::Byte>& rawData)
        : m_rawData(rawData)
        , m_register(std::make_shared<gameguy::cpu::Register>())
        , m_memory(std::make_shared<gameguy::memory::Memory>(rawData))
        , m_command(std::make_shared<gameguy::cpu::Command>(m_register, m_memory))
        , m_mbc(std::make_shared<gameguy::memory::Mbc3>(rawData))
{
}

auto Cpu::executeInstruction() -> void
{
    gameguy::Byte opcode = m_memory->readByte(m_register->regPC());

    DEBUG_STDOUT(
        "OPCODE: " << std::setw(2) << std::hex << static_cast<int>(opcode) <<
        '(' << std::setw(3) << std::dec << static_cast<int>(opcode) << "), " <<
        "ADDRESS: " << std::setw(2) << std::hex << static_cast<int>(m_register->regPC()) <<
        '(' << std::setw(3) << std::dec << static_cast<int>(m_register->regPC()) << ')' << std::endl);
    m_register->regPC((m_register->regPC() + 1) & 0xFFFF);
    m_command->execute(opcode);
}

} // namespace cpu

} // namespace gameguy
