#ifndef GAMEGUY_CPU_REGISTER_HPP
#define GAMEGUY_CPU_REGISTER_HPP

#include "config/type.hpp"
#include <cstdint>


namespace gameguy {

namespace cpu {

class Register
{
  private:
    gameguy::Byte m_regA;
    gameguy::Byte m_regB;
    gameguy::Byte m_regC;
    gameguy::Byte m_regD;
    gameguy::Byte m_regE;
    gameguy::Byte m_regF;
    gameguy::Byte m_regH;
    gameguy::Byte m_regL;    

    gameguy::Word m_regPC;
    gameguy::Word m_regSP;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_REGISTER_HPP
