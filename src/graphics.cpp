#include <SDL2/SDL.h>
#include <cstdint>
#include "graphics.hpp"

namespace gameguy {

Graphics::Graphics(SDL_Window *window, int textureWidth, int textureHeight)
        : m_window(window)
        , m_textureWidth(textureWidth)
        , m_textureHeight(textureHeight)
{
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    m_texture = SDL_CreateTexture(
        m_renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STATIC,
        m_textureWidth,
        m_textureHeight
    );
    m_pixels = new std::int32_t[m_textureWidth * m_textureHeight];
    memset(m_pixels, 255, m_textureWidth * m_textureHeight * sizeof(std::int32_t));
}

Graphics::~Graphics()
{
    delete[] m_pixels;
}

auto Graphics::draw() -> void
{
    SDL_UpdateTexture(m_texture, NULL, m_pixels, m_textureWidth * sizeof(std::int32_t));    
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

auto Graphics::setPixel(int x, int y, std::int32_t v) -> void
{
    m_pixels[y * m_textureWidth + x] = v;
}

auto Graphics::getPixel(int x, int y) -> std::int32_t
{
    return m_pixels[y * m_textureWidth + x];
}

} // namespace gameguy
