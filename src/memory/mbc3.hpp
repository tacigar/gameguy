#ifndef GAMEGUY_MEMORY_MBC3_HPP
#define GAMEGUY_MEMORY_MBC3_HPP

#include "../config/config.hpp"
#include "mbc.hpp"

#include <vector>

namespace gameguy {

namespace memory {

class Mbc3
        : public gameguy::memory::Mbc
{
  public:
    Mbc3(const std::vector<gameguy::Byte>& rawData);

    virtual auto readByte(gameguy::Word address) -> gameguy::Byte override;
    virtual auto writeByte(gameguy::Word, gameguy::Byte b) -> void override;
    virtual auto readWord(gameguy::Word address) -> gameguy::Word override;
    virtual auto writeWord(gameguy::Word address, gameguy::Word w) -> void override;
    
  private:
    std::vector<gameguy::Byte> m_rawData;
    std::vector<gameguy::Byte> m_ram;
    std::vector<gameguy::Byte> m_rtc;
    int m_romBank;
    int m_ramBank;
    int m_rtcSelect;
    bool m_rtcEnable;
    bool m_ramEnable;
};

} // namespace memory

} // namespace memory

#endif // GAMEGUY_MEMORY_MBC3_HPP
