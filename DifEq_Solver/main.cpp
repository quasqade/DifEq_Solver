#include <cstdio>
#include <iostream>
#include <limits>
#include "problem.h"
#include "solver.h"


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
		}
		else
		{
			break;
		}
	}
	Problem problem = Problem(order);
	Solver solver = Solver(problem);
	std::cin;
	return 1;
}
