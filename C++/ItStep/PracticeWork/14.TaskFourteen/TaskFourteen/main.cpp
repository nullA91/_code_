#include <cstring>
#include <iostream>
#include <string>

int main(int _arguments_counter, char* _arguments_value[])
{
	const char colors[9][15] { "black", "dark blue", "green", "light blue", "red", "purple", "yellow", "white", "gray" };

	int width = 0;
	int height = 0;
	char symbol = '0';

	const int _color_size = 3;
	const int _string_parameter_size = 10;

	char _string_parameter[_string_parameter_size] = "color ";
	char color[_color_size] = "07";

	/*
	Задание 1. Вывести на экран прямоугольник с заданными
	сторонами заданным символом.
	*/
	RetryEnterWidth:
	std::cout << "enter the width of the rectangle: ";
	std::cin >> width;
	if (width < 1) 
		goto RetryEnterWidth;
	RetryEnterHeight:
	std::cout << "enter the height of the rectangle: ";
	std::cin >> height;
	if (height < 1) 
		goto RetryEnterHeight;

	std::cout << "enter fill character: ";
	std::cin >> symbol;

	for (size_t j = 0; j < height; ++j)
	{
		for (size_t i = 0; i < width; ++i)
			std::cout << symbol;
		std::cout << std::endl;
	}
	/*
	Задание 2. Вывести на экран пустой прямоугольник
	с заданными размерами заданным символом заданного
	цвета.
	*/
	REW:
	std::cout << "enter the width of the rectangle: ";
	std::cin >> width;
	if (width < 1) 
		goto REW;
	
	REH:
	std::cout << "enter the height of the rectangle: ";
	std::cin >> height;
	if (height < 1)
		goto REH;

	// цвет фона
	system("cls");
	for (size_t i = 0; i < 9; ++i)
		std::cout << i + 1 << ". " << colors[i] << std::endl;
	std::cout << "\tselect background color: ";
	std::cin >> symbol;
	color[0] = symbol - 1;

	// цвет текста
	for (size_t i = 0; i < 9; ++i)
		std::cout << i + 1 << ". " << colors[i] << std::endl;
	std::cout << "\tselect text color: ";
	std::cin >> symbol;
	color[1] = symbol - 1;
	color[2] = '\0';

	strcat_s(_string_parameter, color);

	std::cout << "enter fill character: ";
	std::cin >> symbol;

	system(_string_parameter);

	for (size_t j = 0; j < height; ++j)
	{
		if (j == 0 || j == height - 1)
		{
			for (size_t i = 0; i < width; ++i)
				std::cout << symbol;
			std::cout << std::endl;
		}
		else if (j > 0 && j < height - 1)
		{
			std::cout << symbol;
			for (size_t i = 1; i < width - 1; ++i)
				std::cout << ' ';
			std::cout << symbol << std::endl;
		}
	}

	return 0;
}
