#ifndef GAMEGUY_MEMORY_MBC3_HPP
#define GAMEGUY_MEMORY_MBC3_HPP

namespace gameguy {

namespace memory {

class Mbc3
        : public gameguy::memory::Mbc
{
  public:
    Mbc3() = default;

    virtual auto readByte(gameguy::Word address) -> gameguy::Byte override;
    virtual auto writeByte(gameguy::Word, gameguy::Byte b) -> void override;
    virtual auto readWord(gameguy::Word address) -> gameguy::Word override;
    virtual auto writeWord(gameguy::Word address, gameguy::Word w) -> void override;
    
  private:
    std::vector<gameguy::Byte> m_rawData;
};

} // namespace memory

} // namespace memory

#endif // GAMEGUY_MEMORY_MBC3_HPP
