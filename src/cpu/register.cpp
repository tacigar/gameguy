#include "cpu/register.hpp"

#include "config/type.hpp"

namespace gameguy {

namespace cpu {

Register::Register()
        : m_regA((gameguy::Byte)0x01)
        , m_regB((gameguy::Byte)0x00)
        , m_regC((gameguy::Byte)0x13)
        , m_regD((gameguy::Byte)0x00)
        , m_regE((gameguy::Byte)0xD8)
        , m_regF((gameguy::Byte)0xB0)
        , m_regH((gameguy::Byte)0x01)
        , m_regL((gameguy::Byte)0x4D)
        , m_regPC((gameguy::Word)0x0100)
        , m_regSP((gameguy::Word)0xFFFE)
{
}

} // namespace cpu

} // namespace gameguy
