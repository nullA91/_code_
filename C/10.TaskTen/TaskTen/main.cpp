#include <iostream>
#include <Windows.h>

int main(int _arguments_counter, char* _arguments_value[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int _start_range = 0;
	int _end_range = 0;
	int counter = 0;
	int _temporary_variable = 0;
	int sum = 0;

	// Задание 1. Вывести на экран все числа от нуля до введенного пользователем числа.
	std::cout << "введите конец диапазона: ";
	std::cin >> _end_range;

	std::cout << "\nдиапазон чисел: ";
	if (!_end_range)
		std::cout << _end_range << std::endl;
	else if (_end_range < 0)
		while (_start_range != _end_range - 1)
			std::cout << _start_range-- << ' ';
	else
		while (_start_range != _end_range + 1)
			std::cout << _start_range++ << ' ';
	std::cout << std::endl;
	/*
	Задание 2. Пользователь вводит две границы диапазона,
	вывести на экран все числа из этого диапазона. Преду-
	смотреть, чтобы пользователь мог вводить границы ди-
	апазона в произвольном порядке.
	■ вывести все четные числа из диапазона.
	■ вывести все нечетные числа из диапазона.
	■ вывести все числа, кратные семи.
	*/
TryAgainTaskTwo:
	std::cout << "введите начальную границу диапазона: ";
	std::cin >> _start_range;
	std::cout << "введите конечную границу диапазона: ";
	std::cin >> _end_range;

	_temporary_variable = _start_range;

	if (_end_range < _start_range)
	{
		std::cout << "конечная граница диапазона, меньше начальной!" << std::endl;
		goto TryAgainTaskTwo;
	}

	else
	{
	TryTask:
		if (!counter)
		{
			std::cout << "\nдиапазон чисел: ";
			while (_start_range < _end_range + 1)
				std::cout << _start_range++ << ' ';
		}
		else if (counter == 1)
		{
			std::cout << "\nчетные числа из диапазона: ";
			while (_start_range < _end_range + 1)
			{
				if (!(_start_range % 2))
					std::cout << _start_range << ' ';
				++_start_range;
			}
		}
		else if (counter == 2)
		{
			std::cout << "\nнечетные числа из диапазона: ";
			while (_start_range < _end_range + 1)
			{
				if (_start_range % 2)
					std::cout << _start_range << ' ';
				++_start_range;
			}
		}
		else if (counter == 3)
		{
			std::cout << "\nчисла из диапазона кратные семи: ";
			while (_start_range < _end_range + 1)
			{
				if (!(_start_range % 7))
					std::cout << _start_range << ' ';
				++_start_range;
			}
		}
		// Задание 3. Пользователь вводит две границы диапазона. Посчитать сумму всех чисел диапазона.
		else if (counter == 4)
		{
			while (_start_range < _end_range + 1)
				sum += _start_range++;

			std::cout << "\nсумма всех чисел диапазона: " << sum;
		}
	}
	std::cout << std::endl;
	++counter;
	_start_range = _temporary_variable;

	if (counter < 5) goto TryTask;
	/*
	Задание 4. Пользователь с клавиатуры вводит числа.
	Посчитать их сумму и вывести на экран, как только поль-
	зователь введет ноль.
	*/
	sum = 0;
	_temporary_variable = 1;

	while (_temporary_variable != 0)
	{
		std::cout << "введите число: ";
		std::cin >> _temporary_variable;

		sum += _temporary_variable;

		std::cout << "продолжить 1.да/0.нет ? ";
		std::cin >> _temporary_variable;
	}

	std::cout << "\nсумма введенных чисел: " << sum << std::endl;

	return 0;
}