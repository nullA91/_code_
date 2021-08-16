#include "GLOBAL.h"
#include "functions_draw.h"
#include "functions_shoot.h"

int main(int _arguments_counter, char* _arguments_value[])
{
	srand(time(NULL));

	bool flag = true;

	char field[row][column];
	char field_player[row][column];

	_function_drawing_field(field);
	_function_drawing_field(field_player);

	_function_filling_field(field);

	

	while (flag)
	{
		_function_output_filed(field_player, size);
		_function_output_filed(field, size);
		flag = _function_shoot(field, field_player);
		system("cls");
		//_function_output_filed(field_player, size);
	}

	system("cls");

	_function_output_filed(field_player, size);

	system("pause");

	return 0;
}