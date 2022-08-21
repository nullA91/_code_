#include "functions.h"

long double calculator(const double& number_one, const double& number_two, const char& operation)
{
	int choise = 0;

	long double result = 0.0;

	calculator_menu();

	switch (operation)
	{
		case '+':
			result = number_one + number_two;
			break;
		case '-':
			result = number_one - number_two;
			break;
		case '*':
			result = number_one * number_two;
			break;
		case '/':
			if (!number_two) abort();

			result = number_one / number_two;
			break;
		default:
			std::cout << "invalid operation character passed" << std::endl;
			break;
	}

	return result;
}

double triangle_area(const double& first_side, const double& second_side, const double& third_side)
{
	#include <cmath>

	bool start = false;

	const double divider = 2.0;

	double semi_perimeter = 0.0;
	double square = 0.0;

	start = triangle_check_existence(first_side, second_side, third_side);
	if (!start) return static_cast<signed int>(-1);

	triangle_menu();

	semi_perimeter = (first_side + second_side + third_side) / divider;

	square = sqrt( (semi_perimeter * (semi_perimeter - first_side) * (semi_perimeter - second_side) * (semi_perimeter - third_side)) );

	return square;
}

bool triangle_check_existence(const double& first_side, const double& second_side, const double& third_side)
{
	// first_side + second_side > third_side
	// first_side + third_side > second_side
	// second_side + third_side > first_side

	if (((first_side + second_side) > third_side) && ((first_side + third_side) > second_side) && ((second_side + third_side) > first_side))
		return true;
	else 
		return false;
}

void filling_array(int* array, const size_t& size, const int& range)
{
	// min + rand() % (max - min + 1);
	const int min = 0;

	for (size_t i = 0; i < size; ++i)
		array[i] = min + rand() % (range - min + 1);

	array_menu(array, size);
}

int even_numbers(const int* array, const size_t& size)
{
	int count = 0;

	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] % 2 == 0)
			++count;
	}

	return count;
}

int maximum_value(const int* array, const size_t& size)
{
	int max = 0;

	max = array[0];
	for (size_t i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}

	return max;
}

int maximum_element_index(const int* array, const size_t& size)
{
	int index = 0;
	int max = 0;
	
	max = array[0];
	for (size_t i = 1; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
			index = i;
		}
	}

	return index;
}

int average(const int* array, const size_t& size)
{
	int _average = 0;

	for (size_t i = 0; i < size; ++i)
		_average += array[i];
	_average /= size;

	return _average;
}

int num_elem_larg_than_average_val_arr(const int* array, const size_t& size)
{
	int count = 0;
	int _average = 0;

	_average = average(array, size);
	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] > _average)
			++count;
	}

	return count;
}
//////////////////////////////
void calculator_menu()
{
	const size_t space = 15;

	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < space; ++i)
	{
		std::cout << ' ';
	}
	std::cout << static_cast<char>(187) << std::endl;

	std::cout << static_cast<char>(186) << "  " << "calculator" << "   " << static_cast<char>(186) << std::endl;

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < space; ++i)
	{
		if (i == 3 || i == 7 || i == 11)
			std::cout << static_cast<char>(203);
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(185) << std::endl;

	std::cout << static_cast<char>(186) << " + ";
	std::cout << static_cast<char>(186) << " - ";
	std::cout << static_cast<char>(186) << " * ";
	std::cout << static_cast<char>(186) << " / " << static_cast<char>(186);
	std::cout << std::endl;

	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < space; ++i)
	{
		if (i == 3 || i == 7 || i == 11)
			std::cout << static_cast<char>(202);
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(188) << std::endl;
}

void triangle_menu()
{
	int iteration_left = 0;
	int iteration_right = 0;

	iteration_left = 9;
	iteration_right = 10;

	for (size_t j = 0; j < 10; ++j)
	{
		for (size_t i = 0; i < 20; ++i)
		{
			if (i == iteration_left)
			{
				std::cout << static_cast<char>(201);
			}
			else if (i == iteration_right)
			{
				std::cout << static_cast<char>(187);
				continue;
			}
			else
				std::cout << ' ';
		}
		--iteration_left;
		++iteration_right;

		std::cout << '\n';
	}

	for (size_t i = 0; i < 20; ++i)
	{
		std::cout << static_cast<char>(205);
	}
	std::cout << '\n';
}

void array_menu(const int* array, const size_t& size)
{
	const unsigned int multipple = 6;
	const unsigned int adding = 6;

	int check = 0;

	check = adding;
	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < size * multipple + adding; ++i)
	{
		if (i == check)
		{
			std::cout << static_cast<char>(203);
			check += adding;
		}
		else
		{
			std::cout << static_cast<char>(205);
		}
	}
	std::cout << static_cast<char>(187) << std::endl;

	std::cout << static_cast<char>(186) << "array:" << static_cast<char>(186);
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(5) << array[i] << static_cast<char>(186);
	}
	std::cout << std::endl;

	check = adding;
	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < size * multipple + adding; ++i)
	{
		if (i == check)
		{
			std::cout << static_cast<char>(202);
			check += adding;
		}
		else
		{
			std::cout << static_cast<char>(205);
		}
	}
	std::cout << static_cast<char>(188) << std::endl;
}