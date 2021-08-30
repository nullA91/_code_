/*
Напишите шаблонную функцию maxn(), которая принимает в качестве
аргумента массив элементов типа T и целое число, представляющее количество
элементов в массиве, а возвращает элемент с наибольшим значением. Протестируйте
ее работу в программе, которая использует этот шаблон с массивом из шести
значений int и массивом из четырех значений double. Программа также
должна включать специализацию, которая использует массив указателей на char в
качестве первого аргумента и количество указателей — в качестве второго, а затем
возвращает адрес самой длинной строки. Если имеется более одной строки
наибольшей длины, функция должна вернуть адрес первой из них. Протестируйте
специализацию на массиве из пяти указателей на строки.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>
#include <typeinfo>

template<typename T>
void maxn(T* _array, size_t _elements_number, std::string _data_type_source = "undefined");

int main() {
	setlocale(LC_ALL, "RUSSIAN");

	int _array_integer[6] = { 1, 2, 13, 4, 5, 0 };
	double _array_double[4] = { 13.3, 13.7, 13.1, 13 };
	char* _array_char_pointer[] = { "One", "Three","Five", "Eight", "Nine" };

	maxn(_array_integer, 6, typeid(*_array_integer).name());
	maxn(_array_double, 4, typeid(*_array_double).name());
	maxn(_array_char_pointer, 5, typeid(*_array_char_pointer).name());
	
	system("pause");
	return 0;
}

template<typename T>
void maxn(T* _array, size_t _elements_number, std::string _data_type_source) {
	T _max_element = 0;
	if (_data_type_source == "int" || _data_type_source == "double" || _data_type_source == "char") {
		for (size_t i = 0; i < _elements_number; ++i)
			if (_array[i] > _max_element)
				_max_element = _array[i];
		std::cout << "максимальное значение в массиве: " << _max_element << std::endl;
	}
	else {
		std::string _string;
		std::string _string_max_length;
		if (_elements_number > 1) {
			_string_max_length = _array[0];
			for (size_t i = 1; i < _elements_number; ++i) {
				_string = _array[i];
				if (_string_max_length.length() < _string.length())
					_string_max_length = _string;
			}
			std::cout << "самая длинная строка в массиве: " << _string_max_length << std::endl;
		}
		else
			std::cout << "в массиве только одна строка..." << std::endl;
	}
}