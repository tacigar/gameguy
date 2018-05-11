#include <SDL2/SDL.h>

#include "game.hpp"
#include "graphics.hpp"

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
    m_graphics = new Graphics(m_window, 50, 30);

    for (int i = 0; i < m_graphics->getTextureWidth(); ++i) {
        for (int j = 0; j < m_graphics->getTextureHeight(); ++j) {
            if (i == j)
                m_graphics->setPixel(i, j, 0);
        }
    }
}

auto Game::run() -> void
{
    SDL_Event event;
    int lastFrame = SDL_GetTicks();
    unsigned int wait = 16;

    bool leftMouseButtonDown = false;

    while (true) {
        while (SDL_PollEvent(&event)) {
            if ((event.type == SDL_QUIT)
                || (event.type == SDL_KEYUP
                    && event.key.keysym.sym == SDLK_ESCAPE)) {
                return;
            }
            switch (event.type)
            {
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT)
                        leftMouseButtonDown = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                        leftMouseButtonDown = true;
                case SDL_MOUSEMOTION:
                    if (leftMouseButtonDown) {
                        int mouseX = event.motion.x;
                        int mouseY = event.motion.y;
                        m_graphics->setPixel(mouseX, mouseY, 0);
                    }
                    break;
            }
        }
        update(SDL_GetTicks() - lastFrame);
        if (SDL_GetTicks() - lastFrame < wait) {
            draw();
            unsigned int tick = SDL_GetTicks();
            if (tick - lastFrame < wait) {
                SDL_Delay(wait - (tick - (lastFrame)));
            }
        }
        lastFrame += wait;
    }
}

auto Game::terminate() -> void
{
    delete m_graphics;
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

auto Game::update(int dt) -> void
{

}

auto Game::draw() -> void
{
    m_graphics->draw();
}

} // namespace gameguy
