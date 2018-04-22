#ifndef GAMEGUY_GAME_HPP
#define GAMEGUY_GAME_HPP

#include <cstdint>

class SDL_Window;
class SDL_Surface;

namespace gameguy {

class Graphics;

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
    Graphics *m_graphics;
};

} // namespace gameguy

#endif // GAMEGUY_GAME_HPP
