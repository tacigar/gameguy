#include "game.hpp"
#include "config/config.hpp"
#include "cpu/cpu.hpp"
#include "rom/header.hpp"
#include "rom/rom.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

auto main(int argc, char **argv) -> int
{
    std::shared_ptr<gameguy::rom::Rom> rom = gameguy::rom::Rom::loadFile("rom/adjustris.gb");
    std::shared_ptr<gameguy::rom::Header> header = rom->header();

    DEBUG_STDOUT(*header << std::endl);

    gameguy::cpu::Cpu cpu(rom->rawData());
    cpu.executeInstruction();
    cpu.executeInstruction();
    cpu.executeInstruction();
    
    gameguy::Game game;
    game.initialize();
    game.run();
    game.terminate();
    return 0;
}
