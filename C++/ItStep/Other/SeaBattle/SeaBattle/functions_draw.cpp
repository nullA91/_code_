#include "functions_draw.h"

void _function_drawing_field(char array[row][column])
{
	for (int i = 0; i < row; /*++i*/)
	{
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < column; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
		{
			array[i][a] = static_cast<char>(201);
			array[i][b] = static_cast<char>(205);
			array[i][c] = static_cast<char>(205);
			array[i][d] = static_cast<char>(205);
			array[i][e] = static_cast<char>(187);
		}
		++i;
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < column; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
		{
			array[i][a] = static_cast<char>(186);
			array[i][b] = ' ';
			array[i][c] = ' ';
			array[i][d] = ' ';
			array[i][e] = static_cast<char>(186);
		}
		++i;
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < column; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
		{
			array[i][a] = static_cast<char>(200);
			array[i][b] = static_cast<char>(205);
			array[i][c] = static_cast<char>(205);
			array[i][d] = static_cast<char>(205);
			array[i][e] = static_cast<char>(188);
		}
		++i;
	}
}

void _function_filling_field(char array[row][column])
{
	for (int i = 0, j = 1; i < 10; ++i)
	{
		_function_drawing_ship(array, j, symbol/*j + 48*/);
		if (i == 3 || i == 6 || i == 8 || i == 9)
			++j;
	}
	_function_dot_erasing(array);
}

void _function_drawing_ship(char array[row][column], int _ship_size, char symbol)
{
	bool flag = false;

	int counter = 0;

	int direction = 0;
	int y = 0;
	int x = 0;

	int Y = 0;
	int X = 0;

	int directions[4]{ 0 };

POINT:
	flag = false;

	counter = 0;
	
	for (int i = 0; i < 4; ++i)
		directions[i] = i + 1;

	Y = rand() % size;
	X = rand() % size;

	y = rows[Y];
	x = columns[X];

DIRECTION:
	RAND:
	direction = rand() % 4 + 1;

	if (directions[direction - 1] == 0)
		goto RAND;

	if (direction == 1)
	{
		counter++;

		if (Y - _ship_size >= -1)
		{
			flag = true;
			for (int i = 0, r = 0, c = 0; i < _ship_size; ++i, r += r_step, c += c_step)
			{
				if (array[y - r][x] == 'o' || array[y - r][x] == symbol)
				{
					flag = false;
					directions[direction - 1] = 0;
					break;
				}
			}
		}
		else
		{
			flag = false;
			directions[direction - 1] = 0;
		}
	}
	else if (direction == 3)
	{
		counter++;

		if (Y + _ship_size <= size)
		{
			flag = true;
			for (int i = 0, r = 0, c = 0; i < _ship_size; ++i, r += r_step, c += c_step)
			{
				if (array[y + r][x] == 'o' || array[y - r][x] == symbol)
				{
					counter++;
					flag = false;
					directions[direction - 1] = 0;
					break;
				}
			}
		}
		else
		{
			flag = false;
			directions[direction - 1] = 0;
		}
	}
	else if (direction == 2)
	{
		counter++;

		if (X - _ship_size >= -1)
		{
			flag = true;
			for (int i = 0, r = 0, c = 0; i < _ship_size; ++i, r += r_step, c += c_step)
			{
				if (array[y][x - c] == 'o' || array[y - r][x] == symbol)
				{
					counter++;
					flag = false;
					directions[direction - 1] = 0;
					break;
				}
			}
		}
		else
		{
			flag = false;
			directions[direction - 1] = 0;
		}
	}
	else if (direction == 4)
	{
		counter++;

		if (X + _ship_size <= size)
		{
			flag = true;
			for (int i = 0, r = 0, c = 0; i < _ship_size; ++i, r += r_step, c += c_step)
			{
				if (array[y][x + c] == 'o' || array[y - r][x] == symbol)
				{
					counter++;
					flag = false;
					directions[direction - 1] = 0;
					break;
				}
			}
		}
		else
		{
			flag = false;
			directions[direction - 1] = 0;
		}
	}

	if (flag == false && counter < 4) goto DIRECTION;
	else if (flag == false && counter == 4)goto POINT;

	if (flag == true)
	{
		for (int i = 0; i < _ship_size; ++i)
		{
			if (direction == 1)
			{
				array[y][x] = symbol;
				y -= r_step;
			}
			else if (direction == 3)
			{
				array[y][x] = symbol;
				y += r_step;
			}
			else if (direction == 2)
			{
				array[y][x] = symbol;
				x -= c_step;
			}
			else if (direction == 4)
			{
				array[y][x] = symbol;
				x += c_step;
			}
		}
	}
	else goto POINT;

	_function_dot_filling(array, symbol);
}

void _function_dot_filling(char array[row][column], const char symbol)
{

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (array[i][j] == symbol)
			{
				if (i == 1)
				{
					if(array[i + r_step][j] == ' ')
						array[i + r_step][j] = 'o';
				}
				else if (i > 1 && i < 28)
				{
					if (array[i - r_step][j] == ' ')
						array[i - r_step][j] = 'o';
					if (array[i + r_step][j] == ' ')
						array[i + r_step][j] = 'o';
				}
				else if(i == 28)
				{
					if (array[i - r_step][j] == ' ')
						array[i - r_step][j] = 'o';
				}

				if (j == 2)
				{
						if(array[i][j + c_step] == ' ')
						array[i][j + c_step] = 'o';
				}
				else if (j > 2 && j < 47)
				{
					if (array[i][j - c_step] == ' ')
						array[i][j - c_step] = 'o';
					if (array[i][j + c_step] == ' ')
						array[i][j + c_step] = 'o';
				}
				else if(j == 47)
				{
					if (array[i][j - c_step] == ' ')
						array[i][j - c_step] = 'o';
				}
			}
		}
	}
}

void _function_dot_erasing(char array[row][column])
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
			if (array[i][j] == 'o')
				array[i][j] = ' ';
	}
}