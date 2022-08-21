#include <array>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <Windows.h>

int main(int _arguments_counter, char* _arguments_value[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	
	// Задание 1. Сжать (сдвинуть элементы) массив, удалив из  него все 0,
	// и заполнить освободившиеся справа элементы  значениями -1.
	const int size = 50;
	std::array<int, size> array{ 0 };
	int index = 0;

	std::cout << std::setiosflags(std::ios::left) << std::setw(30) << "массив в первоночальном виде:";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = rand() % 11;
		std::cout << std::setw(3) << array[i] << '|';
	}
	std::cout << std::endl;

	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] == 0 && i != size - 1)
		{
			index = i + 1;
			while (array[index] == 0)
			{
				if (index != size - 1)
					++index;
				else
					break;
			}
			array[i] = array[index];
			array[index] = 0;
		}
	}

	std::cout << std::setiosflags(std::ios::left) << std::setw(30) << "измененный массив:";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(3) << array[i] << '|';
	}
	std::cout << std::endl;

	for (size_t i = size - 1; i > 0; --i)
	{
		if (array[i] == 0)
		{
			array[i] = -1;
		}
		else
		{
			break;
		}
	}

	std::cout << std::setiosflags(std::ios::left) << std::setw(30) << "завершенный вариант массива:";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(3) << array[i] << '|';
	}
	std::cout << std::endl;

	/*
	  Задание 2. Написать программу, копирующую элементы
	  2-х массивов размером 5 элементов каждый в один мас-
	  сив размером 10 элементов следующим образом: сначала
	  копируются последовательно все элементы, большие 0,
	  затем последовательно все элементы, равные 0, а затем
	  последовательно все элементы, меньшие 0.
	*/

	const int length = 10;

	index = 0;

	std::array<int, length> _null_array{ 0 };
	std::array<int, 5> _first_array{ 0 };
	std::array<int, 5> _second_array{ 0 };

	for (size_t i = 0; i < 5; ++i)
	{
		_first_array[i] = rand() % 19 - 9;
		_second_array[i] = rand() % 19 - 9;
	}

	for (size_t i = 0; i < 5; ++i)
	{
		if (_first_array[i] > 0)
		{
			_null_array[index] = _first_array[i];
			++index;
		}
	}
	for (size_t i = 0; i < 5; ++i)
	{
		if (_second_array[i] > 0)
		{
			_null_array[index] = _second_array[i];
			++index;
		}
	}
	if (index < 10)
	{
		for (size_t i = 0; i < 5; ++i)
		{
			if (_first_array[i] == 0)
			{
				_null_array[index] = _first_array[i];
				++index;
			}
		}
		for (size_t i = 0; i < 5; ++i)
		{
			if (_second_array[i] == 0)
			{
				_null_array[index] = _second_array[i];
				++index;
			}
		}
	}
	if (index < 10)
	{
		for (size_t i = 0; i < 5; ++i)
		{
			if (_first_array[i] < 0)
			{
				_null_array[index] = _first_array[i];
				++index;
			}
		}
		for (size_t i = 0; i < 5; ++i)
		{
			if (_second_array[i] < 0)
			{
				_null_array[index] = _second_array[i];
				++index;
			}
		}
	}

	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "массив №1: ";
	std::cout << '|';
	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << _first_array[i] << '|';
	}
	std::cout << std::endl;

	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "массив №2: ";
	std::cout << '|';
	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << _second_array[i] << '|';
	}
	std::cout << std::endl;

	std::cout << std::setiosflags(std::ios::left) << std::setw(10) << "массив №0: ";
	std::cout << '|';
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << _null_array[i] << '|';
	}
	std::cout << std::endl;

	return 0;
}
