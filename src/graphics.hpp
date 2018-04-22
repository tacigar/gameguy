#ifndef GAMEGUY_GRAPHICS_HPP
#define GAMEGUY_GRAPHICS_HPP

#include <cstdint>

class SDL_Window;
class SDL_Renderer;
class SDL_Texture;

namespace gameguy {

class Graphics
{
  public:
    Graphics(SDL_Window *window, int width, int height);
    ~Graphics();
    
    auto draw() -> void;
    auto setPixel(int x, int y, std::int32_t v) -> void;
    auto getPixel(int x, int y) -> std::int32_t;
    auto getTextureWidth() -> int;
    auto getTextureHeight() -> int;
    
  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    std::int32_t *m_pixels;
    int m_textureWidth;
    int m_textureHeight;
};

} // namespace gameguy

#endif // GAMEGUY_GRAPHICS_HPP
