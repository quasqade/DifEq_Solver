#include <cstdio>
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



	Problem problem = Problem(order, a, A);
	Solver solver = Solver(problem);
	std::cin;
	return 0;
}
