﻿#include <cstdio>
#include <iostream>
#include <limits>
#include "problem.h"
#include "solver.h"
#include <vector>


#define DEBUG_VALUES false

int main()
{
	//Постановка задачи
	std::cin;
	std::cout << "Введите порядок ДУ:\n";
	int order;
	while (true)
	{
		if (DEBUG_VALUES)
		{
			order = 1;
		}
		else
		{
			std::cin >> order;
		}
		
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			std::cout << "Неверный порядок!" << std::endl;
		}
		else
		{
			break;
		}
	}

	std::vector<double> a(order+1);
	std::vector<double> A(order+1);

	std::cout << "Введите коэффициенты:" << std::endl;

	for (int i = 0; i < order+1; ++i)
	{
		while (true)
		{
			std::cout << "a" << i << " = ";
			std::cin >> a[i];

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					std::cout << "Коэффициент должен быть числом с плавающей точкой!" << std::endl;
				}
				else
				{
					break;
				}
		}
	}
	for (int i = 0; i < order+1; ++i)
	{
		while (true)
		{
			std::cout << "A" << i << " = ";
			std::cin >> A[i];

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					std::cout << "Коэффициент должен быть числом с плавающей точкой!" << std::endl;
				}
				else
				{
					break;
				}
		}
	}


	//Параметры решения
	std::vector<double> IC(order);
	double dt;
	int command;

	std::cout << "Введите параметры решения:" << std::endl;

	std::cout << "Н. У.:" << std::endl;
	for (int i = 0; i < order; i++)
	{

		while (true)
		{
			std::cout << "x0(" << i << ") = ";
			double input;
			std::cin >> input;
			IC.at(i) = input;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					std::cout << "Коэффициент должен быть числом с плавающей точкой!" << std::endl;
				}
				else
				{
					break;
				}
		}
	}

	while (true)
		{
		std::cout << "Шаг интегрирования = ";
		std::cin >> dt;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				std::cout << "Коэффициент должен быть числом с плавающей точкой!" << std::endl;
			}
				else
			{
				break;
			}
	}

	while (true)
		{
		std::cout << "Выберите управляющее воздействие:" << std::endl;
		std::cout << "1. Без воздействия." << std::endl;
		std::cout << "2. sin(t)" << std::endl;
		std::cout << "3. ln(1+t)" << std::endl;
		std::cout << "4. exp(-t)" << std::endl;
		std::cout << "5. 1(t)" << std::endl;
		std::cout << "Тип воздействия: ";
		std::cin >> command;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				std::cout << "Коэффициент должен быть числом!" << std::endl;
			}
			else
			{
				command--;
				if ((command<0) || (command>5))
				{
					std::cout << "Коэффициент должен соответствовать номеру команды!" << std::endl;
				}
				else
				break;
			}
	}

	Problem problem = Problem(order, a, A);
	Solver solver = Solver(&problem);
	solver.solve(IC, dt, (Control)command);
	int i;
	std::cin >> i;
	return 0;
}
