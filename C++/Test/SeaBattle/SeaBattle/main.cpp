#include "GLOBAL.h"

#include "DrawFunctions.h"
#include "ShootFunctions.h"

void _function_output_filed(char array[size * 3][size * 5], const int size);

int main(int _arguments_counter, char* _arguments_value[])
{
	srand(time(NULL));

	char field[size * 3][size * 5];
	char symbol = char(254);

	_function_create_field(field, size);

	for (int i = 0, j = 1; i < 10; ++i)
	{
		_function_drawing_ship(field, j, symbol);
		if (i == 3 || i == 6 || i == 8 || i == 9)
			++j;
	}

	_function_output_filed(field, size);

	int X = rand() % 10;
	int Y = rand() % 10;

	for(int i = 0; i < 3; ++i)
		shoot(field, X, Y);

	_function_output_filed(field, size);

	system("pause");

	return 0;
}

void _function_output_filed(char array[size * 3][size * 5], const int size)
{
	//////////////////////////////////////////////////////
	for (int i = 0; i < size * 3; ++i)
	{
		for (int j = 0; j < size * 5; ++j)
			if (array[i][j] == 'o')
				array[i][j] = ' ';
	}
	/////////////////////////////////////////////////////
	for (int i = 0, j = 5, c = 0; i < size * 5 + 1; ++i)
	{
		if (i == j)
		{
			std::cout << char(65 + c++);
			j += 5;
		}
		else
			std::cout << ' ';
	}
	std::cout << std::endl;
	/////////////////////////////////////////////////////
	for (int i = 0, j = 1, c = 1; i < size * 3; ++i)
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
		for (int k = 0; k < size * 5; ++k)
			std::cout << array[i][k];
		std::cout << std::endl;
	}
	//////////////////////////////////////////////////////
	system("pause");
}