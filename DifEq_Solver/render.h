#pragma once
#include "point.h"
#include <vector>
#include <SDL2/SDL.h> //библиотека графики

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Render
{
    public:
        static void plot(std::vector<point> points);
};