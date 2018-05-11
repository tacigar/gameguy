#include "../config/config.hpp"
#include "memory.hpp"

#include <vector>

namespace gameguy {

namespace memory {

Memory::Memory(const std::vector<gameguy::Byte>& rawData)
        : m_rawData(rawData)
{

}

auto Memory::readWord(gameguy::Word address) -> gameguy::Word
{
    gameguy::Word lower = readByte(address);
    gameguy::Word upper = readByte(address + 1) << 8;
    return upper + lower;
}

auto Memory::writeWord(gameguy::Word address, gameguy::Word w) -> void
{
    gameguy::Word lower = readByte(address);
    gameguy::Word upper = readByte(address + 1) << 8;
    m_rawData[upper + lower] = w;
}

} // namespace memory

} // namespace gameguy
