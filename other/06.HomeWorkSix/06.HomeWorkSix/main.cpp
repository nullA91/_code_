#include "functions.h"

int main(int arg_c, char* arg_v[])
{
	const size_t size = 25;

	char symbol = '\0';

	double number_one = 0.0;
	double number_two = 0.0;
	long double result = 0;
	
	double area = 0.0;
	double first_side = 0.0;
	double second_side = 0.0;
	double third_side = 0.0;

	int range = 0;
	int array[size] = { 0 };

	int count = 0;

	int max = 0;

	int index = 0;

	std::cout << "enter the first number: ";
	std::cin >> number_one;
	std::cout << "enter the second number: ";
	std::cin >> number_two;
	std::cout << "enter operation: ";
	std::cin >> symbol;

	result = calculator(number_one, number_two, symbol);

	std::cout << "result of program execution: " << result << std::endl;

	std::cout << "enter the first side of triangle: ";
	std::cin >> first_side;
	std::cout << "enter the second side of triangle: ";
	std::cin >> second_side;
	std::cout << "enter the third side of triangle: ";
	std::cin >> third_side;

	area = triangle_area(first_side, second_side, third_side);

	if (area != -1)
		std::cout << "area of the triangle is: " << area << std::endl;
	else
		std::cout << "a triangle cannot be built" << std::endl;

	std::cout << "enter a range of values for the array: ";
	std::cin >> range;

	filling_array(array, size, range);

	count = even_numbers(array, size);

	if (even_numbers)
		std::cout << "the number of even numbers in the array: " << count << std::endl;
	else
		std::cout << "there are no even numbers in the array" << std::endl;

	max = maximum_value(array, size);

	std::cout << "maximum value in the array: " << max << std::endl;

	index = maximum_element_index(array, size);

	std::cout << "index of the maximum element in the array: " << index << std::endl;

	count = num_elem_larg_than_average_val_arr(array, size);

	std::cout << "number of elements larger than the average value of the array: " << count << std::endl;

	system("pause");
	return 0;
}