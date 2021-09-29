#include "functions.h"
/*
Задание 1. Написать функцию, добавляющую строку двухмерному массиву в конец.
Задание 2. Написать функцию, добавляющую строку двухмерному массиву в начало.
Задание 3. Написать функцию, добавляющую строку двухмерному массиву в указанную позицию.
Задание 4. Написать функцию, удаляющую строку двухмерного массива по указанному номеру.
*/
///////////////////////////////////////////////////////////////////////////////////////
/*
Вот дом, который построил Джек.
А это пшеница, которая в темном чулане хранится
В доме, который построил Джек.
А это веселая птица-синица,
которая часто ворует пшеницу,
которая в темном чулане хранится
В доме, который построил Джек.
*/

int main(int arg_c, char* arg_v[])
{
	const size_t length = 256;

	int choise = 0;
	int index = 0;

	size_t rows = 7;
	size_t columns = 50;

	char string[length] = {'\0'};

	char** text = nullptr;

	text = new char* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		text[i] = new char[columns];
	}

	strcpy(text[0], "Вот дом, который построил Джек.");
	strcpy(text[1], "А это пшеница, которая в темном чулане хранится");
	strcpy(text[2], "В доме, который построил Джек.");
	strcpy(text[3], "А это веселая птица-синица,");
	strcpy(text[4], "которая часто ворует пшеницу,");
	strcpy(text[5], "которая в темном чулане хранится");
	strcpy(text[6], "В доме, который построил Джек.");

	do
	{
		system("cls");

		menu_output();
		std::cout << "select menu item: ";
		std::cin >> choise;

		switch (choise)
		{
			case 1:
				std::cout << "enter the line to be added to the end of the text: ";
				std::cin.ignore();
				std::cin.getline(string, 255);
				add_line_end(text, rows, columns, string);
				break;
			case 2:
				std::cout << "enter the line to be added to the beginning of the text: ";
				std::cin.ignore();
				std::cin.getline(string, 255);
				add_line_begin(text, rows, columns, string);
				break;
			case 3:
				std::cout << "enter the string to be added at the specified position in the text: ";
				std::cin.ignore();
				std::cin.getline(string, 255);
				RETRYCININDEX:
				std::cout << "enter the position number in the text: ";
				std::cin >> index;
				if (index < 1 || index > rows)
				{
					std::cout << "the serial number of the position was entered incorrectly" << std::endl;
					goto RETRYCININDEX;
				}
				add_line_index(text, rows, columns, string, index);
				break;
			case 4:
				if (rows)
				{
					RETRY:
					std::cout << "enter the sequence number of the deleted line: ";
					std::cin >> index;
					if (index < 1 || index > rows)
					{
						std::cout << "the serial number of the position was entered incorrectly" << std::endl;
						goto RETRY;
					}
					del_line_index(text, rows, columns, index);
				}
				else
				{
					std::cout << "the text used is empty, add some lines to it" << std::endl;
				}
				break;
			case 5:
				if (rows)
				{
					for (size_t i = 0; i < rows; ++i)
						std::cout << _convert_ANSI_string_to_ASCII_string(text[i]) << std::endl;
				}
				else
				{
					std::cout << "the text used is empty, add some lines to it" << std::endl;
				}
				break;
			case 0:
				std::cout << "the program is over" << std::endl;
				break;
			default:
				std::cout << "select the correct menu item" << std::endl;
				break;
		}
		if (choise)
			system("pause");
	} while (choise);

	for (size_t i = 0; i < rows; ++i)
		delete[] text[i];
	delete[] text;
	system("pause");
	return 0;
}
