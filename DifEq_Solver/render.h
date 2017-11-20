#pragma once
#include "point.h"
#include <vector>
#include <string>
#include "control.h"

class Render
{
    public:
        void gnuplot(const std::string& filename); //отрисовка графика с помощью gnuplot из файла (упадёт, если нет gnuplot)
        void to_file(const std::string& filename, std::vector<point> points, Control control_type); //вывод в файл
};