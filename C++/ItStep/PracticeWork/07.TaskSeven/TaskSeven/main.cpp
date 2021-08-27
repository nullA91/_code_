#include <iostream>
#include <Windows.h>

int main(int _arguments_counter, char* _arguments_value)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number = 0;
	int _number_one = 0;
	int _number_two = 0;
	// Задание 1. Пользователь вводит число. Определить, является ли оно четным.
	std::cout << "введите число: ";
	std::cin >> number;

	if (number % 2 == 0)
		std::cout << "число чётное" << std::endl;
	else
		std::cout << "число нечётное" << std::endl;
	// Задание 2. Пользователь вводит два числа. Вывести на экран меньшее из этих чисел.
	std::cout << "введите первое число: ";
	std::cin >> _number_one;
	std::cout << "введите второе число: ";
	std::cin >> _number_two;

	if (_number_one > _number_two)
		std::cout << "число " << _number_one << " больше " << _number_two << std::endl;
	else if (_number_two > _number_one)
		std::cout << "число " << _number_two << " больше " << _number_one << std::endl;
	else
		std::cout << "числа равны" << std::endl;
	/*
	Задание 3. Пользователь вводит число. Определить, по-
	ложительное это число, отрицательное или равно нулю.
	*/
	std::cout << "введите число: ";
	std::cin >> number;

	if (number > 0)
		std::cout << "число положительное" << std::endl;
	else if (number < 0)
		std::cout << "число отрицательное" << std::endl;
	else
		std::cout << "число равно нулю" << std::endl;
	/*
	Задание 4. Пользователь вводит два числа. Определить,
	равны ли эти числа, и если нет, вывести их на экран в по-
	рядке возрастания.
	*/
	std::cout << "введите первое число: ";
	std::cin >> _number_one;
	std::cout << "введите второе число: ";
	std::cin >> _number_two;

	if (_number_one != _number_two)
		(_number_one > _number_two) ?
		std::cout << _number_one << ' ' << _number_two << std::endl
		: std::cout << _number_two << ' ' << _number_one << std::endl;

	return 0;
}
