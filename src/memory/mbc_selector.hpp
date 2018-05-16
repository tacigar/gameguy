#ifndef GAMEGUY_MEMORY_MBC_SELECTOR_HPP
#define GAMEGUY_MEMORY_MBC_SELECTOR_HPP

#include "../config/config.hpp"
#include "../rom/cartridge_type.hpp"
#include "mbc.hpp"

#include <memory>
#include <vector>

namespace gameguy {

namespace memory {

class MbcSelector
{
  public:
    auto select(gameguy::rom::CartridgeType cartridgeType,
                const std::vector<Byte>& rawData)
            -> std::shared_ptr<Mbc>;
};

} // namespace memory

} // namespace gameguy

#endif // GAMEGUY_MEMORY_MBC_SELECTOR_HPP
