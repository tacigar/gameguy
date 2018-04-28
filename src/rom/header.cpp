#include "header.hpp"

namespace gameguy {

namespace rom {

auto Header::parseData(std::vector<gameguy::Byte> rawData) -> Header
{
    
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

} // namespace rom

} // namespace gameguy
