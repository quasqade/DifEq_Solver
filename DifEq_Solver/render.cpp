#include "render.h"
#include <iostream>

void Render::plot(std::vector<point> points)
{
    //окно
    SDL_Window* window = NULL;

    //поверхность
    SDL_Surface* windowSurface = NULL;

    //инициализация SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Could not initalize SDL! Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        window = SDL_CreateWindow("График решения", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Could not create SDL window! Error: " << SDL_GetError() << std::endl;
        }
    }
}