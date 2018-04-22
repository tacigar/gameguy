#include <SDL2/SDL.h>
#include <cstdint>
#include "graphics.hpp"
#include <iostream>
namespace gameguy {

Graphics::Graphics(SDL_Window *window)
        : m_window(window)
{
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    m_texture = SDL_CreateTexture(
        m_renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STATIC,
        640,
        480
    );
    m_pixels = new std::int32_t[640 * 480];
    memset(m_pixels, 255, 640 * 480 * sizeof(std::int32_t));
}

Graphics::~Graphics()
{
    delete[] m_pixels;
}

auto Graphics::draw() -> void
{
    SDL_UpdateTexture(m_texture, NULL, m_pixels, 640 * sizeof(std::int32_t));    
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

auto Graphics::setPixel(int x, int y, std::int32_t v) -> void
{
    m_pixels[y * 640 + x] = v;
}

auto Graphics::getPixel(int x, int y) -> std::int32_t
{
    return m_pixels[y * 640 + x];
}

} // namespace gameguy
