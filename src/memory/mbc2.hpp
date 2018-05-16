#ifndef GAMEGUY_MEMORY_MBC2_HPP
#define GAMEGUY_MEMORY_MBC2_HPP

#include "../config/config.hpp"
#include "mbc.hpp"

#include <vector>

namespace gameguy {

namespace memory {

class Mbc2
        : public gameguy::memory::Mbc
{
  public:
    Mbc2(const std::vector<gameguy::Byte>& rawData);

    virtual auto readByte(gameguy::Word address) -> gameguy::Byte override;
    virtual auto writeByte(gameguy::Word, gameguy::Byte b) -> void override;
    virtual auto readWord(gameguy::Word address) -> gameguy::Word override;
    virtual auto writeWord(gameguy::Word address, gameguy::Word w) -> void override;
};

} // namespace memory

} // namespace gameguy

#endif // GAMEGUY_MEMORY_MBC2_HPP
