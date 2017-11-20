#include "problem.h"
#include <iostream>
#include <cmath>


Problem::Problem(int order, std::vector<double> a, std::vector<double> A)
{
    this->order=order;
    this->a = a;
    this->A = A;
    initializec();
    initializeC();
    initializem();
}

void Problem::initializec()
{
    c.reserve(order+1);
    c.push_back(A.at(0));
    c.push_back((order-1) + sqrt((order - 1) + A.at(1)));
    if (order>1)
    c.push_back(sqrt(A.at(2)));
}

void Problem::initializeC()
{
    C.reserve(order);
    for (int i = 0; i<order; i++)
    {
        C.push_back(c.at(i) / c.at(order));
    }
}

void Problem::initializem()
{
    m.reserve(order);
    for (int i = 0; i < order; i++)
    {
        m.push_back(1 - (a.at(order-i)/(C.at(i)*a.at(0))));
    }
}

std::vector<double> Problem::get_parameter(char parameter)
{
switch (parameter)
{
    case 'a':
        return a;
        break;
    case 'A':
        return A;
        break;
    case 'c':
        return c;
        break;
    case 'C':
        return C;
        break;
    case 'm':
        return m;
        break;
}
}

int Problem::get_order()
{
return order;
}
