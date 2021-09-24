#include <cstring>
#include <iostream>
#include <Windows.h>
/*
Есть некоторый текст. Используя стандартные строковые функции:
■ Посчитайте количество вхождений слово, заданного пользователем;
■ Посчитайте количество предложений в тексте;
■ Количество точек и запятых;
■ Переверните весь текст целиком;
■ Переверните каждое предложение в тексте.
*/



/*
Вот дом, который построил Джек.
А это пшеница, которая в темном чулане хранится
В доме, который построил Джек.
А это веселая птица-синица,
которая часто ворует пшеницу,
которая в темном чулане хранится
В доме, который построил Джек.
*/

static unsigned short index = 0;

std::string return_word(const std::string& string);

int main(int arg_c, char* arg_v[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const size_t size = 7;

	std::string text[size]
	{
		"Вот дом, который построил Джек.",
		"А это пшеница, которая в темном чулане хранится.",
		"В доме, который построил Джек.",
		"А это веселая птица - синица,",
		"которая часто ворует пшеницу,",
		"которая в темном чулане хранится.",
		"В доме, который построил Джек."
	};

	unsigned short choise = 0;

	do
	{
		system("cls");

		std::cout << "\tменю\n";
		std::cout << "1. подсчет количества слова заданного пользователем в тексте\n";
		std::cout << "2. подсчет количества предложений в тексте\n";
		std::cout << "3. подсчет количества точек и запятых в тексте\n";
		std::cout << "4. реверсия текста\n";
		std::cout << "5. реверсия каждого предложения в тексте\n";
		std::cout << "0. выход\n";
		std::cin >> choise;

		switch (choise)
		{
			case 1:
			{
				short counter = 0;

				//std::string string = "";
				std::string word = "";
				//std::string _text_word = "";

				if (!text->size())
				{
					std::cout << "выбранный текст пустой" << std::endl;
					break;
				}

				std::cout << "введите слово: ";
				std::cin >> word;

				for (size_t i = 0; i < size; ++i)
				{
					for (size_t j = 0; j < text[i].size(); ++j)
					{
						if (!strcmp(word.c_str(), return_word(text[i]).c_str()))
							++counter;
					}
					index = 0;
				}

				if (counter)
					std::cout << "количество слова введенного пользоватем в тексте: " << counter << std::endl;
				else
					std::cout << "в тексте отсутствует введенное пользователем слово" << std::endl;

				break;
			}
			case 2:
			{
				short counter = 0;

				if (!text->size())
				{
					std::cout << "выбранный текст пустой" << std::endl;
					break;
				}

				for (size_t i = 0; i < size; ++i)
				{
					if ( strchr(text[i].c_str(), '.') || strchr(text[i].c_str(), '?') || strchr(text[i].c_str(), '!') )
						++counter;
				}

				std::cout << "количество предложений в тексте: " << counter << std::endl;

				break;
			}
			case 3:
			{
				short counter_point = 0;
				short counter_comma = 0;

				if (!text->size())
				{
					std::cout << "выбранный текст пустой" << std::endl;
					break;
				}

				for (size_t i = 0; i < size; ++i)
				{
					if (strchr(text[i].c_str(), '.'))
						++counter_point;
					if (strchr(text[i].c_str(), ','))
						++counter_comma;
				}

				std::cout << "количество точек в тексте: " << counter_point << std::endl;
				std::cout << "количество запятых в тексте: " << counter_comma << std::endl;

				break;
			}
			case 4:
			{
				if (!text->size())
				{
					std::cout << "выбранный текст пустой" << std::endl;
					break;
				}

				for (int i = size - 1; i >= 0; --i)
				{
					for (int j = strlen(text[i].c_str()); j >= 0; --j)
					{
						std::cout << text[i][j];
					}
					std::cout << std::endl;
				}

				break;
			}
			case 5:
			{
				if (!text->size())
				{
					std::cout << "выбранный текст пустой" << std::endl;
					break;
				}

				std::cout << std::endl;
				for (int i = size - 1; i >= 0; --i)
					std::cout << text[i] << std::endl;
				std::cout << std::endl;

				break;
			}
			
			case 0:
				std::cout << "программа завершена\n";
				break;

			default:
				std::cout << "выберите правильный пункт меню\n";
				break;
		}
		if(choise)
			system("pause");
	}while (choise);

	system("pause");
	return 0;
}

std::string return_word(const std::string& string)
{
	std::string word = "";

	for (; index < string.size(); ++index)
	{
		if ((string[index] >= 'А' && string[index] <= 'Я') || (string[index] >= 'а' && string[index] <= 'я'))
		{
			word += string[index];
			++index;
			while ((string[index] >= 'А' && string[index] <= 'Я') || (string[index] >= 'а' && string[index] <= 'я'))
			{
				word += string[index];
				++index;
			}
			break;
		}
	}

	return word;
}