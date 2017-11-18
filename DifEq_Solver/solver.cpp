#include "solver.h"
#include <iostream>

Solver::Solver(Problem problem)
{
    this->problem = problem;
    std::cout << "Solver created" << std::endl;
}