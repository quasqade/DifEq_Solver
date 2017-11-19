#include "render.h"
#include <iostream>
#include <fstream>
void Render::to_file(const std::string& filename, std::vector<point> points)
{
    std::ofstream outfile;
    outfile.open(filename);
    for (int i = 0; i < points.size(); i++)
    {
        outfile << points.at(i).time << "," << points.at(i).value << std::endl;
    }
    outfile.close();
}

void Render::gnuplot(const std::string& filename)
{
//create gnuplot script
std::ofstream script("gnuplot.script");
script << "set datafile separator \",\"" << std::endl;
script << "set title 'Solution'" << std::endl;
script << "set ylabel 'y'" << std::endl;
script << "set xlabel 't'" << std::endl;
script << "set grid" << std::endl;
script << "set terminal x11" << std::endl;
script << "set output" << std::endl;
script << "plot '" << filename << "'" << std::endl;
script.close();

//run gnuplot script
system("gnuplot -p gnuplot.script");

//delete gnuplot script
std::remove("gnuplot.script");
}