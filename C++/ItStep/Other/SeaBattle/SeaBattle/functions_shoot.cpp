#include "functions_shoot.h"
#include "functions_draw.h"

//###################################################################################
//#                                !!!PLAYER!!!                                     #
//###################################################################################
int _function_shoot_player(char _field_cpu[rows][columns], char _field_player[rows][columns])
{
	static int hit = 0;

	const int size = 10;

	const int _indexes_rows[size] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28 };
	const int _indexes_columns[size] = { 2, 7, 12, 17, 22, 27, 32, 37, 42, 47 };

	bool flag = false;

	char letter = '\0';

	int Y = 0;
	int X = 0;

	int y = 0;
	int x = 0;
	////
C_X:
	std::cout << "enter the X coordinate: ";
	std::cin >> letter;

	if ((static_cast<int>(letter) < 65 || static_cast<int>(letter) > 74) && (static_cast<int>(letter) < 97 || static_cast<int>(letter) > 106))
	{
		std::cout << "enter the correct x coordinate\n";
		system("pause");
		goto C_X;
	}
	////
C_Y:
	std::cout << "enter the Y coordinate: ";
	std::cin >> Y;

	if (Y < 1 || Y > 10)
	{
		std::cout << "enter the y coordinate correctly\n";
		system("pause");
		goto C_Y;
	}
	////
	if (static_cast<int>(letter) > 64 && static_cast<int>(letter) < 91)
		X = static_cast<int>(letter) - 64;
	else if (static_cast<int>(letter) > 96 && static_cast<int>(letter) < 123)
		X = static_cast<int>(letter) - 96;

	++attempt;

	y = _indexes_rows[Y - 1];
	x = _indexes_columns[X - 1];

	if (_field_cpu[y][x] == 'x')
	{
		--attempt;

		std::cout << "you have already shot this position \n";
		std::cout << "move transition \n";
		system("pause");
		goto C_X;
	}

	if (_field_cpu[y][x] == symbol)
	{
		flag = true;

		_field_cpu[y][x] = 'x';
		_field_player[y][x] = symbol;

		++hit;
		--part;

		if (y == 1)
		{
			if (_field_cpu[y + _step_row][x] == symbol)
				++part;
		}
		else if (y > 1 && y < 28)
		{
			if (_field_cpu[y - _step_row][x] == symbol)
				++part;
			if (_field_cpu[y + _step_row][x] == symbol)
				++part;
		}
		else if (y == 28)
		{
			if (_field_cpu[y - _step_row][x] == symbol)
				++part;
		}

		if (x == 2)
		{
			if (_field_cpu[y][x + _step_column] == symbol)
				++part;
		}
		else if (x > 2 && x < 47)
		{
			if (_field_cpu[y][x - _step_column] == symbol)
				++part;
			if (_field_cpu[y][x + _step_column] == symbol)
				++part;
		}
		else if (x == 47)
		{
			if (_field_cpu[y][x - _step_column] == symbol)
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
			_function_dot_filling(_field_player, symbol);
			system("pause");
		}

		if (hit == 20)
		{
			system("cls");
			std::cout << "you destroyed all ships" << std::endl;
			std::cout << "number of attempts: " << attempt << " pieces" << std::endl;

			return 0;
		}
		else
			return 1;
	}

	else
	{
		flag = false;
		_field_player[y][x] = 'o';
		std::cout << "miss" << std::endl;
		system("pause");
		return -1;
	}
}