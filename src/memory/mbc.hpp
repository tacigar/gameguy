#ifndef GAMEGUY_MEMORY_MBC_HPP
#define GAMEGUY_MEMORY_MBC_HPP

#include "../config/config.hpp"

namespace gameguy {

namespace memory {

class Mbc
{
  public:
    virtual ~Mbc() = default;

    virtual auto readByte(gameguy::Word address) -> gameguy::Byte = 0;
    virtual auto writeByte(gameguy::Word, gameguy::Byte b) -> void = 0;
    virtual auto readWord(gameguy::Word address) -> gameguy::Word = 0;
    virtual auto writeWord(gameguy::Word address, gameguy::Word w) -> void = 0;
};

} // namespace memory

} // namespace gameguy

#endif // GAMEGUY_MEMORY_MBC_HPP
