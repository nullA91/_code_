#include "GLOBAL.h"
#include "functions_draw.h"
#include "functions_shoot.h"

int main(int _arguments_counter, char* _arguments_value[])
{
	srand(time(NULL));

	char field_player[rows][columns];
	char field_cpu[rows][columns];

	_function_drawing_field(field_player);
	_function_drawing_field(field_cpu);

	_function_filling_field(field_cpu);

	_function_output_filed(field_player);
	_function_output_filed(field_cpu);

	while (_function_shoot_player(field_cpu, field_player))
	{
		system("cls");
		_function_output_filed(field_player);
		_function_output_filed(field_cpu);
	}

	system("pause");

	return 0;
}