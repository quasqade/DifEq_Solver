#include "solver.h"
#include <iostream>

Solver::Solver(Problem* p)
{
    this->problem = p;
}

Solver::~Solver()
{
    
}

std::vector<point> Solver::solve(std::vector<double> IC, double dt, Control control)
{

    //переписываем параметры в локальные переменные, чтобы упростить обращение
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
            control_function = &control_none;
            std::cout << "Cannot set control function!" << std::endl;
    }

    //временные переменные для расчетов
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


    //Метод Рунге-Кутты 4 порядка
    const int AMOUNT_OF_POINTS = 999;
    double t = dt;
    for (int count = 1; count < AMOUNT_OF_POINTS; count++, t+=dt)
    {
        double k1, k2, k3, k4;
        std::vector<double> temp_x(order);
        for (int i = 0; i < order; i++)
        {
            k1 = B[i]*control_function(t);
            k2 = k1;
            k3 = k1;
            k4 = k1;

            for (int j = 0; j < order; j++)
            {
                k1 += A[i][j] * x[j];
                k2 += A[i][j] * (x[j] + (dt/2)*k1);
                k3 += A[i][j] * (x[j] + (dt/2)*k2);
                k4 += A[i][j] * (x[j] + dt*k3);
            }

            temp_x[i] = x[i] + (dt/6) * (k1 + 2*k2 + 2*k3 + k4);
        }
        x = temp_x;
        result.push_back(make_point(t, x[0] + control_function(t)));
    }

    return result;
}

point Solver::make_point(double time, double value)
{
    point result = {time, value};
    return result;
}
