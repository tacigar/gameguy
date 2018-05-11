#include "../config/config.hpp"
#include "memory.hpp"

#include <vector>

namespace gameguy {

namespace memory {

Memory::Memory(const std::vector<gameguy::Byte>& rawData)
        : m_rawData(rawData)
{

}

} // namespace memory

} // namespace gameguy
