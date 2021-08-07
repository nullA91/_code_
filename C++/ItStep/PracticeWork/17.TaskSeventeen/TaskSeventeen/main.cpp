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

	const unsigned int size = 10;

	/*
	Задание 1. Написать программу, выполняющую со-
	ртировку одномерного массива целых чисел методом
	пузырьковой сортировки.
	*/

	bool flag = false;

	std::array<int, size> array{ 0 };

	unsigned int iterations = 0;

	int counter = 0;
	int index = 0;
	int min = 0;
	int max = 0;
	int _temp_variable = 0;
	int choise = 0;

	for (size_t i = 0; i < size; ++i)
	{
		array[i] = rand() % 101 - 50;
	}
	std::cout << "\t\t\tсортировка методом пузырька:\n";
	std::cout << std::setiosflags(std::ios::left) << std::setw(35) << "массив в первоначальном виде: ";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(5) << array[i] << '|';
	}
	std::cout << std::endl;
	// сортировка методом пузырька
	index = 0;
	flag = true;
	while (flag)
	{
		for (size_t i = index + 1; i < size; ++i)
		{
			if (array[i] < array[index])
			{
				_temp_variable = array[index];
				array[index] = array[i];
				array[i] = _temp_variable;
				if (counter < 1)
				{
					++counter;
				}
			}
		}
		if (counter == 0 && index != 0)
		{
			flag = false;
		}
		if (index < size - 2)
		{
			++index;
		}
		counter = 0;

		++iterations;
	}

	std::cout << std::setw(35) << "отсортированный массив: ";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(5) << array[i] << '|';
	}
	std::cout << std::endl;

	std::cout << "\nколичество итераций: " << iterations << " шт." << std::endl;
	/*
	Задание 2. Написать программу, выполняющую сорти-
	ровку одномерного массива целых чисел методом вставок.
	*/
	for (size_t i = 0; i < size; ++i)
		array[i] = rand() % 101 - 50;
	std::cout << "\n\t\t\tсортировка методом вставок:\n";
	std::cout << std::setiosflags(std::ios::left) << std::setw(40) << "новый массив в первоначальном виде: ";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(5) << array[i] << '|';
	}
	std::cout << std::endl;

	iterations = 0;
	counter = 0;
	flag = true;
	min = 0;
	max = size - 1;
	// сортировка методом вставок
	while (flag)
	{
		for (size_t i = min + 1, j = max - 1; i < size; ++i, --j)
		{
			// поиск минимального
			if (array[i] < array[min])
			{
				_temp_variable = array[min];
				array[min] = array[i];
				array[i] = _temp_variable;
				++counter;
			}
			// поиск максимального
			if (array[j] > array[max])
			{
				_temp_variable = array[max];
				array[max] = array[j];
				array[j] = _temp_variable;
				++counter;
			}
		}
		flag = counter;
		if (min < size - 2)
			++min;
		if (max > 1)
			--max;
		counter = 0;

		++iterations;
	}

	std::cout << std::setw(40) << "новый отсортированный массив: ";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(5) << array[i] << '|';
	}
	std::cout << std::endl;

	std::cout << "\nколичество итераций: " << iterations << " шт.\n" << std::endl;

	/*
	Задание 3. Написать программу «успеваемость». Поль-
	зователь вводит 10 оценок студента. Реализовать меню для пользователя
		■ Вывод оценок (вывод содержимого массива);
		■ Пересдача экзамена (пользователь вводит номер элемента массива и новую оценку);
		■ Выходит ли стипендия (стипендия выходит, если средний бал не ниже 10.7).
	*/

	for (size_t i = 0; i < size; ++i)
	{
	retry:
		if (i != 2)
			std::cout << "введите " << i + 1 << " -ую оценку студента: ";
		else
			std::cout << "введите " << i + 1 << " -юю оценку студента: ";
		std::cin >> array[i];
		if (array[i] < 1 || array[i] > 12)
			goto retry;
	}
ChooseOperation:
	system("cls");
	//////////////////////////////////////////////////////////////// меню //////////////////////////////////////////////////////////////////////////
	//std::cout << ' ';
	for (size_t i = 0; i < 30; ++i)
		std::cout << '-';
	std::cout << '\n' << '|' << std::setiosflags(std::ios::right) << std::setw(16) << "меню" << std::setw(13) << '|' << std::endl;
	//std::cout << ' ';
	for (size_t i = 0; i < 30; ++i)
		std::cout << '-';
	std::cout << '\n' << '|' << std::setiosflags(std::ios::left) << std::setw(12) << "1. вывод оценок" << std::setw(14) << '|' << std::endl;
	//std::cout << ' ';
	for (size_t i = 0; i < 30; ++i)
		std::cout << '-';
	std::cout << '\n' << '|' << std::setiosflags(std::ios::left) << std::setw(12) << "2. пересдача экзамена" << std::setw(8) << '|' << std::endl;
	//std::cout << ' ';
	for (size_t i = 0; i < 30; ++i)
		std::cout << '-';
	std::cout << '\n' << '|' << std::setiosflags(std::ios::left) << std::setw(12) << "3. выходит ли стипендия" << std::setw(6) << '|' << std::endl;
	//std::cout << ' ';
	for (size_t i = 0; i < 30; ++i)
		std::cout << '-';
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "\nвыберите операцию: ";
	std::cin >> choise;

	if (choise == 1)
	{
		std::cout << "\tоценки за экзамен\n";
		for (size_t i = 0; i < size; ++i)
		{
			if (i != 2)
				std::cout << i + 1 << " -ая оценка за экзамен: " << array[i] << std::endl;
			else
				std::cout << i + 1 << " -яя оценка за экзамен: " << array[i] << std::endl;
		}
	}
	else if (choise == 2)
	{
	Retry:
		std::cout << "введите № экзамена который нужно пересдать: ";
		std::cin >> index;
		if (index < 1 || index > 10)
			goto Retry;
	RETRY:
		std::cout << "введите новую оценку за экзамен № " << index << ": ";
		std::cin >> array[--index];
		if (array[index] < 1 || array[index] > 12)
			goto RETRY;
	}
	else if (choise == 3)
	{
		_temp_variable = 0;
		for (size_t i = 0; i < size; ++i)
			_temp_variable += array[i];
		if (static_cast<double>(_temp_variable / 10) > 10.6)
			std::cout << "вы получаете степендию" << std::endl;
		else
			std::cout << "вы не получите стипендию" << std::endl;
	}
	else
	{
		std::cout << "выберите правильный номер операции" << std::endl;
		goto ChooseOperation;
	}

	std::cout << "продолжить (1.да/0.нет): ";
	std::cin >> choise;

	if (choise)
		goto ChooseOperation;

	/*
	Задание 5. Необходимо отсортировать первые две трети
	массива в порядке возрастания если среднее арифме-
	тическое всех элементов больше нуля; иначе — лишь
	первую треть. Остальную часть массива не сортировать,
	а расположить в обратном порядке.
	*/

	_temp_variable = 0;
	min = 0;
	counter = 0;
	index = 0;
	flag = true;

	std::cout << std::endl;
	std::cout << "массив в первоначальном виде:  ";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = rand() % 21 - 10;
		std::cout << array[i] << '|';
		_temp_variable += array[i];
	}
	std::cout << std::endl;

	if (_temp_variable / size > 0)
	{
		index = size / 3 * 2;
		while (flag)
		{
			for (size_t i = min + 1; i < size / 3 * 2; ++i)
			{
				if (array[i] < array[min])
				{
					_temp_variable = array[min];
					array[min] = array[i];
					array[i] = _temp_variable;
					if (counter < 1)
					{
						++counter;
					}
				}
			}
			if (counter == 0 && min != 0)
			{
				flag = false;
			}
			if (min < size / 3 * 2 - 2)
			{
				++min;
			}
			counter = 0;
		}
	}
	else
	{
		index = size / 3 * 1;
		while (flag)
		{
			for (size_t i = min + 1; i < size / 3 * 1; ++i)
			{
				if (array[i] < array[min])
				{
					_temp_variable = array[min];
					array[min] = array[i];
					array[i] = _temp_variable;
					if (counter < 1)
					{
						++counter;
					}
				}
			}
			if (counter == 0 && min != 0)
			{
				flag = false;
			}
			if (min < size / 3 * 2 - 2)
			{
				++min;
			}
			counter = 0;
		}
	}

	std::cout << "отсортированный массив:        ";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << array[i] << '|';
	}
	std::cout << std::endl;
	
	for (size_t i = index, j = size - 1, k = 0; k < (size - index) / 2; ++i, --j, ++k)
	{
		_temp_variable = array[i];
		array[i] = array[j];
		array[j] = _temp_variable;
	}

	std::cout << "новый отсортированный массив:  ";
	std::cout << '|';
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << array[i] << '|';
	}
	std::cout << std::endl;

	return 0;
}

/*
index = 0;
	int i = 1;
	int inc = 1;
	flag = true;
	while (flag)
	{
		for (; i < size; ++i)
		{
			if (array[i] < array[index])
			{
				_temp_variable = array[index];
				array[index] = array[i];
				array[i] = _temp_variable;
				if (counter < 1)
				{
					++counter;
				}
			}
		}
		if (counter == 0)
		{
			flag = false;
		}
		if (index < size - 1)
		{
			++index;
		}
		if(inc < size - 1)
		i = ++inc;
		counter = 0;
	}

	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(5) << array[i] << '|';
	}
*/

/*
int arr[5] = { 5,13,7,2,1 };

	flag = true;
	min = 0;
	max = 5 - 1;
	// сортировка методом вставок
	while (flag)
	{
		for (size_t i = min + 1, j = max - 1; i < 5; ++i, --j)
		{
			// поиск минимального
			if (arr[i] < arr[min])
			{
				_temp_variable = arr[min];
				arr[min] = arr[i];
				arr[i] = _temp_variable;
				++counter;
			}
			// поиск максимального
			if (arr[j] > arr[max])
			{
				_temp_variable = arr[max];
				arr[max] = arr[j];
				arr[j] = _temp_variable;
				++counter;
			}
		}
		flag = counter;
		if (min < size - 2)
			++min;
		if (max > 1)
			--max;
		counter = 0;
	}

	std::cout << std::setw(35) << "\nновый отсортированный массив: ";
	std::cout << '|';
	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << std::setw(5) << arr[i] << '|';
	}
	std::cout << std::endl;
*/