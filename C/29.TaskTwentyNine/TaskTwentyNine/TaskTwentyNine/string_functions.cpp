#include "string_functions.h"

size_t _function_string_length(const char* string)
{
	if (string == nullptr) return 0;

	size_t string_length = 0;

	for (size_t i = 0; string[i] != '\0'; ++i)
		++string_length;

	return string_length;
}

char* _function_string_copy(char* source_string, const char* copied_string)
{
	size_t length = 0;

	if (source_string != nullptr)
	{
		delete[] source_string;
		source_string = nullptr;
	}
	
	length = _function_string_length(copied_string) + 1;

	source_string = new char[length];
	source_string[length - 1] = '\0';

	for (size_t i = 0; i < _function_string_length(copied_string); ++i)
		source_string[i] = copied_string[i];

	return source_string;
}

char* _function_string_concatenation(char* string_one, const char* string_two)
{
	size_t length = 0;

	unsigned int index = 0;

	char* temp_string = nullptr;

	if (string_one != nullptr)
	{
		length = _function_string_length(string_one) + 1;

		temp_string = new char[length];
		temp_string[length - 1] = '\0';

		for (size_t i = 0; i < _function_string_length(string_one); ++i)
			temp_string[i] = string_one[i];

		length = _function_string_length(temp_string) + _function_string_length(string_two) + 1;
	}
	else
	{
		length = _function_string_length(string_one) + 1;

		temp_string = new char[length];
		temp_string[length - 1] = '\0';

		for (size_t i = 0; i < _function_string_length(string_one); ++i)
			temp_string[i] = string_one[i];

		delete[] string_one;
		string_one = nullptr;

		length = _function_string_length(temp_string) + _function_string_length(string_two) + 1;

		string_one = new char[length];
		string_one[length - 1] = '\0';
	}

	for (; index < _function_string_length(temp_string); ++index)
		string_one[index] = temp_string[index];
	for (size_t i = 0; i < _function_string_length(string_two); ++i, ++index)
		string_one[index] = string_two[i];

	if(temp_string != nullptr)
		delete[] temp_string;

	return string_one;
}

char* _function_search_character_in_string(char* string, char symbol)
{
	char* adress = nullptr;

	if (_function_string_length(string) == 0) return nullptr;

	for (size_t i = 0; i < _function_string_length(string); ++i)
	{
		if (string[i] == symbol)
		{
			adress = string + i;
			return adress;
			break;
		}
	}

	return adress;
}

char* _function_string_two_in_string_one(char* string_one, char* string_two)
{
	size_t length = 0;

	char* adress = nullptr;

	if (_function_string_length(string_one) < _function_string_length(string_two)) return nullptr;

	for (size_t i = 0; i < _function_string_length(string_one); ++i)
	{
		if (string_one[i] == string_two[length])
		{
			++length;
			++i;

			while (string_one[i] == string_two[length])
				++length;

			if (length == _function_string_length(string_two))
			{
				adress = string_one + (i - length);
				return adress;
				break;
			}
		}
	}

	return adress;
}