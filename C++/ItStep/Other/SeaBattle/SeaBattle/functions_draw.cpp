#include "functions_draw.h"

void _function_drawing_field(char field[rows][columns])
{
	for (int i = 0; i < rows; /*++i*/)
	{
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < columns; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
		{
			field[i][a] = static_cast<char>(201);
			field[i][b] = static_cast<char>(205);
			field[i][c] = static_cast<char>(205);
			field[i][d] = static_cast<char>(205);
			field[i][e] = static_cast<char>(187);
		}
		++i;
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < columns; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
		{
			field[i][a] = static_cast<char>(186);
			field[i][b] = ' ';
			field[i][c] = ' ';
			field[i][d] = ' ';
			field[i][e] = static_cast<char>(186);
		}
		++i;
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < columns; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
		{
			field[i][a] = static_cast<char>(200);
			field[i][b] = static_cast<char>(205);
			field[i][c] = static_cast<char>(205);
			field[i][d] = static_cast<char>(205);
			field[i][e] = static_cast<char>(188);
		}
		++i;
	}
}

void _function_filling_field(char field[rows][columns])
{
	for (int i = 0, j = 1; i < 10; ++i)
	{
		_function_drawing_ship(field, j, symbol/*j + 48*/);
		if (i == 3 || i == 6 || i == 8 || i == 9)
			++j;
	}
	_function_dot_erasing(field);
}

void _function_drawing_ship(char field[rows][columns], const int _ship_size, const char symbol)
{
	const int size = 10;

	const int _indexes_rows[size] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28 };
	const int _indexes_columns[size] = { 2, 7, 12, 17, 22, 27, 32, 37, 42, 47 };

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

	y =_indexes_rows[Y];
	x = _indexes_columns[X];

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
			for (int i = 0, r = 0, c = 0; i < _ship_size; ++i, r += _step_row, c += _step_column)
			{
				if (field[y - r][x] == 'o' || field[y - r][x] == symbol)
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
			for (int i = 0, r = 0, c = 0; i < _ship_size; ++i, r += _step_row, c += _step_column)
			{
				if (field[y + r][x] == 'o' || field[y - r][x] == symbol)
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
			for (int i = 0, r = 0, c = 0; i < _ship_size; ++i, r += _step_row, c += _step_column)
			{
				if (field[y][x - c] == 'o' || field[y - r][x] == symbol)
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
			for (int i = 0, r = 0, c = 0; i < _ship_size; ++i, r += _step_row, c += _step_column)
			{
				if (field[y][x + c] == 'o' || field[y - r][x] == symbol)
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
				field[y][x] = symbol;
				y -= _step_row;
			}
			else if (direction == 3)
			{
				field[y][x] = symbol;
				y += _step_row;
			}
			else if (direction == 2)
			{
				field[y][x] = symbol;
				x -= _step_column;
			}
			else if (direction == 4)
			{
				field[y][x] = symbol;
				x += _step_column;
			}
		}
	}
	else goto POINT;

	_function_dot_filling(field, symbol);
}

void _function_dot_filling(char field[rows][columns], const char symbol)
{

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (field[i][j] == symbol)
			{
				if (i == 1)
				{
					if(field[i + _step_row][j] == ' ')
						field[i + _step_row][j] = 'o';
				}
				else if (i > 1 && i < 28)
				{
					if (field[i - _step_row][j] == ' ')
						field[i - _step_row][j] = 'o';
					if (field[i + _step_row][j] == ' ')
						field[i + _step_row][j] = 'o';
				}
				else if(i == 28)
				{
					if (field[i - _step_row][j] == ' ')
						field[i - _step_row][j] = 'o';
				}

				if (j == 2)
				{
						if(field[i][j + _step_column] == ' ')
							field[i][j + _step_column] = 'o';
				}
				else if (j > 2 && j < 47)
				{
					if (field[i][j - _step_column] == ' ')
						field[i][j - _step_column] = 'o';
					if (field[i][j + _step_column] == ' ')
						field[i][j + _step_column] = 'o';
				}
				else if(j == 47)
				{
					if (field[i][j - _step_column] == ' ')
						field[i][j - _step_column] = 'o';
				}
			}
		}
	}
}

void _function_dot_erasing(char field[rows][columns])
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			if (field[i][j] == 'o')
				field[i][j] = ' ';
	}
}