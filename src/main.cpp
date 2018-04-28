#include <SDL2/SDL.h>
#include "game.hpp"
#include "config/type.hpp"
#include "rom/header.hpp"
#include <iostream>
#include <fstream>
#include <vector>

auto main(int argc, char **argv) -> int
{
    std::ifstream fin("rom/adjustris.gb", std::ios::in | std::ios::binary);
    if (!fin) {
        std::cout << "cannot open file" << std::endl;
        return 1;
    }
    std::vector<gameguy::Byte> data;    
    while (!fin.eof()) {
        char buf;
        fin.read((char *) &buf, sizeof(char));
        data.push_back(buf);
    }
    gameguy::rom::Header header = gameguy::rom::Header::parseData(data);
    std::cout << header.romSize() << std::endl;
    std::cout << header.ramSize() << std::endl;
    std::cout << header.title() << std::endl;
    std::cout << header.manufacturerCode() << std::endl;

    gameguy::Game game;
    game.initialize();
    game.run();
    game.terminate();
    return 0;
}
