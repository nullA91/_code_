/*
|__________________________________________________________________________
|-------------------------------------------------------------------------/
| Задание 1. Дан массив чисел размерностью 10 элемен-                    /
| тов. Написать функцию, которая сортирует массив по                    /
| возрастанию или по убыванию, в зависимости от треть-                 /
| его параметра функции. Если он равен true, сортировка               /
| идет по убыванию, если false, то по возрастанию. Первые            /
| 2 параметра функции — это массив и его размер, третий             /
| параметр по умолчанию равен false.                               /
| ##############################################################  /
| ############################################################## /
| Задание 2. Написать функцию, которая сортирует первую         /
| половину массива по убыванию, а вторую — по возрас-          /
| танию, используя сортировку простыми вставками.             /
| #########################################################  /
| ######################################################### /
| Задание 3. В функцию передаётся массив случайных         /
| чисел в диапазоне от -20 до +20. Необходимо найти по-   /
| зиции крайних отрицательных элементов (самого левого   /
| отрицательного элемента и самого правого отрицатель-  /
| ного элемента) и отсортировать элементы, находящиеся /
| между ними.                                         /
|----------------------------------------------------/
|###################################################/
|--------------------------------------------------/
*/

#include <ctime>
#include <iomanip>
#include <iostream>

void array_filling(int* array, const uint8_t size)
{ 
	for (uint8_t i = 0; i < size; ++i) 
		array[i] = rand() % 41 - 20; 
}
void array_output(const int* array, const uint8_t size) 
{
	std::cout << "||"; 
	for (uint8_t i = 0; i < size; ++i) 
		std::cout << std::setw(3) << array[i] << "||"; std::cout << "\n\n"; 
}

void array_sort(int* array, const uint8_t size, const bool sorting_type = false);
void array_sort_two_ways(int* array, const uint8_t size);
void array_sorting_between_negative_elements(int* array, const uint8_t size);

int main(int arg_c, char* arg_v[])
{
	system("cls");

	srand(time(NULL));

	const uint8_t size = 25;
	bool flag = false;

	int array[size]{ 0 };
	
	array_filling(array, size);
	std::cout << std::setiosflags(std::ios::left) << std::setw(45) << "array:";
	array_output(array, size);

	array_sort(array, size, true);
	std::cout << std::setw(45) << "array sorted in descending order:";
	array_output(array, size);

	array_sort(array, size);
	std::cout << std::setw(45) << "array sorted in ascending order:";
	array_output(array, size);

	////////////////
	array_filling(array, size);
	std::cout << std::setw(45) << "array:";
	array_output(array, size);

	array_sort_two_ways(array, size);
	std::cout << std::setw(45) << "array sorted in two ways:";
	array_output(array, size);
	///////////////
	array_filling(array, size);
	std::cout << std::setw(45) << "array:";
	array_output(array, size);

	array_sorting_between_negative_elements(array, size);
	std::cout << std::setw(45) << "array sorting between negative elements:";
	array_output(array, size);
	///////////////
	system("pause");
	return 0;
}

void array_sort(int* array, const uint8_t size, const bool sorting_type)
{
	// true - по убыванию
	// false - по возрастанию
	bool flag = false;

	int counter = 0;
	int temp_variable = 0;
	int min = 0;
	int max = 0;

	if (sorting_type)
	{
		flag = true;
		min = size - 1;
		max = 0;

		while (flag)
		{
			for (uint8_t i = min - 1, j = max + 1; j < size; --i, ++j)
			{
				// поиск минимального элемента в массиве
				if (array[i] < array[min])
				{
					temp_variable = array[min];
					array[min] = array[i];
					array[i] = temp_variable;
					++counter;
				}
				//  поиск максимального элемента в массиве
				if (array[j] > array[max])
				{
					temp_variable = array[max];
					array[max] = array[j];
					array[j] = temp_variable;
					++counter;
				}
			}
			flag = counter;
			if (min > 1) --min;
			if (max < size - 2) ++max;
			counter = 0;
		}
	}
	else
	{
		flag = true;
		min = 0;
		max = size - 1;

		while (flag)
		{
			for (uint8_t i = min + 1, j = max - 1; i < size; ++i, --j)
			{
				// поиск минимального элемента в массиве
				if (array[i] < array[min])
				{
					temp_variable = array[min];
					array[min] = array[i];
					array[i] = temp_variable;
					++counter;
				}
				// поиск максимального элемента в массиве
				if (array[j] > array[max])
				{
					temp_variable = array[max];
					array[max] = array[j];
					array[j] = temp_variable;
					++counter;
				}
			}
			flag = counter;
			if (min < size - 2) ++min;
			if (max > 1) --max;
			counter = 0;
		}
	}
}

void array_sort_two_ways(int* array, const uint8_t size)
{
	bool flag = false;
	int counter = 0;
	int temp_variable = 0;
	int min = 0;
	int max = 0;

	array_sort(array, (size / 2), true);

	flag = true;
	min = 0 + size / 2;
	max = size - 1;

	while (flag)
	{
		for (uint8_t i = min + 1, j = max - 1; i < size; ++i, --j)
		{
			// поиск минимального элемента в массиве
			if (array[i] < array[min])
			{
				temp_variable = array[min];
				array[min] = array[i];
				array[i] = temp_variable;
				++counter;
			}
			// поиск максимального элемента в массиве
			if (array[j] > array[max])
			{
				temp_variable = array[max];
				array[max] = array[j];
				array[j] = temp_variable;
				++counter;
			}
		}
		flag = counter;
		if (min < size - 2) ++min;
		if (max > 1) --max;
		counter = 0;
	}
}

void array_sorting_between_negative_elements(int* array, const uint8_t size)
{
	bool flag = false;
	int counter = 0;
	int temp_variable = 0;
	int min = 0;
	int max = 0;

	int left_index = 0;
	int right_index = 0;

	for (int i = 0; i < size; ++i)
	{
		if (array[i] < 0)
		{
			left_index = i;
			break;
		}
	}
	for (int i = size - 1; i >= 0; --i)
	{
		if (array[i] < 0)
		{
			right_index = i;
			break;
		}
	}

	if (right_index > (left_index + 2))
	{
		flag = true;
		min = left_index + 1;
		max = right_index - 1;

		while (flag)
		{
			for (int i = min + 1, j = max - 1; i < right_index; ++i, --j)
			{
				// поиск минимального элемента в массиве
				if (array[i] < array[min])
				{
					temp_variable = array[min];
					array[min] = array[i];
					array[i] = temp_variable;
					++counter;
				}
				// поиск максимального элемента в массиве
				if (array[j] > array[max])
				{
					temp_variable = array[max];
					array[max] = array[j];
					array[j] = temp_variable;
					++counter;
				}
			}
			flag = counter;
			if (min < right_index - 2) ++min;
			if (max > left_index + 1) --max;
			counter = 0;
		}
	}
}