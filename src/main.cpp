#include <SDL2/SDL.h>
#include "game.hpp"
#include "config/type.hpp"
#include "rom/header.hpp"
#include "rom/rom.hpp"
#include <iostream>
#include <fstream>
#include <vector>

auto main(int argc, char **argv) -> int
{
    std::shared_ptr<gameguy::rom::Rom> rom = gameguy::rom::Rom::loadFile("rom/adjustris.gb");
    std::shared_ptr<gameguy::rom::Header> header = rom->header();

    std::cout << *header << std::endl;
    
    gameguy::Game game;
    game.initialize();
    game.run();
    game.terminate();
    return 0;
}
