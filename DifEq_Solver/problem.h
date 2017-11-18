#pragma once
#include <vector>

//задача
class Problem
{
private:
    int order; //Порядок ур-ия

    std::vector<double> a, A, c, C, m; //параметры
    void initializec(); //инициализация c
    void initializeC(); //инициализация C
    void initializem(); //инициализация m


public:
    std::vector<double> get_parameter(char parameter);
    int get_order();

    Problem(int order, std::vector<double> a, std::vector<double> A); //обычный конструктор
    Problem(const Problem& problem); //конструктор копии для передачи по значению
    ~Problem(); //деструктор

    void printA(); //временная хуйня
};