#pragma once

#include "global.h"

template<typename data_type>
std::pair<data_type, data_type> sum_and_prodocts_array_elements(const data_type* array, const size_t& size)
{
	std::pair<data_type, data_type> return_value;

	return_value.first = 0;
	return_value.second = 1;

	for (size_t i = 0; i < size; ++i)
	{
		return_value.first += array[i];
		return_value.second *= array[i];
	}

	return return_value;
}

template<typename data_type>
std::pair<std::pair<int, int>, int> pos_neg_zero_arr_elem(const data_type* array, const size_t& size)
{
	std::pair<std::pair<int, int>, int> return_value;

	unsigned int counter_positive = 0;
	unsigned int counter_negative = 0;
	unsigned int counter_zero = 0;

	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] > 0)
			++counter_positive;
		else if (array[i] < 0)
			++counter_negative;
		else
			++counter_zero;
	}

	return_value.first.first = counter_positive;
	return_value.first.second = counter_negative;
	return_value.second = counter_zero;

	return return_value;
}

template<typename data_type>
data_type* check_arr_B_is_sub_arr_A(data_type* array_one, data_type* array_two, const size_t& size_one, const size_t& size_two)
{
	int check_size = 0;

	data_type* address = nullptr;

	if (size_one < size_two)
	{
		std::cout << "array B cannot be a subset of array A" << std::endl;
		return address;
	}

	for (size_t i = 0, j = 0; i < size_one; ++i)
	{
		if (array_one[i] == array_two[j])
		{
			++check_size;
			++j;
		}
		else
		{
			check_size = 0;
			j = 0;
		}

		if (check_size == size_two)
		{
			address = (array_one + i - size_two + 1);
			break;
		}
	}

	return address;
}

template<typename data_type>
data_type* array_without_negative_numbers(const data_type* array, size_t& size)
{
	const size_t length = size;

	data_type* pointer_array = nullptr;

	for (size_t i = 0; i < length; ++i)
	{
		if (array[i] < 0) --size;
	}

	if (size)
	{
		pointer_array = new data_type[size];
		for (size_t i = 0, index = 0; i < length; ++i)
		{
			if (array[i] >= 0)
			{
				pointer_array[index] = array[i];
				++index;
			}
		}
	}

	delete[] array;

	return pointer_array;
}

template<typename data_type>
data_type* add_elem_end_arr(data_type* array_one, const data_type* array_two, const size_t& size_one, const size_t& size_two)
{
	const size_t length = (size_one + size_two);

	data_type* pointer_new_array = nullptr;

	pointer_new_array = new data_type[length];

	for (size_t i = 0, index = 0; i < length; ++i)
	{
		if (i < size_one)
			pointer_new_array[i] = array_one[i];
		else
		{
			pointer_new_array[i] = array_two[index];
			index++;
		}
	}

	delete[] array_one;

	array_one = new data_type[length];

	for (size_t i = 0; i < length; ++i)
	{
		array_one[i] = pointer_new_array[i];
	}

	delete[] pointer_new_array;

	return array_one;
}

template<typename data_type>
data_type* add_elem_anywhere_arr(data_type* array_one, const data_type* array_two, const size_t& size_one, const size_t& size_two, const unsigned int& index)
{
	const size_t length = (size_one + size_two);

	data_type* pointer_array = nullptr;

	pointer_array = new data_type[length];

	for (size_t i = 0; i < index - 1; ++i)
	{
		pointer_array[i] = array_one[i];
	}

	for (size_t i = 0, j = index - 1; i < size_two; ++i, ++j)
	{
		pointer_array[j] = array_two[i];
	}

	for (size_t i = index - 1, j = index - 1 + size_two; i < size_one; ++i, ++j)
	{
		pointer_array[j] = array_one[i];
	}

	delete[] array_one;

	return pointer_array;
}

template<typename data_type>
data_type* remov_elem_arr(data_type* array_one, const unsigned int& index)
{
	data_type* pointer_array = nullptr;

	pointer_array = new data_type[index];

	for (size_t i = 0; i < index - 1; ++i)
	{
		pointer_array[i] = array_one[i];
	}

	delete[] array_one;

	return pointer_array;
}

void create_menu(const char* string);