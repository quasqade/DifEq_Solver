#pragma once
#include "problem.h"
#include "point.h"

//перечисление видов управляющего воздействия
enum Control {NONE, SIN, LN, EXP, HS};

//класс решателя, принимает на вход указатель на объект задачи
class Solver
{
private:
    Problem* problem; //указатель на условия задачи
    point make_point(double time, double value); //функция создаёт и возвращает точку, чтобы не плодить временные переменные

public:
    Solver(Problem* p); //constructor

    std::vector<point> solve(std::vector<double> IC, double dt, Control control); //запуск решателя, принимает на вход
};