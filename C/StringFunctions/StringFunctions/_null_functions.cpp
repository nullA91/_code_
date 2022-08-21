#include "_null_functions.h"

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

void _console_menu_creation_pyramid(const char* string, const size_t _max_length)
{
	std::cout << '+';
	for (size_t i = 0; i < _max_length - 1; ++i)
		std::cout << '-';
	std::cout << '+' << std::endl;

	std::cout << '|';
	for (size_t i = 0; i < (_max_length - strlen(string)) / 2; ++i)
		std::cout << ' ';
	std::cout << string;
	for (size_t i = 0; i < (_max_length - strlen(string) - 1) / 2; ++i)
		std::cout << ' ';
	std::cout << '|' << std::endl;;

	std::cout << '+';
	for (size_t i = 0; i < _max_length - 1; ++i)
		std::cout << '-';
	std::cout << '+' << std::endl;
}

void _console_menu_creation(const char* string, const size_t _max_length)
{
	std::cout << '+';
	for (size_t i = 0; i < _max_length - 1; ++i)
		std::cout << '-';
	std::cout << '+' << std::endl;

	std::cout << '|';
	std::cout << string;
	for (size_t i = 0; i < (_max_length - strlen(string) - 1); ++i)
		std::cout << ' ';
	std::cout << '|' << std::endl;;

	std::cout << '+';
	for (size_t i = 0; i < _max_length - 1; ++i)
		std::cout << '-';
	std::cout << '+' << std::endl;
}