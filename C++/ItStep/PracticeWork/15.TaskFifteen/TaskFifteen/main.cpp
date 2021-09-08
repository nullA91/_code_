#include <array>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

static int counter = 0;

void _creat_menu(std::string _menu_string);

int main(int _arguments_counter, char* _arguments_value[])
{
	srand(time(NULL));

	int _temp_var = 0;
	int _temp_var_min = 0;
	int _temp_var_max = 0;
	int choise = 0;
	double sum = 0;
	int _index_min = 0;
	int _index_max = 0;

	const char month[12][10] { "january", "febrary", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

	double _half_year_profit[6]{ 0.0 };
	int array[10]{ 0 };
	int _array_pentagon_sides[5];
	std::array<double, 12> _year_profit{ 0.0 };
	
	do
	{
		counter = 0;

		std::system("cls");
		//std::system("clear"); // linux

		_creat_menu("calculation of the firm's profit for six months ");
		_creat_menu("outputting the array in reverse order ");
		_creat_menu("calculating the perimeter of a pentagon ");
		_creat_menu("calculation of the maximum and minimum profit of the company for the year ");
		_creat_menu("exit ");
		std::cout << "\nchoose operation: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			/*
	З       Задание 1. Написать, программу, которая вычисляет при-
			быль фирмы за 6 месяцев. Пользователь вводит прибыль
			фирмы за каждый месяц.
			*/
			sum = 0;

			for (size_t i = 0; i < 6; ++i)
			{
				std::cout << "enter profit for the " << i + 1 << " month: ";
				std::cin >> _half_year_profit[i];
				sum += _half_year_profit[i];
			}

			std::cout << "profit of the company for the six month: " << sum << " $" << std::endl;

			break;
		case 2:
			/*
			Задание 2. Написать программу, которая выводит одно-
			мерный массив в обратном порядке.
			*/
			for (size_t i = 0; i < 10; ++i)
				array[i] = rand() % 500 + 1;

			std::cout << "\tarray in its original form" << std::endl;
			for (size_t i = 0; i < 50 + 1; ++i)
				std::cout << '-';
			std::cout << "\n|";

			for (size_t i = 0; i < 10; ++i)
				std::cout << std::setw(4) << array[i] << '|';
			std::cout << std::endl;

			for (size_t i = 0; i < 50 + 1; ++i)
				std::cout << '-';
			std::cout << std::endl;

			std::cout << "\tarray in reverse order" << std::endl;
			for (size_t i = 0; i < 50 + 1; ++i)
				std::cout << '-';
			std::cout << "\n|";

			for (size_t i = 0, j = 9; i < 5; ++i, --j)
			{
				_temp_var = array[i];
				array[i] = array[j];
				array[j] = _temp_var;
			}

			for (size_t i = 0; i < 10; ++i)
				std::cout << std::setw(4) << array[i] << '|';
			std::cout << std::endl;

			for (size_t i = 0; i < 50 + 1; ++i)
				std::cout << '-';
			std::cout << std::endl;

			break;
		case 3:
			/*
			Задание 3. Пользователь вводит длину сторон пятиуголь-
			ника, каждая сторона заноситься в массив, необходимо
			вычислить периметр пятиугольника (периметр — сумма
			всех сторон).
			*/
			sum = 0;

			for (size_t i = 0; i < 5; ++i)
			{
				std::cout << "enter " << i + 1 << " side of the pentagon: ";
				std::cin >> _array_pentagon_sides[i];
				sum += _array_pentagon_sides[i];
			}

			std::cout << "the perimeter of the pentagon is: " << sum << std::endl;

			break;
		case 4:
			/*
			Задание 4. Пользователь вводит прибыль фирмы за год
			(12 месяцев). Необходимо определить месяц, в котором
			прибыль была максимальна и месяц, в котором прибыль
			была минимальна.
			*/
			sum = 0;

			for (size_t i = 0; i < 12; ++i)
			{
				std::cout << "enter profit for " << month[i] << ": ";
				std::cin >> _year_profit[i];
				sum += _year_profit[i];
			}

			_index_min = 0;
			_index_max = 0;
			_temp_var_min = _year_profit[0];
			_temp_var_max = _year_profit[0];

			for (size_t i = 0, j = 11; i < 6; ++i, --j)
			{
				// нахождение месяца в котором у фирмы была минимальная прибыль 
				if (_year_profit[i] < _year_profit[j] && _year_profit[i] < _temp_var_min)
				{
					_temp_var_min = _year_profit[i];
					_index_min = i;
				}
				else if (_year_profit[j] < _year_profit[i] && _year_profit[j] < _temp_var_min)
				{
					_temp_var_min = _year_profit[j];
					_index_min = j;
				}
				// нахождение месяца в котором у фирмы была максимальная прибыль
				if (_year_profit[i] > _year_profit[j] && _year_profit[i] > _temp_var_max)
				{
					_temp_var_max = _year_profit[i];
					_index_max = i;
				}
				else if (_year_profit[j] > _year_profit[i] && _year_profit[j] > _temp_var_max)
				{
					_temp_var_max = _year_profit[j];
					_index_max = j;
				}
			}

			std::cout << "profit of the company for the year: " << sum << " $" << std::endl;
			std::cout << "month in which the firm receives the minimum profit: " << month[_index_min] << std::endl;
			std::cout << "month in which the company receives the maximum profit: " << month[_index_max] << std::endl;

			break;
		default:
			std::cout << "choose the correct operation number" << std::endl;
			break;
		}
		if (choise != 5)
		{
			std::cout << "continue(1.yes/0.no): ";
			std::cin >> choise;
		}
		else
			choise = 5;
		if (!choise) choise = 5;
	} while (choise != 5);

	return 0;
}

void _creat_menu(std::string _menu_string)
{
	int size = _menu_string.size();
	++counter;

	// создание строки меню
	for (size_t i = 0; i < size + 6; ++i)
		std::cout << '-';
	std::cout << "\n| " << counter << ". ";
	std::cout << std::setw(size) << _menu_string;
	std::cout << "|\n";
	//std::cout << ' ';
	for (size_t i = 0; i < size + 6; ++i)
		std::cout << '-';
	std::cout << std::endl;
}
