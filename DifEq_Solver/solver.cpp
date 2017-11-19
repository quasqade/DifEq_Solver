#include "solver.h"
#include "control.h"
#include <iostream>

Solver::Solver(Problem* p) //initalization list 
{
    this->problem = p;
    std::cout << "Created a Solver" << std::endl;
}

std::vector<point> Solver::solve(std::vector<double> IC, double dt, Control control)
{

    //входные параметры
    std::vector<double> a = problem->get_parameter('a');
    std::vector<double> C = problem->get_parameter('C');
    std::vector<double> m = problem->get_parameter('m');
    int order = problem->get_order();

    double(*control_function)(double); //указатель на функцию управляющего воздействия
    switch(control)
    {
        case NONE:
            control_function = &control_none;
            break;
        case SIN:
            control_function = &control_sin;
            break;
        case LN:
            control_function = &control_ln;
            break;
        case EXP:
            control_function = &control_exp;
            break;
        case HS:
            control_function = &control_heavyside;
            break;
        default:
            std::cout << "Cannot set control function!" << std::endl;
    }


    std::vector<double> x = IC;
    std::vector<std::vector<double>>A(order, std::vector<double>(order, 0));
    std::vector<double> B(order);

    //результат
    std::vector<point> result(1);

    for (int i = 0; i < order; i++)
    {
        for (int j = i + 1; j < order; j++)
        {
            A[i][j] = 1;
        }

        A[i][0] = -(a[i+1]/a[0] + C[order-i-1] * m[order-i-1]);
        B[i] = C[order-i-1] + A[i][0];
    }

    result.push_back(make_point(0, IC[0] + control_function(0)));

    return result;
}

point Solver::make_point(double time, double value)
{
    point result = {time, value};
    return result;
}