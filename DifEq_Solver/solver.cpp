#include "solver.h"
#include "control.h"
#include <iostream>

Solver::Solver(Problem* p) //initalization list 
{
    this->problem = p;
    std::cout << "Created a Solver" << std::endl;
}

void Solver::solve(std::vector<double> IC, double dt, Control control)
{

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
            //TODO
    }


    std::vector<double> x = IC;
    std::vector<std::vector<double>>A(order, std::vector<double>(order, 0));
    std::vector<double> B(order);

    for (int i = 0; i < order; i++)
    {
        for (int j = i + 1; j < order; j++)
        {
            A.at(i).at(j) = 1;
        }

        A.at(i).at(0) = -(a.at(i+1)/a.at(0) + C.at(order-i-1) * m.at(order-i-1));
        B.at(i) = C.at(order-i-1) + A.at(i).at(0);
        
    }

}