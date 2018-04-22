#include <SDL2/SDL.h>

#include "game.hpp"

namespace gameguy {

auto Game::initialize() -> void
{
    SDL_Init(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow(
        "GameGuy",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );
    m_surface = SDL_GetWindowSurface(m_window);
    SDL_UpdateWindowSurface(m_window);
}

auto Game::run() -> void
{

}

auto Game::terminate() -> void
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

} // namespace gameguy
