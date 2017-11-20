#pragma once
#include "problem.h"
#include "point.h"
#include "control.h"

//класс решателя, конструктор принимает на вход указатель на объект задачи
class Solver
{
private:
    Problem* problem; //указатель на условия задачи
    point make_point(double time, double value); //функция создаёт и возвращает точку, чтобы не плодить временные переменные
public:
    Solver(Problem* p); //конструктор
    ~Solver(); //деструктор

    std::vector<point> solve(std::vector<double> IC, double dt, Control control); //запуск решателя, принимает на вход вектор начальных условий, шаг интегрирования и тип управляющего воздействия
};