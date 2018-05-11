#include "cartridge_type.hpp"

#include <string>
#include <unordered_map>

namespace {

#define GEN_MAP_ENTRIES_COMMON \
    GEN_MAP_ENTRY(ROM_ONLY),\
    GEN_MAP_ENTRY(MBC1),\
    GEN_MAP_ENTRY(MBC1_RAM),\
    GEN_MAP_ENTRY(MBC1_RAM_BATTERY),\
    GEN_MAP_ENTRY(MBC2),\
    GEN_MAP_ENTRY(MBC2_BATTERY),\
    GEN_MAP_ENTRY(ROM_RAM),\
    GEN_MAP_ENTRY(ROM_RAM_BATTERY),\
    GEN_MAP_ENTRY(MMM01),\
    GEN_MAP_ENTRY(MMM01_RAM),\
    GEN_MAP_ENTRY(MMM01_RAM_BATTERY),\
    GEN_MAP_ENTRY(MBC3_TIMER_BATTERY),\
    GEN_MAP_ENTRY(MBC3_TIMER_RAM_BATTERY),\
    GEN_MAP_ENTRY(MBC3),\
    GEN_MAP_ENTRY(MBC3_RAM),\
    GEN_MAP_ENTRY(MBC3_RAM_BATTERY),\
    GEN_MAP_ENTRY(MBC5),\
    GEN_MAP_ENTRY(MBC5_RAM),\
    GEN_MAP_ENTRY(MBC5_RAM_BATTERY),\
    GEN_MAP_ENTRY(MBC5_RUMBLE),\
    GEN_MAP_ENTRY(MBC5_RUMBLE_RAM),\
    GEN_MAP_ENTRY(MBC5_RUMBLE_RAM_BATTERY),\
    GEN_MAP_ENTRY(MBC6),\
    GEN_MAP_ENTRY(MBC7_SENSOR_RUMBLE_RAM_BATTERY),\
    GEN_MAP_ENTRY(POCKET_CAMERA),\
    GEN_MAP_ENTRY(BANDAI_TAMA5),\
    GEN_MAP_ENTRY(HuC3),\
    GEN_MAP_ENTRY(HuC1_RAM_BATTERY),

std::unordered_map<std::string, gameguy::rom::CartridgeType> stringCartridgeMap = {
#define GEN_MAP_ENTRY(x) {#x, gameguy::rom::CartridgeType::x}
    GEN_MAP_ENTRIES_COMMON
#undef GEN_MAP_ENTRY    
};

std::unordered_map<gameguy::rom::CartridgeType, std::string> cartridgeStringMap = {
#define GEN_MAP_ENTRY(x) {gameguy::rom::CartridgeType::x, #x}
    GEN_MAP_ENTRIES_COMMON
#undef GEN_MAP_ENTRY
};

} // namespace

namespace gameguy {

namespace rom {

auto stringToCartridgeType(const std::string& s) -> CartridgeType
{
    return stringCartridgeMap.at(s);
}

auto cartridgeTypeToString(CartridgeType c) -> std::string
{
    return cartridgeStringMap.at(c);
}

} // namespace rom

} // namespace gameguy
