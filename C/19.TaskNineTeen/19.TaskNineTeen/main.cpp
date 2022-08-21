/*
Задание 1. Написать функцию, выводящую на экран
прямоугольник с высотой N и шириной K.
Задание 2. Написать функцию, вычисляющую факториал
переданного ей числа.
Задание 3. Написать функцию, которая проверяет, является ли переданное ей число простым? Число называется
простым, если оно делится без остатка только на себя
и на единицу.
Задание 4. Написать функцию, которая возвращает куб
числа.
Задание 5. Написать функцию для нахождения наибольшего из двух чисел.
Задание 6. Написать функцию, которая возвращает истину, если передаваемое значение положительное и ложь,
если отрицательное.

*/
#include "functions.h"

int main(int _arguments_counter, char* _arguments_value[])
{
	int exit = 0;
	int width = 0;
	int height = 0;
	
	int number = 0;
	int number_two = 0;
	// Task one
	TaskOne:
	while (std::cout << "enter height: ", std::cin >> height, std::cout << "enter width: ", std::cin >> width)
	{
		if (width < 1 || height < 1)
		{
			std::cout << "enter correct data" << std::endl;
			goto TaskOne;
		}

		output_rectangle(width, height);
		std::cout << "continue(1.yes/0.no)";
		std::cin >> exit;

		if (!exit) break;
	}
	// Task two
	TaskTwo:
	while (std::cout << "enter number: ", std::cin >> number)
	{
		if(number < 0)
		{
			std::cout << "enter correct data" << std::endl;
			goto TaskTwo;
		}

		std::cout << factorial(number) << std::endl;
		std::cout << "continue(1.yes/0.no)";
		std::cin >> exit;

		if (!exit) break;
	}
	// Task three
	TaskThree:
	while (std::cout << "enter number: ", std::cin >> number)
	{
		if (number < 1)
		{
			std::cout << "enter correct data" << std::endl;
			goto TaskThree;
		}

		if (check_number(number)) std::cout << "number is not prime" << std::endl;
		else std::cout << "prime number" << std::endl;

		std::cout << "continue(1.yes/0.no)";
		std::cin >> exit;

		if (!exit) break;
	}
	// Task four
	while (std::cout << "enter number: ", std::cin >> number)
	{
		std::cout << cube_number(number) << std::endl;

		std::cout << "continue(1.yes/0.no)";
		std::cin >> exit;

		if (!exit) break;
	}
	// Task five
	while (std::cout << "enter first number: ", std::cin >> number, std::cout << "enter second number: ", std::cin >> number_two)
	{
		std::cout << max_number(number, number_two) << std::endl;

		std::cout << "continue(1.yes/0.no)";
		std::cin >> exit;

		if (!exit) break;
	}
	// Task Six
	while (std::cout << "enter number: ", std::cin >> number)
	{
		

		if (check_number(number)) std::cout << "positive number" << std::endl;
		else std::cout << "number negative" << std::endl;

		std::cout << "continue(1.yes/0.no)";
		std::cin >> exit;

		if (!exit) break;
	}

	system("pause");
	return 0;
}