#include <cmath>
#include <iostream>
#include <Windows.h>

int main(int _arguments_counter, char* _arguments_value[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*
	Задание 1. Пользователь вводит с клавиатуры время
	в секундах, прошедшее с начала дня. Вывести на экран
	текущее время в часах, минутах и секундах. Посчитать,
	сколько часов, минут и секунд осталось до полуночи.
	*/

	int temp = 0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
	int midnight = 0;

TryAgain:
	std::cout << "введите время в секундах(максимальное значение 86400): " << std::endl;
	std::cin >> temp;

	if (temp > 86400)
		goto TryAgain;

	hours = temp / 60 / 60;
	minutes = (temp - hours * 60 * 60) / 60;
	seconds = temp - (hours * 60 * 60 + minutes * 60);

	if (temp > 60)
	{
		std::cout << "введенное время: ";
		// часы
		if (hours > 10 && hours < 20)
			std::cout << hours << " часов; ";
		else if (hours % 10 == 1)
			std::cout << hours << " час; ";
		else if (hours % 10 == 2 || hours % 10 == 3 || hours % 10 == 4)
			std::cout << hours << " часа; ";
		else
			std::cout << hours << " часов; ";
		// минуты
		if (minutes > 10 && minutes < 20)
			std::cout << minutes << " минут; ";
		else if (minutes % 10 == 1)
			std::cout << minutes << " минута; ";
		else if (minutes % 10 == 2 || minutes % 10 == 3 || minutes % 10 == 4)
			std::cout << minutes << " минуты; ";
		else
			std::cout << minutes << " минут; ";
		// секунды
		if (seconds > 10 && seconds < 20)
			std::cout << seconds << " секунд." << std::endl;
		else if (seconds % 10 == 1)
			std::cout << seconds << " секунда." << std::endl;
		else if (seconds % 10 == 2 || seconds % 10 == 3 || seconds % 10 == 4)
			std::cout << seconds << " секунды." << std::endl;
		else
			std::cout << seconds << " секунд." << std::endl;
	}
	else
	{
		std::cout << "введенное в ремя: " << 0 << " часов; " << 0 << " минут; ";
		// секунды
		if (temp > 10 && temp < 20)
			std::cout << temp << " секунд." << std::endl;
		else if (temp % 10 == 1)
			std::cout << temp << " секунда." << std::endl;
		else if (temp % 10 == 2 || temp % 10 == 3 || temp % 10 == 4)
			std::cout << temp << " секунды." << std::endl;
		else
			std::cout << temp << " секунд." << std::endl;
	}

	midnight = 24 * 60 * 60 - temp;

	hours = midnight / 60 / 60;
	minutes = (midnight - hours * 60 * 60) / 60;
	seconds = midnight - (hours * 60 * 60 + minutes * 60);

	std::cout << "до полуночи осталось: ";
	// часы
	if (hours > 10 && hours < 20)
		std::cout << hours << " часов; ";
	else if (hours % 10 == 1)
		std::cout << hours << " час; ";
	else if (hours % 10 == 2 || hours % 10 == 3 || hours % 10 == 4)
		std::cout << hours << " часа; ";
	else
		std::cout << hours << " часов; ";
	// минуты
	if (minutes > 10 && minutes < 20)
		std::cout << minutes << " минут; ";
	else if (minutes % 10 == 1)
		std::cout << minutes << " минута; ";
	else if (minutes % 10 == 2 || minutes % 10 == 3 || minutes % 10 == 4)
		std::cout << minutes << " минуты; ";
	else
		std::cout << minutes << " минут; ";
	// секунды
	if (seconds > 10 && seconds < 20)
		std::cout << seconds << " секунд." << std::endl;
	else if (seconds % 10 == 1)
		std::cout << seconds << " секунда." << std::endl;
	else if (seconds % 10 == 2 || seconds % 10 == 3 || seconds % 10 == 4)
		std::cout << seconds << " секунды." << std::endl;
	else
		std::cout << seconds << " секунд." << std::endl;

	/*
	Задание 2. Пользователь вводит с клавиатуры диаметр
	окружности. Посчитать площадь и периметр окружности.
	*/
	const float PI = 3.14;
	
	float perimeter = 0;
	float square = 0;
	float diameter = 0;

	std::cout << "введите диаметр окружности: ";
	std::cin >> diameter;

	square = std::pow(diameter, 2) / 4 * PI;
	perimeter = PI * diameter;

	std::cout << "площадь окружности: " << square << " см." << std::endl;
	std::cout << "периметр окружности: " << perimeter << " см." << std::endl;

	return 0;
}
/*
if (temp > 60)
	std::cout << "введенное в ремя: " << hours << " часов; " << minutes << " минут; " << seconds << " секунд." << std::endl;
else
	std::cout << "введенное в ремя: " << 0 << " часов; " << 0 << " минут; " << temp << " секунд." << std::endl;
*/
///////////////////////////////////////////////////////////////////////
/*
if (temp > 60)
	std::cout << "до полуночи осталось: " << hours << " часов; " << minutes << " минут; " << seconds << " секунд." << std::endl;
else
	std::cout << "до полуночи осталось: " << 0 << " часов; " << 0 << " минут; " << midnight - temp << " секунд." << std::endl;
*/
