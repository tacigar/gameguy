#include "../config/config.hpp"
#include "cartridge_type.hpp"
#include "header.hpp"

#include <cmath>
#include <cstddef>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace gameguy {

namespace rom {

auto Header::parseData(std::vector<gameguy::Byte> rawData) -> std::shared_ptr<Header>
{
    std::shared_ptr<Header> header = std::make_shared<Header>();
    header->m_title = Header::extractStringData(rawData, 0x134, 0x143);
    header->m_manufacturerCode = Header::extractStringData(rawData, 0x13F, 0x142);

    int romSize = rawData[0x148];
    switch (romSize) {
        case 0x00: case 0x01: case 0x02: case 0x03: case 0x04:
        case 0x05: case 0x06: case 0x07: case 0x08: {
            header->m_romSize = (32 * 1024) << romSize;
            break;
        }
        case 0x52: {
            header->m_romSize = (int)std::ceil(1.1 * 1024 * 1024);
            break;
        }
        case 0x53: {
            header->m_romSize = (int)std::ceil(1.2 * 1024 * 1024);
            break;
        }
        case 0x54: {
            header->m_romSize = (int)std::ceil(1.5 * 1024 * 1024);
            break;
        }
    }

    int ramSize = rawData[0x149];
    switch (ramSize) {
        case 0x00: header->m_ramSize =           0; break;
        case 0x01: header->m_ramSize =    2 * 1024; break;
        case 0x02: header->m_ramSize =    8 * 1024; break;
        case 0x03: header->m_ramSize =   32 * 1024; break;
        case 0x04: header->m_ramSize =  128 * 1024; break;
        case 0x05: header->m_ramSize =   64 * 1024; break;
    }

    header->m_cartridgeType = static_cast<CartridgeType>(rawData[0x147]);
    return header;
}

auto Header::extractStringData(std::vector<gameguy::Byte> rawData, int from, int to) -> std::string
{
    int lastIndex = from;
    for (int i = from; i <= to; ++i) {
        if (rawData[i] == 0) {
            lastIndex = i;
            break;
        }
    }
    return std::string(rawData.begin() + from, rawData.begin() + to);
}

auto operator<<(std::ostream& os, const Header& header) -> std::ostream&
{
    os << " ROM SIZE: " << header.romSize() << std::endl;
    os << " RAM SIZE: " << header.ramSize() << std::endl;
    os << " TITLE: " << header.title() << std::endl;
    os << " MANUFACTURER CODE: " << header.manufacturerCode() << std::endl;
    os << " CARTRIDGE TYPE: " << cartridgeTypeToString(header.cartridgeType());
    return os;
}

} // namespace rom

} // namespace gameguy
