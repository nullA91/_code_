#include "functions.h"

void add_line_end(char**& array, size_t& rows, size_t& columns, const char* string)
{
	char** pointer_temp_array = nullptr;

	if (strlen(string) > columns)
		columns = strlen(string);

	++rows;
	pointer_temp_array = new char* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		pointer_temp_array[i] = new char[columns];
	}

	strcpy(pointer_temp_array[rows - 1], string);
	for (size_t i = 0; i < rows - 1; ++i)
	{
		strcpy(pointer_temp_array[i], array[i]);
	}

	for (size_t i = 0; i < rows - 1; ++i)
		delete[] array[i];
	delete[] array;

	array = pointer_temp_array;
}

void add_line_begin(char**& array, size_t & rows, size_t & columns, const char* string)
{
	char** pointer_temp_array = nullptr;

	if (strlen(string) > columns)
		columns = strlen(string);

	++rows;
	pointer_temp_array = new char* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		pointer_temp_array[i] = new char[columns];
	}

	strcpy(pointer_temp_array[0], string);
	for (size_t i = 1; i < rows; ++i)
	{
		strcpy(pointer_temp_array[i], array[(i - 1)]);
	}

	for (size_t i = 0; i < rows - 1; ++i)
		delete[] array[i];
	delete[] array;

	array = pointer_temp_array;
}

void add_line_index(char**& array, size_t & rows, size_t & columns, const char* string, const int& index)
{
	char** pointer_temp_array = nullptr;

	if (strlen(string) > columns)
		columns = strlen(string);

	++rows;
	pointer_temp_array = new char* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		pointer_temp_array[i] = new char[columns];
	}

	for (size_t i = 0; i < index - 1; ++i)
	{
		strcpy(pointer_temp_array[i], array[i]);
	}
	strcpy(pointer_temp_array[index - 1], string);
	for (size_t i = index; i < rows; ++i)
	{
		strcpy(pointer_temp_array[i], array[(i - 1)]);
	}

	for (size_t i = 0; i < rows - 1; ++i)
		delete[] array[i];
	delete[] array;

	array = pointer_temp_array;
}

void del_line_index(char**& array, size_t & rows, size_t & columns, const int& index)
{
	char** pointer_temp_array = nullptr;

	--rows;
	pointer_temp_array = new char* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		pointer_temp_array[i] = new char[columns];
	}

	for (size_t i = 0; i < index - 1; ++i)
	{
		strcpy(pointer_temp_array[i], array[i]);
	}

	for (size_t i = index; i < rows + 1; ++i)
	{
		strcpy(pointer_temp_array[i - 1], array[i]);
	}

	for (size_t i = 0; i < rows + 1; ++i)
		delete[] array[i];
	delete[] array;

	array = pointer_temp_array;
}

void menu_output()
{
	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < 22; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185);
	std::cout << "menu";
	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 28; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(187) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "1. adding a line to the end of the text.                ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
	{
		if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "2. adding a line to the begining of the text.           ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
	{
		if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "3. adding a line to the text at the specified index.    ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
	{
		if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "4. deleting a line from the text at the specified index.";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
	{
		if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "5. displaying text on the screen.                       ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
	{
		if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "0. exit.                                                ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < 56; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(188) << '\n';
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