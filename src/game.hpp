#ifndef GAMEGUY_GAME_HPP
#define GAMEGUY_GAME_HPP

#include <cstdint>

class SDL_Window;
class SDL_Surface;

namespace gameguy {

class Game
{
  public:
    auto initialize() -> void;
    auto run() -> void;
    auto terminate() -> void;

  private:
    auto update(int dt) -> void;
    auto draw() -> void;

  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    std::int32_t *m_pixels;
};

} // namespace gameguy

#endif // GAMEGUY_GAME_HPP
