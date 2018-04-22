#include <SDL2/SDL.h>
#include "game.hpp"

auto main(int argc, char **argv) -> int
{
    gameguy::Game game;
    game.initialize();
    SDL_Delay(2000);
    game.terminate();
    return 0;
}
