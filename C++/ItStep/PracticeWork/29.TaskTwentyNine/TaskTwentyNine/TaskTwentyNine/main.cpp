#include <iostream>
#include <string>
#include <Windows.h>

#include "string_functions.h"

int main(int arg_c, char* arg_v[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int choise = 0;

	do
	{
		system("cls");

		std::cout << "\tменю\n";
		std::cout << "1. длина строки\n";
		std::cout << "2. копирование строки\n";
		std::cout << "3. объединение строк\n";
		std::cout << "4. поиск символа в строке\n";
		std::cout << "5. поиск подстроки в строке\n";
		std::cout << "0. выход\n";
		std::cout << "выберите пункт меню: ";
		std::cin >> choise;

		switch (choise)
		{
			case 1:
			{
				std::string string = "";

				size_t length = 0;

				std::cout << "введите строку: ";
				std::cin >> string;

				length = _function_string_length(string.c_str());

				std::cout << "длина строки: " << length << " символ(а, ов)" << std::endl;

				break;
			}
			case 2:
			{
				char* pointer_string_source = nullptr;
				std::string string_copy;

				std::cout << "введите строку для копирования: ";
				std::cin.ignore();
				std::getline(std::cin, string_copy);

				pointer_string_source = _function_string_copy(pointer_string_source, string_copy.c_str());

				std::cout << "получилось ли скопировать строку: " << pointer_string_source << std::endl;

				break;
			}
			case 3:
			{
				const size_t length = 256;

				char string_source[length] = "";
				char string_copy[length] = "";
				char* string = nullptr;

				std::cout << "введите первую строку: ";
				std::cin.ignore();
				std::cin.getline(string_source, (length - 1));
				std::cout << string_source << std::endl;
				std::cout << "введите вторую строку: ";
				std::cin.getline(string_copy, length - 1);
				std::cout << string_copy << std::endl;

				string = _function_string_concatenation(string_source, string_copy);
				
				std::cout << "результат объеденения двух строк: " << string << std::endl;

				break;
			}
			case 4:
			{
				const size_t length = 256;

				char* pointer_symbol = nullptr;

				char symbol = '\0';
				char string[length] = "";

				std::cout << "введите строку: ";
				std::cin.ignore();
				std::cin.getline(string, (length - 1));

				std::cout << "введите символ для поиска в строке: ";
				std::cin >> symbol;

				pointer_symbol = _function_search_character_in_string(string, symbol);

				if (pointer_symbol != nullptr)
				{
					std::cout << "адрес введенного стмвола в строке: " << (void*)pointer_symbol << std::endl;
					std::cout << "для проверки(строка: Артур Усеня(символ(буква е))): " << (void*)(string + 8) << std::endl;
				}
				else
					std::cout << "в строке отсутствует введенный символ" << std::endl;

				break;
			}
			case 5:
			{
				char string_one[] = "Привет как дела?";
				char string_two[] = "как";
				char* pointer_sub_string = nullptr;

				pointer_sub_string = _function_string_two_in_string_one(string_one, string_two);

				std::cout << "адрес начала как в основной строке: " << (void*)(string_one + 7) << std::endl;
				std::cout << "адрес указателя после работы функции: " << (void*)pointer_sub_string << std::endl;

				break;
			}
			case 0:
				std::cout << "программа завершена\n";
				break;
			default:
				std::cout << "выберите правильный пункт меню" << std::endl;
				break;
		}
		if(choise)
			system("pause");
	} while (choise);
	
	system("pause");
	return 0;
}