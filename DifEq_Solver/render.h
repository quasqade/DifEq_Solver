#pragma once
#include "point.h"
#include <vector>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Render
{
    public:
        void gnuplot(const std::string& filename); //отрисовка графика с помощью gnuplot из файла (упадёт, если нет gnuplot)
        void to_file(const std::string& filename, std::vector<point> points); //вывод в файл
    private:
        void system_string(std::string const &s)
        {
            std::system(s.c_str());
        }
};