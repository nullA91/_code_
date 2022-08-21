//#include <ctime>
#include <iostream>
#include <Windows.h>

int main(int arguments_counter, char* _arguments_value[])
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*
	Задание 1. Пользователь с клавиатуры вводит 5 оценок
	студента. Определить, допущен ли студент к экзамену.
	Студент получает допуск, если его средний балл 4 балла
	и выше.
	*/
	int grade = 0;
	int sum = 0;
	int counter = 0;

	while (counter < 5)
	{
		if (counter != 2)
			std::cout << "введите " << counter + 1 << " -ую оценку студента: ";
		else
			std::cout << "введите " << counter + 1 << " -юю оценку студента: ";
		std::cin >> grade;
		sum += grade;
		++counter;
	}

	if (sum / 5 >= 4)
		std::cout << "студент допущен к экзамену" << std::endl;
	else
		std::cout << "студент не допущен к экзамену" << std::endl;
	/*
	Задание 2. Пользователь вводит с клавиатуры число. Если
	оно четное, умножить его на три, иначе — поделить на
	два. Результат вывести на экран.
	*/
	int number = 0;

	std::cout << "введите число: ";
	std::cin >> number;

	if (number % 2 == 0)
		std::cout << "результат: " << number * 3 << std::endl;
	else
		std::cout << "результат: " << number / 2 << std::endl;
	/*
	Задание 3. Написать программу-калькулятор. Пользователь
	вводит два числа и выбирает арифметическое действие.
	Вывести на экран результат.
	*/
	int _number_one = 0;
	int _number_two = 0;

	int choise = 0;

	do
	{
		system("cls");
		std::cout << "введите первое число: ";
		std::cin >> _number_one;
		std::cout << "введите второе число: ";
		std::cin >> _number_two;

		std::cout << "\tменю\n";
		std::cout << "1. умножить\n";
		std::cout << "2. делить\n";
		std::cout << "3. сложить\n";
		std::cout << "4. вычесть\n";
		std::cout << "0. выход\n";

		std::cout << "выберите пункт меню: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			std::cout << "результат: " << _number_one * _number_two << std::endl;
			break;
		case 2:
			std::cout << "результат: " << _number_one / _number_two << std::endl;
			break;
		case 3:
			std::cout << "результат: " << _number_one + _number_two << std::endl;
			break;
		case 4:
			std::cout << "результат: " << _number_one - _number_two << std::endl;
			break;
		case 0:
			std::cout << "null" << std::endl;
			break;
		default:
			std::cout << "выберите правильный пункт меню" << std::endl;
			break;
		}
		system("pause");
	} while (choise);

	return 0;
}

/*
	srand(time(nullptr));

	int _number_one = 0, _number_two = 0, _number_three = 0;
	int min = 0;
	int max = 0;

	std::cout << "введите три числа: ";
	std::cin >> _number_one >> _number_two >> _number_three;

	_number_one = rand() % 99 + 1;
	_number_two = rand() % 99 + 1;
	_number_three = rand() % 99 + 1;

	std::cout << "числа: " << _number_one << ' ' << _number_two << ' ' << _number_three << std::endl;

	(_number_one > _number_two) ? (_number_one > _number_three) ? max = _number_one : max = _number_three : (_number_two > _number_three) ? max = _number_two : max = _number_three;
	(_number_one < _number_two) ? (_number_one < _number_three) ? min = _number_one : min = _number_three : (_number_two < _number_three) ? min = _number_two : min = _number_three;

	std::cout << "минимальный элемент: " << min << std::endl;
	std::cout << "максимальный элемет: " << max << std::endl;


	int age;

	std::cout << "введите сколько вам лет: ";
	std::cin >> age;

	if (age == 1)
		std::cout << "вам " << age << " год" << std::endl;
	else if (age == 2 || age == 3 || age == 4)
		std::cout << "вам " << age << " года" << std::endl;
	else if (age == 0 || age > 4 && age < 20)
		std::cout << "вам " << age << " лет" << std::endl;

	if (age > 19 && age < 100)
	{
		if (age % 10 == 1)
			std::cout << "вам " << age << " год" << std::endl;
		else if (age % 10 == 2 || age % 10 == 3 || age % 10 == 4)
			std::cout << "вам " << age << " года" << std::endl;
		else if (age % 10 == 0 || age % 10 > 4 && age % 10 < 10)
			std::cout << "вам " << age << " лет" << std::endl;
	}

	if (age > 99 && age < 1000)
	{
		if(age % 100 > 10 && age % 100 < 20)
			std::cout << "вам " << age << " лет" << std::endl;
		else if (age % 10 == 1)
			std::cout << "вам " << age << " год" << std::endl;
		else if (age % 10 == 2 || age % 10 == 3 || age % 10 == 4)
			std::cout << "вам " << age << " года" << std::endl;
		else if (age % 10 == 0 || age % 10 > 4 && age % 10 < 10)
			std::cout << "вам " << age << " лет" << std::endl;
	}
*/
