#ifndef GAMEGUY_CPU_REGISTER_HPP
#define GAMEGUY_CPU_REGISTER_HPP

#include <cstdint>

namespace gameguy {

namespace cpu {

class Register
{
  private:
    char m_regA;
    char m_regB;
    char m_regC;
    char m_regD;
    char m_regE;
    char m_regF;
    char m_regH;
    char m_regL;

    std::int_least16_t m_regPC;
    std::int_least16_t m_regSP;
};

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_REGISTER_HPP
