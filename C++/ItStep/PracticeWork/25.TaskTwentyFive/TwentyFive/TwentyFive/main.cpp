#include <ctime>
#include <iomanip>
#include <iostream>

/*
Задание 1. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив
минимально возможного размера, в котором нужно собрать элементы обоих массивов.

Задание 2. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив
минимально возможного размера, в котором нужно собрать общие элементы двух массивов без повторений.

Задание 3. Дан массив: А[M] (M вводится с клавиатуры). Необходимо удалить из массива четные или нечетные
значения. Пользователь вводит данные в массив, а также с помощью меню решает, что нужно удалить.
*/

int main(int arg_c, char* arg_v[])
{
	srand(time(0));

	bool flag = false;

	int choise = 0;

	int length_one = 0;
	int length_two = 0;
	int length_three = 0;

	int* array_one = nullptr;
	int* array_two = nullptr;
	int* array_three = nullptr;

	// ################################## //
	// #############TASK ONE############# //
	// ################################## //

	std::cout << "enter the size of the first array: ";
	std::cin >> length_one;
	std::cout << "enter the size of the second array: ";
	std::cin >> length_two;

	array_one = new int[length_one];
	array_two = new int[length_two];

	std::cout << std::setw(15) << "array one: |";
	for (size_t i = 0; i < length_one; ++i)
	{
		*array_one = rand() % 101 + 1;
		std::cout << std::setw(3) << *array_one << '|';
		++array_one;
	}
	std::cout << '\n';
	array_one -= length_one;

	std::cout << std::setw(15) << "array two: |";
	for (size_t i = 0; i < length_two; ++i)
	{
		*array_two = rand() % 101 + 1;
		std::cout << std::setw(3) << *array_two << '|';
		++array_two;
	}
	std::cout << '\n';
	array_two -= length_two;

	array_three = new int[length_one + length_two];

	flag = true;

	for (size_t i = 0; i < length_one + length_two; ++i)
	{
		if (i == length_one)
			flag = false;

		if (flag)
			* array_three++ = *array_one++;
		else
			*array_three++ = *array_two++;
	}

	array_one -= length_one;
	array_two -= length_two;
	array_three -= (length_one + length_two);

	std::cout << std::setw(15) << "array three: |";
	for (size_t i = 0; i < length_one + length_two; ++i)
	{
		std::cout << std::setw(3) << *array_three << '|';
		++array_three;
	}
	std::cout << '\n';
	array_three -= (length_one + length_two);

	// ################################## //
	// #############TASK TWO############# //
	// ################################## //

	length_three = 0;

	for (size_t i = 0; i < length_one; ++i)
	{
		for (size_t j = 0; j < length_two; ++j)
		{
			if (array_two[j] == array_one[i])
			{
				++length_three;
				break;
			}
		}
	}

	if (length_three)
	{
		int index = 0;

		delete[] array_three;

		array_three = new int[length_three];

		for (size_t i = 0; i < length_one; ++i)
		{
			for (size_t j = 0; j < length_two; ++j)
			{
				if (array_two[j] == array_one[i])
				{
					array_three[index] = array_two[j];
					++index;
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "\nthere are no common elements in the arrays\n" << std::endl;

		length_three = length_one + length_two;
	}

	std::cout << std::setw(15) << "array one: |";
	for (size_t i = 0; i < length_one; ++i)
		std::cout << std::setw(3) << array_one[i] << '|';
	std::cout << '\n';

	std::cout << std::setw(15) << "array two: |";
	for (size_t i = 0; i < length_two; ++i)
		std::cout << std::setw(3) << array_two[i] << '|';
	std::cout << '\n';

	std::cout << std::setw(15) << "array three: |";
	for (size_t i = 0; i < length_three; ++i)
		std::cout << std::setw(3) << array_three[i] << '|';
	std::cout << '\n';

	// ################################## //
	// ############TASK THREE############ //
	// ################################## //

	choise = -1;

	while(choise)
	{
		std::cout << "\tmenu\n";
		std::cout << "1. remove even numbers\n";
		std::cout << "2. remove odd numbers\n";
		std::cout << "0. exit\n";
		std::cout << "choose menu item: ";
		std::cin >> choise;

		length_three = length_one;

		if (choise == 1)
		{
			delete[] array_three;

			for (size_t i = 0; i < length_one; ++i)
			{
				if (array_one[i] % 2 == 0)
					--length_three;
			}

			array_three = new int[length_three];

			for (size_t i = 0, j = 0; i < length_one; ++i)
			{
				if (array_one[i] % 2 != 0)
				{
					array_three[j] = array_one[i];
					++j;
				}
			}
		}
		else if (choise == 2)
		{
			delete[] array_three;

			for (size_t i = 0; i < length_one; ++i)
			{
				if (array_one[i] % 2 != 0)
					--length_three;
			}

			array_three = new int[length_three];

			for (size_t i = 0, j = 0; i < length_one; ++i)
			{
				if (array_one[i] % 2 == 0)
				{
					array_three[j] = array_one[i];
					++j;
				}
			}
		}
		else if (choise == 0) break;

		std::cout << "array old: |";
		for (size_t i = 0; i < length_one; ++i)
		{
			std::cout << std::setw(3) << array_one[i] << '|';
		}
		std::cout << '\n';
		
		std::cout << "array new: |";
		for (size_t i = 0; i < length_three; ++i)
		{
			std::cout << std::setw(3) << array_three[i] << '|';
		}
		std::cout << '\n';

		std::cout << "continue(1.yes/0.no): ";
		std::cin >> choise;
	}

	delete[] array_one;
	delete[] array_two;
	delete[] array_three;

	system("pause");
	return 0;
}

// -(rand() % 101) îò -100 äî 0

/*
template<typename data_type>
void create_array(data_type* array, const int size) { array = new data_type[size]; }

template<typename data_type>
void fill_array(data_type* array, const int size);

template<typename data_type>
void output_array(data_type* array, const int size);

template<typename data_type>
void fill_array(data_type* array, const int size)
{
	data_type* pointer_array = array;

	for (size_t i = 0; i < size; ++i)
	{
		*pointer_array = rand() % 41 - 20;
	}
}

template<typename data_type>
void output_array(data_type* array, const int size)
{
	data_type* pointer_array = array;

	std::cout << "array: |";
	for (size_t i = 0; i < size; ++i)
		std::cout << *pointer_array++ << '|';
	std::cout << '\n';
}
*/
