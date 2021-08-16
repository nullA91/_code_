#include "GLOBAL.h"

void _function_output_filed(char array[row][column], const int size)
{
	///////////////###output letter###//////////////////////
	for (int i = 0, j = 5, c = 0; i < column + 1; ++i)
	{
		if (i == j)
		{
			std::cout << static_cast<char>(65 + c++);
			j += 5;
		}
		else
			std::cout << ' ';
	}
	std::cout << std::endl;
	//////////////###output digit###///////////////////
	for (int i = 0, j = 1, c = 1; i < row; ++i)
	{
		if (i == j)
		{
			if (c < size)
				std::cout << c++ << "  ";
			else
				std::cout << c++ << ' ';
			j += 3;
		}
		else std::cout << "   ";
		for (int k = 0; k < column; ++k)
			std::cout << array[i][k];
		std::cout << std::endl;
	}
	//////////////////////////////////////////////////////
}