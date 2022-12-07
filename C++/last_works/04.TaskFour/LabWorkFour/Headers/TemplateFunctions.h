#pragma once

#include "../Headers/libraries.h"

// среднее арифметическое значений массива
template<typename data_type>
data_type _arithmetic_mean(const data_type* value_array, const unsigned int& value_count)
{
	data_type sum = 0;

	for (unsigned int i = 0; i < value_count; ++i)
		sum += value_array[i];
	sum /= value_count;

	return sum;
}
// нахождение корней линейного уравнения
template<typename data_type>
data_type _linear_equation_root(const data_type& coefficientA, const data_type& coefficientB)
{
	data_type a = 0;
	data_type b = 0;
	data_type x = 0;

	a = coefficientA;
	b = -coefficientB;
	x = b / a;

	return x;
}
// нахождение корней квадратного уравнения
template<typename data_type>
std::pair<data_type, data_type> _quadratic_equation_root(const data_type& coefficientA, const data_type& coefficientB, const data_type& coefficientC)
{
	data_type b = 0;
	data_type root = 0;
	data_type divider = 0;
	data_type x_first = 0;
	data_type x_second = 0;

	b = -coefficientB;
	root = sqrt(pow(coefficientB, 2.0) - 4 * coefficientA * coefficientC);
	divider = 2 * coefficientA;

	x_first = (b + root) / divider;
	x_second = (b - root) / divider;

	return std::pair<data_type, data_type>(x_first, x_second);
}
// максимальное значение из двух значений
template<typename data_type>
data_type _max_value(const data_type& value_first, const data_type& value_second)
{
	data_type max_value = 0;

	max_value = (value_first > value_second) ? value_first : value_second;

	return max_value;
}
// минимальное значение из двух значений
template<typename data_type>
data_type _min_value(const data_type& value_first, const data_type& value_second)
{
	data_type min_value = 0;

	min_value = (value_first < value_second) ? value_first : value_second;

	return min_value;
}

// #################### //
// #################### //
// #################### //

// тип данных значения
template <typename data_type>
unsigned int valueDataType(data_type value)
{
	bool exit = false;

	unsigned int return_value = 0;

	const unsigned int size_integer = 11;
	const unsigned int size_float = 3;
	const unsigned int size_char_bool = 4;

	const char* type = typeid(value).name();

	const char type_integer[size_integer] = { 'w', 'D', 's', 't', 'i', 'j', 'l', 'm', 'x', 'y' };
	const char type_float[size_float] = { 'f', 'd', 'e' };
	const char type_char_bool[size_char_bool] = { 'b', 'c', 'a', 'h' };

	for (unsigned int i = 0; i < size_integer; ++i)
	{
		if (!exit)
		{
			if (i < size_float)
			{
				return_value = (type[0] == type_integer[i]) ? 1 : (type[0] == type_float[i]) ? 2 : (type[0] == type_char_bool[i]) ? 3 : 0;
				if (return_value) exit = true;
			}
			else if (i == size_float)
			{
				return_value = (type[0] == type_integer[i]) ? 1 : (type[0] == type_char_bool[i]) ? 3 : 0;
				if (return_value) exit = true;
			}
			else if (i > size_float)
			{
				return_value = (type[0] == type_integer[i]) ? 1 : 0;
				if (return_value) exit = true;
			}
		}
		else break;
	}

	return return_value;
}
// длинна(количество цифр[символов]) значения
template <typename data_type>
unsigned int valueLength(data_type value)
{
	unsigned int length = 0;
	unsigned int size = 0;

	unsigned int type = 0;

	char* valueChanged = nullptr;

	std::string _value_ = "";

	type = valueDataType(value);
	_value_ = std::to_string(value);

	// целочисленный тип данных
	if (type == 1)
		length = _value_.length();
	// если тип данных вещественное число
	else if (type == 2)
	{
		for (size_t i = _value_.length() - 1; _value_[i] != '.'; --i)
		{
			if (_value_[i] == '0')
				++size;
			else
				break;
		}
		valueChanged = new char[_value_.length() - size + 1];
		strncpy(valueChanged, _value_.c_str(), _value_.length() - size);
		valueChanged[_value_.length() - size] = '\0';
		length = strlen(valueChanged);
	}
	// тип данных символ или булево значение
	else if (type == 3)
		length = 1;
	// пользовательский тип дынных
	else
		length = 0;

	return length;
}