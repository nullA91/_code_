#include <iostream>
#include <Windows.h>

void _console_menu_creation(const char* string, const size_t _max_length);

int main(int _arguments_counter, char* _arguments_value)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choise = 0;
	/*
	Задание 1. Пользователь вводит с клавиатуры два числа.
	Посчитать их сумму, произведение и среднее арифмети-
	ческое.
	Задание 2. Пользователь вводит с клавиатуры три числа.
	Посчитать их сумму, произведение и среднее арифмети-
	ческое.
	*/
	int _number_one = 0;
	int _number_two = 0;
	int _number_three = 0;
	/*
	Задание 3. Пользователь вводит с клавиатуры стоимость
	одного ноутбука, их количество и процент скидки. По-
	считать общую сумму заказа.
	*/
	int cost = 0;
	int amount = 0;
	int discount = 0;
	/*
	Задание 4. Зарплата менеджера — 100$ + 5% от продаж.
	Пользователь вводит с клавиатуры общую сумму сде-
	лок менеджера за месяц. Посчитать итоговую зарплату
	менеджера.
	*/
	const int salary = 100;
	int sum = 0;
	/*
	Задание 5. Пользователь вводит с клавиатуры размер од-
	ного файла в гигабайтах и скорость интернет-соединения
	в битах в секунду. Посчитать, за сколько часов, минут
	и секунд скачается фильм.
	*/
	unsigned long long size = 0;
	unsigned long long _connection_speed = 0;
	unsigned long long seconds = 0;
	unsigned long long minutes = 0;
	unsigned long long hours = 0;

	do
	{
		system("cls");
		_console_menu_creation("1. сумма, произведение и среднее арифметическое 2 -ух чмсел", 75);
		_console_menu_creation("2. сумма, произведение и среднее арифметическое 3 -ёх чмсел", 75);
		_console_menu_creation("3. расчет общей суммы заказа", 75);
		_console_menu_creation("4. расчет зарплаты", 75);
		_console_menu_creation("5. расчет времени за которое скачается фильм", 75);
		_console_menu_creation("0. выход", 10);

		std::cout << "выберите пункт меню: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			std::cout << "введите первое число: ";
			std::cin >> _number_one;
			std::cout << "введите второе число: ";
			std::cin >> _number_two;

			std::cout << "сумма двух чисел: " << _number_one + _number_two << std::endl;
			std::cout << "произведение двух чисел: " << _number_one * _number_two << std::endl;
			std::cout << "среднее арифметическое двух чисел: " << (_number_one + _number_two) / 2 << std::endl;

			break;
		case 2:
			std::cout << "введите первое число: ";
			std::cin >> _number_one;
			std::cout << "введите второе число: ";
			std::cin >> _number_two;
			std::cout << "введите третье число: ";
			std::cin >> _number_three;

			std::cout << "сумма трёх чисел: " << _number_one + _number_two + _number_three << std::endl;
			std::cout << "произведение трёх чисел: " << _number_one * _number_two * _number_three << std::endl;
			std::cout << "среднее арифметическое трёх чисел: " << (_number_one + _number_two + _number_three) / 3 << std::endl;

			break;
		case 3:
			std::cout << "введите стоимость одного ноутбука: ";
			std::cin >> cost;
			std::cout << "введите количетсво ноутбуков: ";
			std::cin >> amount;
			std::cout << "введите процент скидки: ";
			std::cin >> discount;

			std::cout << "общая сумма заказа: " << cost * amount - cost * amount / 100 * discount << std::endl;

			break;
		case 4:
			std::cout << "введите общую сумму сделок за месяц: ";
			std::cin >> sum;

			std::cout << "ваша итоговая зарплата: " << salary + sum / 100 * 5 << std::endl;

			break;
		case 5:
			// 1 гигабайт = 8589934592 бит
			std::cout << "введите размер файла в гигабайтах: ";
			std::cin >> size;
			std::cout << "введите скорость интернет соеденения Б/С: ";
			std::cin >> _connection_speed;

			size *= 8589934592;

			seconds = size / _connection_speed;
			hours = seconds / 360;
			minutes = (seconds - hours * 360) / 60;
			seconds = seconds - (hours * 360 + minutes * 60);

			std::cout << hours;

			if ((hours % 10 == 0) || (hours % 10 > 4 && hours % 10 < 10) || (hours > 10 && hours < 20))
				std::cout << " часов; ";
			else if (hours % 10 == 1)
				std::cout << " час; ";
			else if (hours % 10 > 1 && hours % 10 < 5)
				std::cout << " часа; ";

			std::cout << minutes;

			if ((minutes % 10 == 0) || (minutes % 10 > 4 && minutes % 10 < 10) || (minutes > 10 && minutes < 20))
				std::cout << " минут; ";
			else if (minutes % 10 == 1)
				std::cout << " минута; ";
			else if (minutes % 10 > 1 && minutes % 10 < 5)
				std::cout << " минуты; ";

			std::cout << seconds;

			if ((seconds % 10 == 0) || (seconds % 10 > 4 && seconds % 10 < 10) || (seconds > 10 && seconds < 20))
				std::cout << " секунд; ";
			else if (seconds % 10 == 1)
				std::cout << " секунда; ";
			else if (seconds % 10 > 1 && seconds % 10 < 5)
				std::cout << " секунды; ";

			std::cout << std::endl;

			break;
		case 0:

			std::cout << "до свидания" << std::endl;

			break;
		default:

			std::cout << "выберите правильный пункт меню" << std::endl;

			break;
		}
		system("pause");
	} while (choise);
    
	return 0;
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