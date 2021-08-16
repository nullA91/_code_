#include "functions_shoot.h"
#include "functions_draw.h"

int _function_shoot(char array_cpu[row][column], char array_player[row][column])
{
	bool flag = false;

	char letter = '\0';

	int Y = 0;
	int X = 0;

	int y = 0;
	int x = 0;
	
	std::cout << "enter the X coordinate: ";
	std::cin >> letter;
	std::cout << "enter the Y coordinate: ";
	std::cin >> Y;

	if (static_cast<int>(letter) > 64 && static_cast<int>(letter) < 91)
		X = static_cast<int>(letter) - 64;
	else if (static_cast<int>(letter) > 96 && static_cast<int>(letter) < 123)
		X = static_cast<int>(letter) - 96;
	
	++attempt;

	y = rows[Y - 1];
	x = columns[X - 1];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (array_cpu[y][x] == symbol)
			{
				flag = true;

				array_cpu[y][x] = 'x';
				array_player[y][x] = symbol;

				++hit;
				--part;

				if (y == 1)
				{
					if (array_cpu[y + r_step][x] == symbol)
						++part;
				}
				else if (y > 1 && y < 28)
				{
					if (array_cpu[y - r_step][x] == symbol)
						++part;
					if (array_cpu[y + r_step][x] == symbol)
						++part;
				}
				else if (y == 28)
				{
					if (array_cpu[y - r_step][x] == symbol)
						++part;
				}

				if (x == 2)
				{
					if (array_cpu[y][x + c_step] == symbol)
						++part;
				}
				else if (x > 2 && x < 47)
				{
					if (array_cpu[y][x - c_step] == symbol)
						++part;
					if (array_cpu[y][x + c_step] == symbol)
						++part;
				}
				else if (x == 47)
				{
					if (array_cpu[y][x - c_step] == symbol)
						++part;
				}

				if (part)
				{
					std::cout << "hit" << std::endl;
					system("pause");
				}
				else
				{
					std::cout << "kill" << std::endl;
					part = 1;
					_function_dot_filling(array_player, symbol);
					system("pause");
				}
			}
		}
	}

	if (!flag)
	{
		flag = false;
		array_player[y][x] = 'o';
		std::cout << "miss" << std::endl;
		system("pause");
		return 1;
	}

	if (hit == 20)
	{
		std::cout << "you destroyed all ships" << std::endl;
		std::cout << "number of attempts: " << attempt << " pieces" << std::endl;
		system("pause");
		attempt = 0;
		return 0;
	}
}