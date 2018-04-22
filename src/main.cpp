#include <SDL2/SDL.h>
#include "game.hpp"

auto main(int argc, char **argv) -> int
{
    gameguy::Game game;
    game.initialize();
    game.run();
    game.terminate();
    return 0;
}
