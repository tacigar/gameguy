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

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    m_texture = SDL_CreateTexture(
        m_renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STATIC,
        640,
        480
    );
    m_pixels = new std::int32_t[640 * 480];
}

auto Game::run() -> void
{
    SDL_Event event;
    int lastFrame = SDL_GetTicks();
    int wait = 16;

    while (true) {
        while (SDL_PollEvent(&event)) {
            if ((event.type == SDL_QUIT)
                || (event.type == SDL_KEYUP
                    && event.key.keysym.sym == SDLK_ESCAPE)) {
                return;
            }
        }
        update(SDL_GetTicks() - lastFrame);
        if (SDL_GetTicks() - lastFrame < wait) {
            draw();
            int tick = SDL_GetTicks();
            if (tick - lastFrame < wait) {
                SDL_Delay(wait - (tick - (lastFrame)));
            }
        }
        lastFrame += wait;
    }
}

auto Game::terminate() -> void
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

auto Game::update(int dt) -> void
{

}

auto Game::draw() -> void
{
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

} // namespace gameguy
