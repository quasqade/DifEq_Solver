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
    std::cout << "Created Problem" << std::endl;
}

void Problem::initializec()
{
    c.reserve(order+1);
    c.push_back(A.at(0));
    c.push_back((order-1) + sqrt((order - 1) + A.at(1)));
    if (order>1)
    c.push_back(sqrt(A.at(2)));
}

void Problem::printA()
{
    std::cout << "Printing A:" << std::endl;
    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A[i] << std::endl;
    }
}

void Problem::initializeC()
{
    C.reserve(order);
    for (int i = 0; i<order; i++)
    {
        C.push_back(c.at(i) / c.at(order));
    }
    std::cout << "fuck";
}

void Problem::initializem()
{
    m.reserve(order);
    for (int i = 0; i < order; i++)
    {
        m.push_back(1 - (a.at(order-i)/(C.at(i)*a.at(0))));
    }
    std::cout << "fuck";
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
        return c;
        break;
    case 'm':
        return m;
        break;
}
}

Problem::~Problem()
{
    //TODO
}