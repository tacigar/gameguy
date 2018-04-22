#ifndef GAMEGUY_GAME_HPP
#define GAMEGUY_GAME_HPP

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
    SDL_Surface *m_surface;    
};

} // namespace gameguy

#endif // GAMEGUY_GAME_HPP
