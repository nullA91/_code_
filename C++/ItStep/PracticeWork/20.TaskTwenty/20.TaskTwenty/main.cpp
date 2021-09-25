#include <ctime>
#include <iostream>
#include <utility>
/*
Задание 1. Написать функцию, определяющую минимум и максимум (значение и номер) элементов передаваемого ей массива.
Задание 2. Написать функцию, меняющую порядок следования элементов передаваемого ей массива на противоположный.
Задание 3. Написать функцию, возвращающую количество простых чисел в передаваемом ей массиве.
*/

template<typename data_type>
std::pair<std::pair<data_type, int>, std::pair<data_type, int>> array_min_max(const data_type* array, const int size);

template<typename data_type>
void array_reverse(data_type* array, const int size);

int prime_number_counter(const int* array, const int size);

int main(int arg_c, char* arg_v[])
{
	srand(time(NULL));

	std::pair<std::pair<int, int>, std::pair<int, int>> array_values;

	const int size = 10;

	int array[size]{ 0 };

	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 1001 + 1;
	}

	array_values = array_min_max(array, size);

	std::cout << "\narray: " << '|';
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << '|';
	}
	std::cout << '\n' << std::endl;

	std::cout << "minimum element in the array: " << array_values.first.first << std::endl;
	std::cout << "position of the minimum element in the array: " << array_values.first.second << std::endl;
	std::cout << "maximum element in the array: " << array_values.second.first << std::endl;
	std::cout << "position of the maximum element in the array: " << array_values.second.second << std::endl;

	array_reverse(array, size);

	std::cout << "\nreverse array: " << '|';
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << '|';
	}
	std::cout << '\n' << std::endl;

	std::cout << "number of primes in the array: " << prime_number_counter(array, size) << std::endl;

	system("pause");
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename data_type>
std::pair<std::pair<data_type, int>, std::pair<data_type, int>> array_min_max(const data_type* array, const int size)
{
	std::pair<std::pair<data_type, int>, std::pair<data_type, int>> return_values;

	int index_min = 0;
	int index_max = 0;

	data_type min = 0;
	data_type max = 0;

	min = array[0];
	max = array[0];

	index_min = 1;
	index_max = 1;

	for (int i = 0; i < size; ++i)
	{
		if (array[i] < min)
		{
			index_min = i + 1;
			min = array[i];
		}
		if (array[i] > max)
		{
			index_max = i + 1;
			max = array[i];
		}
	}

	return_values.first.first = min;
	return_values.first.second = index_min;

	return_values.second.first = max;
	return_values.second.second = index_max;

	return return_values;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename data_type>
void array_reverse(data_type* array, const int size)
{
	data_type temp_variable = 0;

	for (int i = 0, j = size - 1; i < size / 2; ++i, --j)
	{
		temp_variable = array[i];
		array[i] = array[j];
		array[j] = temp_variable;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int prime_number_counter(const int* array, const int size)
{
	int counter = 0;

	// bool flag = false; // для отладки

	counter = size;

	for (int i = 0; i < size; ++i)
	{
		// flag = true; // для отладки

		if (array[i] < 2)
		{
			--counter;
			continue;
		}

		for (int j = 2; j < array[i]; ++j)
		{
			if (array[i] % j == 0)
			{
				--counter;
				// flag = false; // для отладки
				break;
			}
		}

		// if (flag) std::cout << array[i] << std::endl; // для отладки
	}

	return counter;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
