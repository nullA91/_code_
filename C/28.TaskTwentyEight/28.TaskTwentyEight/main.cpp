#include <cstring>
#include <ctime>
#include <iostream>

/*
#########################################################################
Задание 1. Дана строка символов. Заменить в ней все пробелы на табуляции.
#########################################################################
Задание 2. Дана строка символов. Определить количество
букв, цифр и остальных символов, присутствующих в строке.
#########################################################################
Задание 3. Подсчитать количество слов во введенном предложении.
#########################################################################
Задание 4. Дана строка символов. Необходимо проверить
является ли эта строка палиндромом.
#########################################################################
*/

void replacing_spaces_tabs(char* string);
std::pair<std::pair<int, int>, int> num_letters_numb_char(const char* string);
int number_words_sentence(const char* string);
bool palindrome_check(const char* string);

int main(int arg_c, char* arg_v[])
{
	srand(time(NULL));

	const int min = 32;
	const int max = 64;

	int letters = 0;
	int numbers = 0;
	int characters = 0;

	char string[] = "Hello what's your name, how old are you 20 or 35? I'm 34. I live on 10th Street.";
	const char palindrome[] = "A man, A plan, a canal-Panama.";

	std::cout << string << std::endl;

	replacing_spaces_tabs(string);
	std::cout << string << std::endl;

	letters = num_letters_numb_char(string).first.first;
	numbers = num_letters_numb_char(string).first.second;
	characters = num_letters_numb_char(string).second;

	std::cout << "number of letters: " << letters << std::endl;
	std::cout << "number of digits: " << numbers << std::endl;
	std::cout << "number of remaining characters: " << characters << std::endl;

	std::cout << "number of words in sentense: " << number_words_sentence(string) << std::endl;

	if (palindrome_check(palindrome))
		std::cout << "character string is palindrome" << std::endl;
	else
		std::cout << "character string is not palindrome" << std::endl;

	system("pause");
	return 0;
}

void replacing_spaces_tabs(char* string)
{
	const char tabulation = 9;
	const char space = 32;

	for (size_t i = 0; i < strlen(string); ++i)
	{
		if (string[i] == space)
			string[i] = tabulation;
	}
}

std::pair<std::pair<int, int>, int> num_letters_numb_char(const char* string)
{
	std::pair<std::pair<int, int>, int> return_values;

	int letters = 0;
	int numbers = 0;
	int characters = 0;

	for (size_t i = 0; i < strlen(string); ++i)
	{
		if (static_cast<int>(string[i]) > 47 && static_cast<int>(string[i]) < 58)
			++numbers;
		else if ((static_cast<int>(string[i]) > 64 && static_cast<int>(string[i]) < 91) || (static_cast<int>(string[i]) > 96 && static_cast<int>(string[i]) < 123))
			++letters;
		else
			++characters;
	}

	return_values.first.first = letters;
	return_values.first.second = numbers;
	return_values.second = characters;

	return return_values;
}

int number_words_sentence(const char* string)
{
	int words = 0;
	int index = 0;

	while (index < strlen(string))
	{
		if ((static_cast<int>(string[index]) > 64 && static_cast<int>(string[index]) < 91) || (static_cast<int>(string[index]) > 96 && static_cast<int>(string[index]) < 123))
		{
			++words;
			++index;
			while ((static_cast<int>(string[index]) > 64 && static_cast<int>(string[index]) < 91) || (static_cast<int>(string[index]) > 96 && static_cast<int>(string[index]) < 123) || static_cast<char>(string[index]) == 39)
				++index;
		}

		++index;
	}

	return words;
}

bool palindrome_check(const char* string)
{
	bool flag = true;

	size_t length = 0;

	int index = 0;

	char* pointer_string = nullptr;

	for (size_t i = 0; i < strlen(string); ++i)
	{
		if ((static_cast<int>(string[i]) > 64 && static_cast<int>(string[i]) < 91) || (static_cast<int>(string[i]) > 96 && static_cast<int>(string[i]) < 123))
			++length;
	}
	++length;

	pointer_string = new char[length];
	pointer_string[length - 1] = '\0';

	for (size_t i = 0; i < strlen(string); ++i)
	{
		if ((static_cast<int>(string[i]) > 64 && static_cast<int>(string[i]) < 91) || (static_cast<int>(string[i]) > 96 && static_cast<int>(string[i]) < 123))
		{
			if ((static_cast<int>(string[i]) > 64 && static_cast<int>(string[i]) < 91))
			{
				pointer_string[index] = string[i] + 32;
				++index;
			}
			else
			{
				pointer_string[index] = string[i];
				++index;
			}
		}
	}

	for (size_t i = 0, j = length - 2; i < (length - 1) / 2; ++i, --j)
	{
		if (pointer_string[i] != pointer_string[j])
		{
			flag = false;
			break;
		}
	}

	delete[] pointer_string;

	return flag;
}
// min + rand() % (max - min + 1)
