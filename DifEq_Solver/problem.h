#pragma once
#include <vector>

//Класс задачи
class Problem
{
private:
    int order; //Порядок ур-ия

    std::vector<double> a, A, c, C, m; //параметры
    void initializec(); //инициализация c
    void initializeC(); //инициализация C
    void initializem(); //инициализация m


public:
    std::vector<double> get_parameter(char parameter); //функция возвращает параметр, указанный в аргументе
    int get_order(); //функция возвращает порядок уравнения

    Problem(int order, std::vector<double> a, std::vector<double> A); //конструктор
    ~Problem();

};