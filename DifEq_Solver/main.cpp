#include <cstdio>
#include <iostream>
#include <limits>

#define DEBUG_VALUES true

int main()
{
	//Постановка задачи
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
    return 0;
}
