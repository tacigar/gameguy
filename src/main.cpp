#include <SDL2/SDL.h>

auto main(int argc, char **argv) -> int
{
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("The exciting white window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
