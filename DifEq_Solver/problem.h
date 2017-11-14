#pragma once
class Problem
{
    static int order; //Порядок ур-ия

    static double *a;
    static double *c;

public:
    void set_parameter(int); //Установка параметра степени уравнения
	void set_parameter(char, double *&); //Установка параметров a или c

	//virtual double *get_parameter(char *variable) = 0; //Почучение параметров (либо-либо): степень уравнения, a, c
	double get_parameter(char *variable, int); //Почучение параметра: a[i] или c[i]

    Problem(int degree);
	~Problem() {};

	//friend statement;
};