#include "DrawFunctions.h"

// функция создания игрового поля
void _function_create_field(char array[size * 3][size * 5], const int size)
{
	for (int i = 0; i < size * 3; /*++i*/)
	{
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < size * 5; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
		{
			array[i][a] = static_cast<char>(201);
			array[i][b] = static_cast<char>(205);
			array[i][c] = static_cast<char>(205);
			array[i][d] = static_cast<char>(205);
			array[i][e] = static_cast<char>(187);
		}
		++i;
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < size * 5; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
		{
			array[i][a] = static_cast<char>(186);
			array[i][b] = ' ';
			array[i][c] = ' ';
			array[i][d] = ' ';
			array[i][e] = static_cast<char>(186);
		}
		++i;
		for (int a = 0, b = a + 1, c = b + 1, d = c + 1, e = d + 1; a < size * 5; a += 5, b = a + 1, c = b + 1, d = c + 1, e = d + 1)
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
// функция рисования корабля на игровом поле
void _function_drawing_ship(char array[size * 3][size * 5], int _ship_size, char symbol)
{
	const int size = 10;

	bool flag = false;

	int _array_row_index[size]; // = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28 };
	int _array_column_index[size]; // = { 2, 7, 12, 17, 22, 27, 32, 37, 42, 47 };

	int direction = 0;
	int _index_row = 0;
	int _index_column = 0;
	int _row_direction = 0;
	int _column_direction = 0;
	int temp = 0;

	for (int i = 0, j = 1, k = 2; i < size; ++i, j += 3, k += 5)
	{
		_array_row_index[i] = j;
		_array_column_index[i] = k;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
DrawingShip:
	_row_direction = rand() % 10;
	_column_direction = rand() % 10;
	_row_direction = rand() % 10;
	_column_direction = rand() % 10;

	_index_row = _array_row_index[_row_direction];
	_index_column = _array_column_index[_column_direction];
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//++_row_direction;
	//++_column_direction;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
DirectionChoise:
	direction = rand() % 4 + 1;
	//direction = rand() % 4 + 1;
	//direction = rand() % 4 + 1;

	if (direction == 1)
	{
		if (_row_direction - _ship_size >= 0)
			flag = true;
	}
	else if (direction == 3)
	{
		if (_row_direction + _ship_size <= size)
			flag = true;
	}
	else if (direction == 2)
	{
		if (_column_direction - _ship_size >= 0)
			flag = true;
	}
	else if (direction == 4)
	{
		if (_column_direction + _ship_size <= size)
			flag = true;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////
	//--_row_direction;
	//--_column_direction;
	///////////////////////////////////////////////////////////////////////////////////////////////
	if (flag)
	{
		for (int i = 0; i < _ship_size; ++i)
		{
			if (direction == 1)
			{
				if (array[_array_row_index[_row_direction - i]][_array_column_index[_column_direction]] == 'o')
					flag = false;
			}
			else if (direction == 3)
			{
				if (array[_array_row_index[_row_direction + i]][_array_column_index[_column_direction]] == 'o')
					flag = false;
				
			}
			else if (direction == 2)
			{
				if (array[_array_row_index[_row_direction]][_array_column_index[_column_direction - i]] == 'o')
					flag = false;
			}
			else if (direction == 4)
			{
				if (array[_array_row_index[_row_direction]][_array_column_index[_column_direction + i]] == 'o')
					flag = false;
			}
		}
		if (flag == false) goto DrawingShip;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	if (flag)
	{
		for (int j = 0; j < _ship_size; ++j)
		{
			if (direction == 1)
			{
				array[_array_row_index[_row_direction - j]][_index_column] = symbol;
			}
			else if (direction == 3)
			{
				array[_array_row_index[_row_direction + j]][_index_column] = symbol;
			}
			else if (direction == 2)
			{
				array[_index_row][_array_column_index[_column_direction - j]] = symbol;
			}
			else if (direction == 4)
			{
				array[_index_row][_array_column_index[_column_direction + j]] = symbol;
			}
		}

		_function_draw_point(array, size, symbol);
	}
	else goto DirectionChoise;
}
// функция создания точек вокруг корабля для правильной отрисовки кораблей
void _function_draw_point(char array[size * 3][size * 5], const int size, char symbol)
{
	for (int i = 0; i < size * 3; ++i)
	{
		for (int j = 0; j < size * 5; ++j)
		{
			if (array[i][j] == symbol)
			{
				if (array[i][j - 5] == ' ')
					array[i][j - 5] = 'o';

				if (array[i][j + 5] == ' ')
					array[i][j + 5] = 'o';

				if (array[i + 3][j] == ' ')
					array[i + 3][j] = 'o';

				if (array[i - 3][j] == ' ')
					array[i - 3][j] = 'o';
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////