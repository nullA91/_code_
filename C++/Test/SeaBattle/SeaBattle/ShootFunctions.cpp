#include "ShootFunctions.h"

void shoot(char array[size * 3][size * 5], int Y, int X)
{
	std::cout << "zapusk shoot" << std::endl;
	system("pause");

	char _ship_part = static_cast<char>(254);

	bool flag = false;

	int counter = 0;

	int start = 0;
	int finish = 10;

	int row[size] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28 };
	int column[size] = { 2, 7, 12, 17, 22, 27, 32, 37, 42, 47 };

	int y = 0;
	int x = 0;

	y = row[Y];
	x = column[X];

	row[Y] = 0;
	column[X] = 0;

	for (int i = 0; i < size * 3; ++i)
	{
		for (int j = 0; j < size * 5; ++j)
		{
			if (array[y][x] == _ship_part)
			{
				flag = true;

				--part;
				++hit;
				
				array[y][x] = 'X';

				if (array[row[Y - 1]][column[X]] == _ship_part)
					++part;
				if (array[row[Y + 1]][column[X]] == _ship_part)
					++part;
				if (array[row[Y]][column[X - 1]] == _ship_part)
					++part;
				if (array[row[Y]][column[X + 1]] == _ship_part)
					++part;

				if (part)
				{
					if (hit == 1)
					{
						std::cout << "strelba po koordinatam: " << "Y: " << y << '\t' << "X: " << x << std::endl;
						std::cout << "ranil" << std::endl;
						system("pause");
						RETRY:
						start = rand() % (Y + 2) + Y - 1;
						finish = rand() % (X + 2) + X - 1;

						if (row[Y] == 0) goto RETRY;
						if (column[X] == 0) goto RETRY;

						shoot(array, start, finish);
					}
					else if (hit == 2)
					{
						std::cout << "strelba po koordinatam: " << "Y: " << y << '\t' << "X: " << x << std::endl;
						std::cout << "ranil" << std::endl;
						system("pause");
						if (array[row[Y - 1]][x] == 'X' || array[row[Y + 1]][x] == 'X')
						{
						Y:
							start = rand() % (Y + hit) + Y - 1;
							if (row[Y] == 0) goto Y;
						}
						if (array[y][column[X - 1]] == 'X' || array[y][column[X + 1]] == 'X')
						{
						X:
							finish = rand() % (X + hit) + X - 1;
							if (column[X] == 0) goto X;
						}

						shoot(array, start, finish);
					}
					else if (hit == 2)
					{
						std::cout << "strelba po koordinatam: " << "Y: " << y << '\t' << "X: " << x << std::endl;
						std::cout << "ranil" << std::endl;
						system("pause");
						if (array[row[Y - 1]][x] == 'X' || array[row[Y + 1]][x] == 'X')
						{
						Q:
							start = rand() % (Y + hit) + Y - 1;
							if (row[Y] == 0) goto Q;
						}
						if (array[y][column[X - 1]] == 'X' || array[y][column[X + 1]] == 'X')
						{
						W:
							finish = rand() % (X + hit) + X - 1;
							if (column[X] == 0) goto W;
						}

						shoot(array, start, finish);
					}
					else if (hit == 3)
					{
						std::cout << "strelba po koordinatam: " << "Y: " << y << '\t' << "X: " << x << std::endl;
						std::cout << "ranil" << std::endl;
						system("pause");
						if (array[row[Y - 2]][x] == 'X')// || array[row[Y + 1]][x] == 'X')
						{
						A:
							start = rand() % (Y - hit) + Y + 1;
							if (row[Y] == 0) goto A;
						}
						else if (array[row[Y + 2]][x] == 'X')
						{
							C:
							start = rand() % (Y - 1) + Y + hit;
							if (row[Y] == 0) goto C;
						}
						if (array[y][column[X - 2]] == 'X')// || array[y][column[X + 1]] == 'X')
						{
						B:
							finish = rand() % (X - hit) + X + 1;
							if (column[X] == 0) goto B;
						}
						else if (array[y][column[X + 2]] == 'X')
						{
						D:
							finish = rand() % (X - 1) + X + hit;
							if (column[X] == 0) goto D;
						}

						shoot(array, start, finish);
					}
				}
				else
				{
					std::cout << "ubil" << std::endl;
					system("pause");
				}
			}
			else
			{
				std::cout << "mimo" << std::endl;
				//system("pause");
			}
		}
	}

	//_function_output_filed(array, size);
}