#include "../config/config.hpp"
#include "../rom/cartridge_type.hpp"
#include "mbc_selector.hpp"
#include "mbc1.hpp"
#include "mbc2.hpp"
#include "mbc3.hpp"

#include <memory>
#include <vector>

namespace gameguy {

namespace memory {

auto MbcSelector::select(gameguy::rom::CartridgeType cartridgeType,
                         const std::vector<gameguy::Byte>& rawData)
        -> std::shared_ptr<Mbc>
{
    using namespace gameguy::rom;
    switch (cartridgeType) {
        case CartridgeType::MBC1:
        case CartridgeType::MBC1_RAM:
        case CartridgeType::MBC1_RAM_BATTERY:
            return std::make_shared<gameguy::memory::Mbc1>(rawData);
        case CartridgeType::MBC2:
        case CartridgeType::MBC2_BATTERY:
            return std::make_shared<gameguy::memory::Mbc2>(rawData);
        case CartridgeType::MBC3_TIMER_BATTERY:
        case CartridgeType::MBC3_TIMER_RAM_BATTERY:
        case CartridgeType::MBC3:
        case CartridgeType::MBC3_RAM:
        case CartridgeType::MBC3_RAM_BATTERY:
            return std::make_shared<gameguy::memory::Mbc3>(rawData);
        default:
            return nullptr;
    }
}

} // namespace memory

} // namespace gameguy
