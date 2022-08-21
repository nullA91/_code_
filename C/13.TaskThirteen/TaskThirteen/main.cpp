#include <ctime>
#include <iostream>
#include <Windows.h>

int main(int _argumnents_counter, char* _argments_value[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	rand();
	/*
	Задание 1. Написать программу, которая проверяет поль-
	зователя на знание таблицы умножения. Программа вы-
	водит на экран два числа, пользователь должен ввести их
	произведение. Разработать несколько уровней сложности
	(отличаются сложностью и количеством вопросов). Вы-
	вести пользователю оценку его знаний.
	*/
	int _attempt_numbers = 0;
	int _correct_answer = 0;

	int _number_one = 0;
	int _number_two = 0;
	int _number_three = 0;
	int _number_four = 0;

	int _product_numbers = 0;

	int choise = 0;

RETRY:

	system("cls");

	std::cout << "\tуровень сложности\n";
	std::cout << "1. легкий\n";
	std::cout << "2. обычный\n";
	std::cout << "3. тяжелый\n";
	std::cout << "выберите уровень сложности: ";
	std::cin >> choise;

	switch (choise)
	{
	case 1:
		_number_one = rand() % 9 + 1;
		_number_two = rand() % 9 + 1;

		std::cout << "введите произведение " << _number_one << " * " << _number_two << ": ";
		std::cin >> _product_numbers;

		++_attempt_numbers;

		if (_number_one * _number_two == _product_numbers)
			++_correct_answer;
		break;
	case 2:
		_number_one = rand() % 9 + 1;
		_number_two = rand() % 9 + 1;
		_number_three = rand() % 9 + 1;

		std::cout << "введите произведение " << _number_one << " * " << _number_two << " * " << _number_three << ": ";
		std::cin >> _product_numbers;

		++_attempt_numbers;

		if (_number_one * _number_two * _number_three == _product_numbers)
			++_correct_answer;
		break;
	case 3:
		_number_one = rand() % 9 + 1;
		_number_two = rand() % 9 + 1;
		_number_three = rand() % 9 + 1;
		_number_four = rand() % 9 + 1;

		std::cout << "введите произведение " << _number_one << " * " << _number_two << " * " << _number_three << " * " << _number_four << ": ";
		std::cin >> _product_numbers;

		++_attempt_numbers;

		if (_number_one * _number_two * _number_three * _number_four == _product_numbers)
			++_correct_answer;
		break;
	default:
		std::cout << "правильно выберите уровень сложности" << std::endl;
		break;
	}

	std::cout << "продолжить(1.да/0.нет): ";
	std::cin >> choise;

	if (choise) goto RETRY;

	std::cout << "количество правильных ответов: " << _correct_answer << std::endl;
	std::cout << "количество попыток: " << _attempt_numbers << std::endl;

	/*Задание 2. Вывести на экран ромб из звездочек.*/
	int dicriment = 0;

	int length = 20;

	for (size_t i = 0; i < length / 2; ++i)
	{
		for (size_t j = 0; j < length; ++j)
		{
			if (j == (length - 1) / 2 - dicriment || j == (length - 1) / 2 + dicriment)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
		++dicriment;
	}
	dicriment = 1;
	for (size_t i = 0; i < length / 2 - 1; ++i)
	{
		for (size_t j = 0; j < length; ++j)
		{
			if (j == dicriment || j == (length - 2) - dicriment)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
		++dicriment;
	}

	return 0;
}
