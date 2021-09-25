#include <ctime>
#include <iostream>
#include <new>

/*
Задание 1. Используя указатели и оператор разыменования, определить наибольшее из двух чисел.
Задание 2. Используя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры.
Задание 3. Используя указатели и оператор разыменования, обменять местами значения двух переменных.
Задание 4. Написать примитивный калькулятор, пользуясь только указателями.
Задание 5. Используя указатель на массив целых чисел, посчитать сумму элементов массива. Использовать
в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
*/

void calculator(const int* first_number, const int* second_number)
{
	std::cout << "sum of numbers is " << *first_number + *second_number << std::endl;
	std::cout << "difference of numbers is " << *first_number - *second_number << std::endl;
	std::cout << "multiplication of numbers is " << *first_number * *second_number << std::endl;
	std::cout << "a result obtained by dividing one quantity by another " << *first_number / *second_number << std::endl;
}

int main(int arg_c, char* arg_v[])
{
	srand(time(nullptr));

	const int size = 10;

	int* pointer_number = nullptr;
	int* pointer_first_number = nullptr;
	int* pointer_second_number = nullptr;
	int* pointer_array = nullptr;
	
	pointer_array = new int[size];
	for (int i = 0; i < size; ++i)
	{
		*pointer_array++ = rand() % 41 + 1;
		std::cout << "array " << i << ": " << *(pointer_array - 1) << std::endl;
	}
	pointer_array -= size;

	pointer_first_number = new int;
	pointer_second_number = new int;

	std::cout << "enter first number: ";
	std::cin >> *pointer_first_number;
	std::cout << "enter second number: ";
	std::cin >> *pointer_second_number;
	
	std::cout << "first number: " << *pointer_first_number << std::endl;
	std::cout << "second number: " << *pointer_second_number << std::endl;

	(*pointer_first_number > * pointer_second_number) ? \
	std::cout << "number " << *pointer_first_number << " is more than number " << *pointer_second_number << std::endl : \
	std::cout << "number " << *pointer_second_number << " is more than number " << *pointer_first_number << std::endl;

	pointer_number = new int;

	std::cout << "enter number: ";
	std::cin >> *pointer_number;

	(*pointer_number > -1) ? std::cout << "number sign +\n" : std::cout << "number sign -\n";

	pointer_number = pointer_first_number;
	pointer_first_number = pointer_second_number;
	pointer_second_number = pointer_number;

	std::cout << "first number: " << *pointer_first_number << std::endl;
	std::cout << "second number: " << *pointer_second_number << std::endl;

	calculator(pointer_first_number, pointer_second_number);

	*pointer_number = 0;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "array " << i << ": " << *pointer_array << std::endl;
		*pointer_number += *pointer_array++;
	}
	std::cout << "sum of all array elements: " << *pointer_number << std::endl;

	pointer_array -= size;

	delete pointer_number;
	delete pointer_first_number;
	delete [] pointer_array;

	system("pause");
	return 0;
}
