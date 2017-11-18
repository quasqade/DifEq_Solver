#pragma once
#include "problem.h"

enum Control {NONE, SIN, LN, EXP, IMPULSE};

class Solver
{
private:
    Problem* problem; //указатель на условия задачи

public:
    Solver(Problem* p); //constructor

    void solve(std::vector<double> IC, double dt, Control control); //запуск решателя
};