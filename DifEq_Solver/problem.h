#pragma once
#include <vector>

//задача
class Problem
{
private:
    int order; //Порядок ур-ия

    std::vector<double> a, A, c, C, m; //параметры
    void initializec();
    void initializeC();
    void initializem();


public:
    void set_parameter(int); //Установка параметра степени уравнения
	void set_parameter(char, double *&); //Установка параметров a или c

    std::vector<double> get_parameter(char parameter);

    Problem(int order, std::vector<double> a, std::vector<double> A); 
    ~Problem();

    void printA();

	//friend statement;
};