#include "functions.h"
#include <iostream>
#include "_null_functions.h"

int main()
{
	char _string_one[1024] = ""; // символьный массив размером 1 мегабайт для создания строки
	char _string_two[1024] = ""; // символьный массив размером 1 мегабайт для создания строки
	int position = 0; // целочисленная переменная для ввода позиции строки
	int length = 0; // целочисленная переменная для ввода длины строки
	int choise = 0; // целочисленная переменная для выбора пункта меню

	do
	{
		_console_menu_creation(_convert_ANSI_string_to_ASCII_string("1. длина строки"), 46);
		_console_menu_creation(_convert_ANSI_string_to_ASCII_string("2. переворот (инверсия) строки"), 46);
		_console_menu_creation(_convert_ANSI_string_to_ASCII_string("3. проверка баланса скобок строки"), 46);
		_console_menu_creation(_convert_ANSI_string_to_ASCII_string("4. поиск первого вхождения подстроки в строку"), 46);
		_console_menu_creation(_convert_ANSI_string_to_ASCII_string("5. конкатенация строк"), 46);
		_console_menu_creation(_convert_ANSI_string_to_ASCII_string("6. извлечения символов из входной строки"), 46);
		_console_menu_creation(_convert_ANSI_string_to_ASCII_string("0. выход"), 46);
		
		std::cout << _convert_ANSI_string_to_ASCII_string("\nвыберите пункт меню: ");
		std::cin >> choise;

		switch (choise)
		{
			case 1:
				std::cin.clear();
				std::cin.ignore(32767, '\n');

				std::cout << _convert_ANSI_string_to_ASCII_string("введите строку для определения ее длинны: ");
				std::cin.getline(_string_one, sizeof(_string_one));
				std::cout << _convert_ANSI_string_to_ASCII_string("длина строки: ") << _length_string(_string_one) << std::endl;
				break;
			case 2:
				std::cin.clear();
				std::cin.ignore(32767, '\n');

				std::cout << _convert_ANSI_string_to_ASCII_string("введите строку, которую необходимо инвертировать: ");
				std::cin.getline(_string_one, sizeof(_string_one));
				std::cout << _convert_ANSI_string_to_ASCII_string("инвертированная строка: ") << _reverse_string(_string_one) << std::endl;
				break;
			case 3:
				std::cin.clear();
				std::cin.ignore(32767, '\n');

				std::cout << _convert_ANSI_string_to_ASCII_string("введите строку для проверки баланса скобок: ");
				std::cin.getline(_string_one, sizeof(_string_one));
				if (_balance_brackets(_string_one) == 1)
					std::cout << _convert_ANSI_string_to_ASCII_string("баланс скобок выдержан\n");
				else if (_balance_brackets(_string_one) == -1)
					std::cout << _convert_ANSI_string_to_ASCII_string("в строке отсутствуют скобки\n");
				else
					std::cout << _convert_ANSI_string_to_ASCII_string("баланс скобок нарушен\n");
				break;
			case 4:
				std::cin.clear();
				std::cin.ignore(32767, '\n');

				std::cout << _convert_ANSI_string_to_ASCII_string("введите строку для получения позиции подстроки: ");
				std::cin.getline(_string_one, sizeof(_string_one));
				std::cout << _convert_ANSI_string_to_ASCII_string("введите подстроку: ");
				std::cin.getline(_string_two, sizeof(_string_two));
				if (_occurence_substring(_string_one, _string_two))
					std::cout << _convert_ANSI_string_to_ASCII_string("номер позиции: ") << _occurence_substring(_string_one, _string_two) << std::endl;
				else
					std::cout << _convert_ANSI_string_to_ASCII_string("в текущей строке отсутствует введенная подстрока") << std::endl;
				break;
			case 5:
				std::cin.clear();
				std::cin.ignore(32767, '\n');

				std::cout << _convert_ANSI_string_to_ASCII_string("введите первую строку для конкатенации: ");
				std::cin.getline(_string_one, sizeof(_string_one));
				std::cout << _convert_ANSI_string_to_ASCII_string("введите вторую строку для конкатенации: ");
				std::cin.getline(_string_two, sizeof(_string_two));
				std::cout << _convert_ANSI_string_to_ASCII_string("введите позицию для вставляемой строки: ");
				std::cin >> position;
				std::cout << _convert_ANSI_string_to_ASCII_string("результат объединения: ") << _insert_n_string(_string_one, _string_two, position) << std::endl;
				break;
			case 6:
				std::cin.clear();
				std::cin.ignore(32767, '\n');

				std::cout << _convert_ANSI_string_to_ASCII_string("введите строку из которой необходимо скопировать символовы: ");
				std::cin.getline(_string_one, sizeof(_string_one));
				std::cout << _convert_ANSI_string_to_ASCII_string("введите длину копируемой строки: ");
				std::cin >> length;
				std::cout << _convert_ANSI_string_to_ASCII_string("введите номер позиции, начиная с которой необходимо скопировать строку: ");
				std::cin >> position;
				std::cout << _convert_ANSI_string_to_ASCII_string("скопированная строка: ") << _ñut_string(_string_one, length, position) << std::endl;
				break;
			case 0:
				choise = 0;
				break;
			default:
				std::cout << _convert_ANSI_string_to_ASCII_string("в меню отсутствует введенный пункт, введите существующий пункт в меню.\n\n");
				break;
		}
		system("pause");
		system("cls");
	} while (choise != 0);

	return 0;
}
