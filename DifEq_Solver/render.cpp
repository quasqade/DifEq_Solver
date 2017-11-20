#include "render.h"
#include <iostream>
#include <fstream>
void Render::to_file(const std::string& filename, std::vector<point> points, Control control_type)
{
    std::ofstream outfile(filename); //файл, в который будет осуществляться вывод
    std::ofstream overlay("overlay.csv"); //временный файл, в который выводятся значения управляющего воздействия
    for (int i = 0; i < points.size(); i++)
    {
        outfile << points.at(i).time << "," << points.at(i).value << std::endl;
        double value;
    //подсчёт значения управляющей функции в данной точке
    switch(control_type)
        {
        case NONE:
            value = 0;
            break;
        case SIN:
            value = control_sin(points.at(i).time);
            break;
        case LN:
            value = control_ln(points.at(i).time);
            break;
        case EXP:
            value = control_exp(points.at(i).time);
            break;
        case HS:
            value = control_heavyside(points.at(i).time);
            break;
        default:
            value = 0;
            std::cout << "Cannot set control function!" << std::endl;
        }
        overlay << points.at(i).time << "," << value << std::endl;
    }

    //закрываем потоки
    outfile.close();
    overlay.close();
}

void Render::gnuplot(const std::string& filename)
{
//создаём файл скрипта gnuplot
std::ofstream script("gnuplot.script");
script << "set datafile separator \",\"" << std::endl;
script << "set title 'Solution'" << std::endl;
script << "set ylabel 'y'" << std::endl;
script << "set xlabel 't'" << std::endl;
script << "set grid" << std::endl;
script << "set terminal x11" << std::endl;
script << "set output" << std::endl;
script << "plot '" << filename << "' with lines" << ", 'overlay.csv' with lines"<< std::endl;
script << "replot" << std::endl;
//закрываем поток файла
script.close();

//запускаем скрипт в gnuplot
system("gnuplot -p gnuplot.script");

//удаляем скрипт
std::remove("gnuplot.script");
//удаляем файл значений управляющей функции
std::remove("overlay.csv");

}