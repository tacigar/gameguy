#include "../config/config.hpp"
#include "../memory/memory.hpp"
#include "command.hpp"

#include <memory>

namespace gameguy {

namespace cpu {

Command::Command(const std::shared_ptr<gameguy::cpu::Register> reg,
                 const std::shared_ptr<gameguy::memory::Memory> memory)
        : m_register(reg)
        , m_memory(memory)
        , m_commands()
{
    setupLoadCommands();
    setupJumpCommands();
    setupRotateShiftCommands();
    setupInterruptCommands();
    setupCallCommands();
}

auto Command::execute(gameguy::Byte opcode) -> void
{
    m_commands[opcode]();
}

auto Command::setupLoadCommands() -> void
{
#define GEN_LOAD_COMMAND_REG2REG(value, to, from) \
    m_commands[value] = [this]() -> void {\
        m_register->reg##to(m_register->reg##from()); \
    }

    GEN_LOAD_COMMAND_REG2REG(0x40, B, B);
    GEN_LOAD_COMMAND_REG2REG(0x41, B, C);
    GEN_LOAD_COMMAND_REG2REG(0x42, B, D);
    GEN_LOAD_COMMAND_REG2REG(0x43, B, E);
    GEN_LOAD_COMMAND_REG2REG(0x44, B, H);
    GEN_LOAD_COMMAND_REG2REG(0x45, B, L);
    // TODO: 0x46
    GEN_LOAD_COMMAND_REG2REG(0x46, B, A);

    GEN_LOAD_COMMAND_REG2REG(0x48, C, B);
    GEN_LOAD_COMMAND_REG2REG(0x49, C, C);
    GEN_LOAD_COMMAND_REG2REG(0x4A, C, D);
    GEN_LOAD_COMMAND_REG2REG(0x4B, C, E);
    GEN_LOAD_COMMAND_REG2REG(0x4C, C, H);
    GEN_LOAD_COMMAND_REG2REG(0x4D, C, L);
    // TODO: 0x4E
    GEN_LOAD_COMMAND_REG2REG(0x4F, C, A);

    GEN_LOAD_COMMAND_REG2REG(0x50, D, B);
    GEN_LOAD_COMMAND_REG2REG(0x51, D, C);
    GEN_LOAD_COMMAND_REG2REG(0x52, D, D);
    GEN_LOAD_COMMAND_REG2REG(0x53, D, E);
    GEN_LOAD_COMMAND_REG2REG(0x54, D, H);
    GEN_LOAD_COMMAND_REG2REG(0x55, D, L);
    // TODO: 0x46
    GEN_LOAD_COMMAND_REG2REG(0x56, D, A);

    GEN_LOAD_COMMAND_REG2REG(0x58, E, B);
    GEN_LOAD_COMMAND_REG2REG(0x59, E, C);
    GEN_LOAD_COMMAND_REG2REG(0x5A, E, D);
    GEN_LOAD_COMMAND_REG2REG(0x5B, E, E);
    GEN_LOAD_COMMAND_REG2REG(0x5C, E, H);
    GEN_LOAD_COMMAND_REG2REG(0x5D, E, L);
    // TODO: 0x4E
    GEN_LOAD_COMMAND_REG2REG(0x5F, E, A);

    GEN_LOAD_COMMAND_REG2REG(0x60, H, B);
    GEN_LOAD_COMMAND_REG2REG(0x61, H, C);
    GEN_LOAD_COMMAND_REG2REG(0x62, H, D);
    GEN_LOAD_COMMAND_REG2REG(0x63, H, E);
    GEN_LOAD_COMMAND_REG2REG(0x64, H, H);
    GEN_LOAD_COMMAND_REG2REG(0x65, H, L);
    // TODO: 0x46
    GEN_LOAD_COMMAND_REG2REG(0x66, H, A);

    GEN_LOAD_COMMAND_REG2REG(0x68, L, B);
    GEN_LOAD_COMMAND_REG2REG(0x69, L, C);
    GEN_LOAD_COMMAND_REG2REG(0x6A, L, D);
    GEN_LOAD_COMMAND_REG2REG(0x6B, L, E);
    GEN_LOAD_COMMAND_REG2REG(0x6C, L, H);
    GEN_LOAD_COMMAND_REG2REG(0x6D, L, L);
    // TODO: 0x4E
    GEN_LOAD_COMMAND_REG2REG(0x6F, L, A);
#undef GEN_LOAD_COMMAND_REG2REG
}

auto Command::setupJumpCommands() -> void
{
    m_commands[0xC3] = [this]() -> void {
        gameguy::Word address = m_memory->readWord(m_register->regPC());
        m_register->regPC(address);
    };
}

auto Command::setupRotateShiftCommands() -> void
{
    m_commands[0x00] = [this]() -> void {

    };
}

auto Command::setupInterruptCommands() -> void
{
    m_commands[0xF3] = [this]() -> void {

    };
}

auto Command::setupCallCommands() -> void
{
    m_commands[0xCD] = [this]() -> void {
        m_register->regSP(m_register->regSP() - 2);
        m_memory->writeWord(
            m_register->regSP(),
            m_register->regPC() + 3);
        gameguy::Word address = m_memory->readWord(m_register->regPC());
        m_register->regPC(address);
    };
}

} // namespace cpu

} // namespace gameguy
