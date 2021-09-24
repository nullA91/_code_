/*
Задание 1. Создайте приложение Калькулятор. Нужно поддерживать операции +, –, *, /.
Реализовать меню без использования операторов if и switch при помощи массива указателей на функции.
##################################################################################################
##################################################################################################
##################################################################################################
Задание 2. Написать программу, которая содержит функцию, принимающую в качестве аргумента, указатели на  три
массива и размер массивов, Заносит в массив C суммы элементов массивов А и В. Размер массивов одинаковый
*/
#include <ctime>
#include <iomanip>
#include <iostream>
#include <Windows.h>

template<typename data_type>
void sum_arrays_elements(const data_type* array_one, const data_type* array_two, data_type* array_three, const size_t& size) { for (size_t i = 0; i < size; ++i) array_three[i] = array_one[i] + array_two[i]; }

template<typename data_type>
data_type sum(const data_type& number_one, const data_type& number_two) { return number_one + number_two; }

template<typename data_type>
data_type difference(const data_type& number_one, const data_type& number_two) { return number_one - number_two; }

template<typename data_type>
data_type multiplication(const data_type& number_one, const data_type& number_two) { return number_one * number_two; }

template<typename data_type>
data_type division(const data_type& number_one, const data_type& number_two) { return (number_two != 0) ? number_one / number_two : -1; }

void output_array(const char* string, const int* array, const size_t& size, const int& position);

void set_console_cursor_position(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int main(int arg_c, char* arg_v[])
{
	srand(time(NULL));

	const size_t length = 4;

	int first_number = 0;
	int second_number = 0;

	int (*pointer_functions[length])(const int&, const int&) = {sum, difference, multiplication, division};

	std::cout << "std::cin >> first_number: ";
	std::cin >> first_number;
	std::cout << "std::cin >> second_number: ";
	std::cin >> second_number;

	for (size_t i = 0; i < length; ++i)
	{
		std::cout << "result: " << pointer_functions[i](first_number, second_number) << std::endl;
	}

	const size_t size = 25;
	const int min = -1000;
	const int max = 1000;

	int array_a[size];
	int array_b[size];
	int array_c[size];

	int position = 0;

	for (size_t i = 0; i < size; ++i)
	{
		// min + rand() % (max - min);

		array_a[i] = min + rand() % (max - min);
		array_b[i] = min + rand() % (max - min);
	}

	sum_arrays_elements(array_a, array_b, array_c, size);
	
	output_array("array a", array_a, size, position);
	
	position += 13;
	output_array("array b", array_b, size, position);

	position += 13;
	output_array("array c",array_c, size, position);

	system("pause");
	return 0;
}

void output_array(const char* string, const int* array, const size_t& size, const int& position)
{
	const size_t length = strlen(string);

	int Y = 7;
	const int X = position;

	set_console_cursor_position(X, Y);

	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < length; ++i)
	{
		if (i % 2 == 0)
			std::cout << ' ';
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187);
	std::cout << '\n';

	++Y;
	set_console_cursor_position(X, Y);

	std::cout << ' ' << string << '\n';
	
	++Y;
	set_console_cursor_position(X, Y);
	
	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < length; ++i)
	{
		if (i % 2 == 0)
			std::cout << ' ';
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);
	std::cout << '\n';

	++Y;
	set_console_cursor_position(X, Y);

	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < length; ++i)
	{
		if (i % 2 == 0)
			std::cout << ' ';
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187);
	std::cout << '\n';

	++Y;
	set_console_cursor_position(X, Y);

	for (size_t i = 0; i < size; ++i)
	{
		std::cout << static_cast<char>(186);
		std::cout << std::setw(length) << array[i];
		std::cout << static_cast<char>(186);
		std::cout << '\n';

		if (i < size - 1)
		{
			++Y;
			set_console_cursor_position(X, Y);
			for (size_t j = 0; j < length + 1; ++j)
			{
				if (j % 2 != 0)
					std::cout << static_cast<char>(205);
				else
					std::cout << ' ';
			}

			++Y;
		}
		else
			--Y;
		set_console_cursor_position(X, Y);
	}
	std::cout << '\n';

	set_console_cursor_position(X, Y);

	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < length; ++i)
	{
		if (i % 2 == 0)
			std::cout << ' ';
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);
	std::cout << '\n';
}

/*
void output_array(const char* string, const int* array, const size_t& size, const int& position)
{
	const size_t length = strlen(string);

	int Y = 7;
	const int X = position;

	set_console_cursor_position(X, Y);

	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < length; ++i)
	{
		if (i % 2 == 0)
			std::cout << ' ';
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187);
	std::cout << '\n';

	++Y;
	set_console_cursor_position(X, Y);

	std::cout << ' ' << string << '\n';

	++Y;
	set_console_cursor_position(X, Y);

	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < length; ++i)
	{
		if (i % 2 == 0)
			std::cout << ' ';
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);
	std::cout << '\n';

	++Y;
	set_console_cursor_position(X, Y);

	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < length; ++i)
	{
		if (i % 2 == 0)
			std::cout << ' ';
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(187);
	std::cout << '\n';

	++Y;
	set_console_cursor_position(X, Y);

	for (size_t i = 0; i < size; ++i)
	{
		std::cout << static_cast<char>(186);
		std::cout << std::setw(length) << array[i];
		std::cout << static_cast<char>(186);

		if (i < size - 1)
			Y += 2;
		else
			--Y;
		set_console_cursor_position(X, Y);
	}
	std::cout << '\n';

	set_console_cursor_position(X, Y);

	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < length; ++i)
	{
		if (i % 2 == 0)
			std::cout << ' ';
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188);
	std::cout << '\n';
}
*/
