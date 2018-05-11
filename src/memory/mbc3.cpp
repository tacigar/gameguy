#include "mbc3.hpp"

namespace gameguy {

namespace memory {

Mbc3::Mbc3(const std::vector<gameguy::Byte>& rawData)
        : m_rawData(rawData)
        , m_ram()
        , m_rtc()
        , m_romBank(0)
        , m_ramBank(0)
        , m_rtcSelect(0x08)
        , m_rtcEnable(false)
        , m_ramEnable(false)
{

}

auto Mbc3::readByte(gameguy::Word address) -> gameguy::Byte
{
    if (address <= 0x3FFF) {
        return m_rawData[address];
    } else if (address >= 0x4000 && address <= 0x7FFF) {
        return m_rawData[(m_romBank * 16 * 1024) + (address - 0x4000)];
    } else if (address >= 0xA000 && address <= 0xBFFF && m_ramEnable) {
        if (m_rtcEnable) {
            return m_rtc[m_rtcSelect];
        } else {
            return m_ram[(address - 0xA000) + (m_ramBank * 8 * 1024)];
        }
    }
    return 0x00;
}
        
auto Mbc3::writeByte(gameguy::Word, gameguy::Byte b) -> void
{

}

auto Mbc3::readWord(gameguy::Word address) -> gameguy::Word
{

}

auto Mbc3::writeWord(gameguy::Word address, gameguy::Word w) -> void
{

}

} // namespace memory

} // namespace gameguy
