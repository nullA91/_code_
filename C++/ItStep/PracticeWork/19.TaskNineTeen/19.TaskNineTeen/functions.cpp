#include "functions.h"

void output_rectangle(const int& width, const int& height)
{
	for (size_t i = 0; i < height; ++i)
	{
		if (i == 0 || i == (height - 1))
		{
			for (size_t j = 0; j < width; ++j)
			{
				std::cout << '*';
			}
		}
		else
		{
			std::cout << '*';
			for (size_t j = 1; j < width - 1; ++j)
			{
				std::cout << ' ';
			}
			std::cout << '*';
		}
		std::cout << std::endl;
	}
}

int factorial(const int& number)
{
	int counter = 1;
	unsigned long int factorial = 1;

	if (number > 1)
		while (counter <= number)
			factorial *= counter++;

	return factorial;
}

bool composite_number(const int& number)
{
	if (number > 9)
	{
		for (size_t i = 2; i < 10; ++i)
			if (number % i == 0)
				return true;
	}
	else
	{
		for (size_t i = 2; i < number; ++i)
			if (number % i == 0)
				return true;
	}
			
	return false;
}
