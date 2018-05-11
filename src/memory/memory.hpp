#ifndef GAMEGUY_MEMORY_MEMORY_HPP
#define GAMEGUY_MEMORY_MEMORY_HPP

#include "../config/config.hpp"

#include <vector>

namespace gameguy {

namespace memory {

class Memory
{
  public:
    Memory(const std::vector<gameguy::Byte>& rawData);

    auto readByte(gameguy::Word address) -> gameguy::Byte
    {
        return m_rawData[address];
    }

    auto writeByte(gameguy::Word address, gameguy::Byte b) -> void
    {
        m_rawData[address] = b;
    }
    
  private:
    std::vector<gameguy::Byte> m_rawData;
};

} // namespace memory

} // namespace gameguy

#endif // GAMEGUY_MEMORY_MEMORY_HPP
