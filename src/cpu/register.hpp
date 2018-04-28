#ifndef GAMEGUY_CPU_REGISTER_HPP
#define GAMEGUY_CPU_REGISTER_HPP

#include "../config/type.hpp"
#include <cstdint>

namespace gameguy {

namespace cpu {

#define GEN_REGISTER_ACCESSOR(type, name) \
    auto reg##name() const -> type { return m_reg##name; } \
    auto reg##name(type value) -> void { m_reg##name = value; }

class Register
{
  public:
    Register();

    GEN_REGISTER_ACCESSOR(gameguy::Byte, A);
    GEN_REGISTER_ACCESSOR(gameguy::Byte, B);
    GEN_REGISTER_ACCESSOR(gameguy::Byte, C);
    GEN_REGISTER_ACCESSOR(gameguy::Byte, D);
    GEN_REGISTER_ACCESSOR(gameguy::Byte, E);
    GEN_REGISTER_ACCESSOR(gameguy::Byte, F);
    GEN_REGISTER_ACCESSOR(gameguy::Byte, H);
    GEN_REGISTER_ACCESSOR(gameguy::Byte, L);
    GEN_REGISTER_ACCESSOR(gameguy::Word, PC);
    GEN_REGISTER_ACCESSOR(gameguy::Word, SP);    

    auto regAF() const -> gameguy::Word;
    auto regAF(gameguy::Word value) -> void;

    auto regBC() const -> gameguy::Word;
    auto regBC(gameguy::Word value) -> void;

    auto regDE() const -> gameguy::Word;
    auto regDE(gameguy::Word value) -> void;

    auto regHL() const -> gameguy::Word;
    auto regHL(gameguy::Word value) -> void;
    
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

#undef GEN_REGISTER_ACCESSOR

} // namespace cpu

} // namespace gameguy

#endif // GAMEGUY_CPU_REGISTER_HPP
