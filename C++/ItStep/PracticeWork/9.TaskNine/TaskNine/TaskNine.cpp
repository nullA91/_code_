#include <cmath>
#include <iomanip>
#include <iostream>
#include <Windows.h>

int main(int _arguments_counter, char* _arguments_value[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string colors[9]{ "черный", "синий", "зеленый", "голубой", "красный", "розовый", "желтый", "белый", "серый" };

	char _background_color = '0';
	char _text_color = '0';

	char _sys_str_param[10] = "color ";
	/*
	Задание 1. Написать программу, которая по выбору
	пользователя меняет цвет консольного приложения.
	Пользователь может выбрать цвет шрифта и цвет фона.
	*/
	
	for (size_t i = 0; i < 9; i+=3)
		std::cout << i + 1 << ". " << colors[i] << '\t' << i + 2 << ". " << colors[i + 1] << '\t' << i + 3 << ". " << colors[i + 2] << std::endl;
	std::cout << "выберите цвет фона: ";
	std::cin >> _background_color;
	std::cout << "выберите цвет текста: ";
	std::cin >> _text_color;

	_sys_str_param[6] = --_background_color;
	_sys_str_param[7] = --_text_color;

	system(_sys_str_param);

	std::cout << "Hello Wolrd!" << std::endl;
	/*
	Задание 2. Написать программу, которая по выбору
	пользователя возводит введенное им число в степень от
	нулевой до седьмой включительно.
	*/
	int number = 0;

	std::cout << "введите число: ";
	std::cin >> number;

	for (size_t i = 0; i < 8; ++i)
		std::cout << i << " степень числа " << number << ": " << std::setiosflags(std::ios::right) << std::setw(10) << pow(number, i) << std::endl;
}