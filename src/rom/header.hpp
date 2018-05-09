#ifndef GAMEGUY_ROM_HEADER_HPP
#define GAMEGUY_ROM_HEADER_HPP

#include "../config/type.hpp"
#include "cartridge_type.hpp"

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

namespace gameguy {

namespace rom {

class Header
{
  public:
    Header() = default;
    ~Header() = default;

    static auto parseData(std::vector<gameguy::Byte> rawData) -> std::shared_ptr<Header>;

    auto romSize() const -> std::size_t
    {
        return m_romSize;
    }

    auto ramSize() const -> std::size_t
    {
        return m_ramSize;
    }

    auto title() const -> std::string
    {
        return m_title;
    }

    auto manufacturerCode() const -> std::string
    {
        return m_manufacturerCode;
    }

    auto cbgFlag() const -> bool
    {
        return m_cgbFlag;
    }

    auto sgbFlag() const -> bool
    {
        return m_sgbFlag;
    }

    auto cartridgeType() const -> gameguy::rom::CartridgeType
    {
        return m_cartridgeType;
    }

  private:
    static auto extractStringData(std::vector<gameguy::Byte> rawData, int from, int to) -> std::string;

  private:
    std::size_t m_romSize;
    std::size_t m_ramSize;
    std::string m_title;
    std::string m_manufacturerCode;
    bool m_cgbFlag;
    bool m_sgbFlag;
    gameguy::rom::CartridgeType m_cartridgeType;
};

} // namespace rom

} // namespace gameguy

#endif // GAMEGUY_ROM_HEADER_HPP
