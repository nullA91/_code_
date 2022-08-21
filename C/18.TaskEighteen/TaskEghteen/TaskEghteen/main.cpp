#include <ctime>
#include <iomanip>
#include <iostream>

int main(int _arguments_counter, char* _arguments_value[])
{
	srand(time(NULL));
	// Task 1
	/*
	В двумерном массиве целых числе посчитать:
		■ Сумму всех элементов массива;
		■ Среднее арифметическое всех элементов массива;
		■ Минимальный элемент;
		■ Максимальный элемент.
	*/
	double average = 0.0;
	int sum = 0;

	int min = 0;
	int max = 0;
	// Task 2
	/*
	In a two-dimensional array of integers, calculate
	the sum of the elements: in each line; in each column;
	all rows and all columns simultaneously. For-
	like this:
				 3 5 6 7 | 21
				12 1 1 1 | 15
				0 7 12 1 | 20
				-------------
			   15 3 19 9 | 56
	*/
	const int rows = 3;
	const int columns = 4;
	const int size = 4;

	const int numbers[rows][columns] = {
										 { 3, 5, 6, 7 },
										 { 12, 1, 1, 1 },
										 { 0, 7, 12, 1 }
									   };

	int _column_sum[size] = { 0 };
	int _row_sum = 0;
	int _total_sum = 0;

	std::cout << "##### TASK TWO #####" << std::endl;

	for (size_t i = 0; i < rows; ++i)
	{
		_row_sum = 0;
		for (size_t j = 0; j < columns; ++j)
		{
			if (j < 3)
			{
				_column_sum[i] += numbers[j][i];
				if (i == 2)
				{
					_column_sum[i + 1] += numbers[j][(i + 1)];
				}
			}

			_row_sum += numbers[i][j];
			_total_sum += numbers[i][j];

			std::cout << std::setw(3) << numbers[i][j] << ' ';
		}
		std::cout << '|' << ' ' << _row_sum << std::endl;
	}

	for (size_t i = 0; i < 20; ++i)
		std::cout << '-';
	std::cout << std::endl;

	for (size_t i = 0; i < size; ++i)
		std::cout << std::setw(3) << _column_sum[i] << ' ';
	std::cout << '|' << ' ' << _total_sum << std::endl;

	for (size_t i = 0; i < 20; ++i)
		std::cout << '-';
	std::cout << '\n' << std::endl;
	//Task 3
	/*
	Write a program that declares
	a 5 × 10 array and a 5 × 5 array. First
	the array is filled with random numbers, in the range
	from 0 to 50. The second array is filled as follows
	principle: the first element of the second array is equal to the sum
	the first and second element of the first array, the second element
	cop of the second array is equal to the sum of the third and fourth
	element of the first array.
	*/
	const int row = 5;
	const int column = 10;

	int _array_one[row][column];
	int _array_two[row][row];

	int index = 0;

	std::cout << "##### TASK THREE #####" << std::endl;

	for (size_t i = 0; i < row; ++i)
	{
		for (size_t i = 0; i < row * column; ++i)
			std::cout << '-';
		std::cout << std::endl;

		for (size_t j = 0; j < column; ++j)
		{
			_array_one[i][j] = rand() % 51;
			std::cout << '|' << std::setw(3) << _array_one[i][j] << '|';
		}
		std::cout << std::endl;
	}
	for (size_t i = 0; i < row * column; ++i)
		std::cout << '-';
	std::cout << '\n' << std::endl;

	for (size_t i = 0; i < row; ++i)
	{
		index = 0;
		for (size_t j = 0; j < column; j += 2)
		{
			_array_two[i][index] = _array_one[i][j] + _array_one[i][j + 1];
			++index;
		}
	}

	for (size_t i = 0; i < row; ++i)
	{
		for (size_t i = 0; i < row * row; ++i)
			std::cout << '-';
		std::cout << std::endl;

		for (size_t j = 0; j < row; ++j)
		{
			std::cout << '|' << std::setw(3) << _array_two[i][j] << '|';
		}
		std::cout << std::endl;
	}
	for (size_t i = 0; i < row * row; ++i)
		std::cout << '-';
	std::cout << '\n' << std::endl;

	std::cout << "##### TASK ONE #####" << std::endl;

	min = _array_two[0][0];
	max = _array_two[0][0];

	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < row; ++j)
		{
			sum += _array_two[i][j];
			average += _array_two[i][j];

			if (_array_two[i][j] < min)
				min = _array_two[i][j];

			if (_array_two[i][j] > max)
				max = _array_two[i][j];
		}
	}

	average /= (row * row);

	std::cout << "sum of all elements in the array: " << sum << std::endl;
	std::cout << "arithmetic mean of all elements of the array: " << average << std::endl;
	std::cout << "minimum element: " << min << std::endl;
	std::cout << "maximum element: " << max << std::endl;

	system("pause");

	return 0;
}