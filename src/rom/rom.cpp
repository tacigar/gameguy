#include "../config/config.hpp"
#include "header.hpp"
#include "rom.hpp"

#include <fstream>
#include <istream>
#include <memory>
#include <string>
#include <vector>

namespace gameguy {

namespace rom {

Rom::Rom(const std::shared_ptr<gameguy::rom::Header> header)
        : m_header(header)
{
}

auto Rom::load(std::istream& is) -> std::shared_ptr<Rom>
{
    std::vector<gameguy::Byte> rawData;
    while (!is.eof()) {
        char c;
        is.read((char *) &c, sizeof(char));
        rawData.push_back(c);
    }
    return std::make_shared<Rom>(
        gameguy::rom::Header::parseData(rawData));
}

auto Rom::loadFile(const std::string& fileName) -> std::shared_ptr<Rom>
{
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    if (!ifs) {

    }
    return Rom::load(ifs);
}

} // namespace rom

} // namespace gameguy
