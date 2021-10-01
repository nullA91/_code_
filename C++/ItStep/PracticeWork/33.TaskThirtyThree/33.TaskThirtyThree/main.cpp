#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

/*
Задание 1. Напишите функцию для обращения одномерного массива в N-мерный. Должны выполняться соответствующие проверки.
Задание 2. Написать программу, которая дает пользователю ввести 5 фамилий студентов, а затем находит среди них самую длинную фамилию.
*/

template<typename data_type>
data_type** array_expansion(data_type* array, const size_t& columns, const size_t& rows);

char* surname_length();

char* _convert_ANSI_string_to_ASCII_string(const char string[]);
char* _convert_ANSI_string_to_ASCII_string(char string[]);

int main(int arg_c, char* arg_v[])
{
	const unsigned int second_row = 1;
	const size_t size = 256;
	const size_t length = 10;
	size_t rows = 0;
	size_t columns = 0;
	
	int array[length] = { 12, -7, 5, 43, 2, 113, 7, 11, 0, -32 };

	int** pointer_new_array = nullptr;
	int* pointer_array = nullptr;

	char surname[size] = "";

	std::cout << _convert_ANSI_string_to_ASCII_string("введите количество строк в массиве: ");
	std::cin >> rows;
	std::cout << _convert_ANSI_string_to_ASCII_string("введите количество столбцов в массиве: ");
	std::cin >> columns;

	pointer_array = new int[columns];

	for (size_t i = 0; i < columns; ++i)
	{
		pointer_array[i] = i + 1;
	}

	pointer_new_array = array_expansion(array, length, rows);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < length; ++j)
			std::cout << pointer_new_array[i][j] << ' ';
		std::cout << std::endl;
	}
	for (size_t i = second_row; i < rows; ++i)
	{
		delete[] pointer_new_array[i];
	}
	delete[] pointer_new_array;

	pointer_new_array = array_expansion(pointer_array, columns, rows);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			std::cout << pointer_new_array[i][j] << ' ';
		std::cout << std::endl;
	}
	for (size_t i = second_row; i < rows; ++i)
	{
		delete[] pointer_new_array[i];
	}
	delete[] pointer_new_array;

	delete[] pointer_array;

	strcpy(surname, surname_length());

	std::cout << surname << std::endl;

	system("pause");
	return 0;
}

template<typename data_type>
data_type** array_expansion(data_type* array, const size_t& columns, const size_t& rows)
{
	data_type** new_array = nullptr;

	new_array = new int* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		new_array[i] = new int[columns];
	}
	new_array[0] = array;

	return new_array;
}

char* surname_length()
{
	const size_t rows = 5;
	const size_t columns = 256;

	char surname[columns] = "";
	char surnames[rows][columns];

	for (size_t i = 0; i < rows; ++i)
	{
		std::cout << _convert_ANSI_string_to_ASCII_string("введите ") << i + 1 << _convert_ANSI_string_to_ASCII_string(" -ую фамилию студента: ");
		std::cin.ignore();
		std::cin.getline(surnames[i], (columns - 1));
		if (strlen(surnames[i]) > strlen(surname))
			strcpy(surname, surnames[i]);
	}

	return surname;
}

char* _convert_ANSI_string_to_ASCII_string(const char string[])
{
	char* _new_string = new char[strlen(string) + 2];

	int i = 0;

	while (string[i] != '\0')
	{
		unsigned char symbol = string[i];

		if ((symbol >= 192) && (symbol <= 255))
			if (symbol < 240)
				_new_string[i] = string[i] - 64;
			else
				_new_string[i] = string[i] - 16;
		else
			_new_string[i] = string[i];
		i++;
	}

	_new_string[i] = '\0';

	return _new_string;
}

char* _convert_ANSI_string_to_ASCII_string(char string[])
{
	char* _new_string = new char[strlen(string) + 2];

	int i = 0;

	while (string[i] != '\0')
	{
		unsigned char symbol = string[i];

		if ((symbol >= 192) && (symbol <= 255))
			if (symbol < 240)
				_new_string[i] = string[i] - 64;
			else
				_new_string[i] = string[i] - 16;
		else
			_new_string[i] = string[i];
		i++;
	}

	_new_string[i] = '\0';

	return _new_string;
}
