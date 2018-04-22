#ifndef GAMEGUY_GAME_HPP
#define GAMEGUY_GAME_HPP

class SDL_Window;
class SDL_Surface;

namespace gameguy {

class Game
{
  private:
    SDL_Window *m_window;
    SDL_Surface *m_surface;
    
  public:
    auto initialize() -> void;
    auto terminate() -> void;
};

} // namespace gameguy

#endif // GAMEGUY_GAME_HPP
