#include "GLOBAL.h"

void _function_output_filed(const char field[rows][columns])
{
	static int counter = 0;

	const int size = 10;
	///////////////###output letter###//////////////////////
	if (counter % 2 != 0)
		_function_console_cursor(columns + 5, 0);

	for (int i = 0, j = 5, c = 0; i < columns + 1; ++i)
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
	for (int i = 0, j = 1, c = 1; i < rows; ++i)
	{
		if (counter % 2 != 0)
			_function_console_cursor(columns + 5, i + 1);

		if (i == j)
		{
			if (c < size)
				std::cout << c++ << "  ";
			else
				std::cout << c++ << ' ';
			j += 3;
		}
		else std::cout << "   ";
		for (int k = 0; k < columns; ++k)
			std::cout << field[i][k];
		std::cout << std::endl;
	}
	//////////////////////////////////////////////////////
	++counter;

	if (counter > 1) counter = 0;
}

int length(int array[])
{
	int _size_array = 0;

	for (int i = 0; i < 10; ++i)
	{
		if (array[i] != -1)
			++_size_array;
		else
			break;
	}

	return _size_array;
}

void _function_console_cursor(int X, int Y)
{
	static HANDLE console_number = NULL;
	if (!console_number)
		console_number = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor = { X, Y };
	SetConsoleCursorPosition(console_number, cursor);
}