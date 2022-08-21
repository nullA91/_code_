#include "functions.h"

int main(int arg_c, char* arg_v[])
{
	srand(static_cast<unsigned int>(time(NULL)));

	int choise = 0;

	do
	{
		system("cls");

		create_menu("menu");
		create_menu("sum and product of all array elements");
		create_menu("number of negative, positive and zero elements of the array");
		create_menu("checking if array B is a subset of array A");
		create_menu("removing all negative numbers from an array");
		create_menu("adding a block of elements to the end of the array");
		create_menu("adding a block of elements starting at an arbitrary array index");
		create_menu("deleting a block of elements starting at an arbitrary array index");
		std::cout << "select menu item: ";
		std::cin >> choise;
		
		switch (choise)
		{
			case 1:
			{
				const size_t size = 25;

				unsigned long long array[size] = { 0 };

				int value = 0;

				for (size_t i = 0; i < size; ++i)
				{
					value = rand() % 101 + 1;
					array[i] = value;
				}

				std::cout << "array: |";
				for (size_t i = 0; i < size; ++i)
					std::cout << std::setw(3) << array[i] << '|';
				std::cout << '\n' << std::endl;

				std::cout << "sum of all array elements: " << sum_and_prodocts_array_elements(array, size).first << std::endl;
				std::cout << "multiplication of all array elements: " << sum_and_prodocts_array_elements(array, size).second << std::endl;

				break;
			}
			case 2:
			{
				// min + rand() % (max - min + 1);

				const int size = 25;

				int array[size] = { 0 };

				for (size_t i = 0; i < size; ++i)
				{
					array[i] = -50 + rand() % (50 - -50 + 1);
				}

				std::cout << "array: |";
				for (size_t i = 0; i < size; ++i)
					std::cout << std::setw(3) << array[i] << '|';
				std::cout << '\n' << std::endl;

				std::cout << "number of positive elements: " << pos_neg_zero_arr_elem(array, size).first.first << std::endl;
				std::cout << "number of negative elements: " << pos_neg_zero_arr_elem(array, size).first.second << std::endl;
				std::cout << "number of zero elements: " << pos_neg_zero_arr_elem(array, size).second << std::endl;

				break;
			}
			case 3:
			{
				const size_t size_one = 25;
				const size_t size_two = 10;

				int array_one[size_one] = { 3, 7, 14, 29, 3, 8, 5, 7, 17, 4, -34, 1, 0, 29, 3, 15, 999, 23, 56, 3, 35, 22, 23, 24, 25 };
				int array_two[size_two] = { 29, 3, 15, 999, 23, 56, 3, 35, 22, 23 };

				if (check_arr_B_is_sub_arr_A(array_one, array_two, size_one, size_two) != nullptr)
				{
					std::cout << "array B is a subset of array A\n";
					std::cout << "start fragment address: " << check_arr_B_is_sub_arr_A(array_one, array_two, size_one, size_two) << std::endl;
				}
				else
					std::cout << "pointer is nullptr\n";

				break;
			}
			case 4:
			{
				size_t length = 0;

				int* pointer_array = nullptr;
				int* pointer_new_array = nullptr;

				CASE4RETRY:
				std::cout << "enter the size of array: ";
				std::cin >> length;

				if (length < 2) goto CASE4RETRY;

				pointer_array = new int[length];

				std::cout << std::setw(10) << std::setiosflags(std::ios::left) << "array:" << '|';
				for (size_t i = 0; i < length; ++i)
				{
					pointer_array[i] = rand() % 41 - 20;
					std::cout << std::setw(3) << pointer_array[i] << '|';
				}
				std::cout << '\n' << std::endl;

				pointer_new_array = array_without_negative_numbers(pointer_array, length);

				if (pointer_new_array != nullptr)
				{
					std::cout << '\n' << std::setw(10) << std::setiosflags(std::ios::left) << "new array:" << '|';
					for (size_t i = 0; i < length; ++i)
					{
						std::cout << std::setw(3) << pointer_new_array[i] << '|';
					}
					std::cout << '\n' << std::endl;

					delete[] pointer_new_array;
				}
				else
				{
					std::cout << "there are no negative elements in the array, repeat the operation" << std::endl;
				}

				break;
			}
			case 5:
			{
				const size_t size = 5;

				size_t length = 0;

				int* pointer_array = nullptr;

				int array_add[size] = { 1, 2, 3, 4, 5 };

				CASE5RETRY:
				std::cout << "enter the size of array: ";
				std::cin >> length;

				if (length < 2) goto CASE5RETRY;

				pointer_array = new int[length];

				std::cout << '\n' << std::setw(10) << std::setiosflags(std::ios::left) << "array:" << '|';
				for (size_t i = 0; i < length; ++i)
				{
					pointer_array[i] = rand() % 41 - 20;
					std::cout << std::setw(3) << pointer_array[i] << '|';
				}
				std::cout << '\n' << std::endl;

				pointer_array = add_elem_end_arr(pointer_array, array_add, length, size);

				std::cout << '\n' << std::setw(10) << std::setiosflags(std::ios::left) << "new array:" << '|';
				for (size_t i = 0; i < length + size; ++i)
				{
					std::cout << std::setw(3) << pointer_array[i] << '|';
				}
				std::cout << '\n' << std::endl;

				delete[] pointer_array;

				break;
			}
			case 6:
			{
				const size_t size = 5;

				size_t length = 0;

				int index = 0;

				int* pointer_array = nullptr;

				int array_add[size] = { 1, 2, 3, 4, 5 };

				CASE6RETRY:
				std::cout << "enter the size of array: ";
				std::cin >> length;

				if (length < 2) goto CASE6RETRY;

				RETRYADD:
				std::cout << "enter index add block of elements: ";
				std::cin >> index;

				if (index < 1 || index > length + 1) goto RETRYADD;

				pointer_array = new int[length];

				std::cout << '\n' << std::setw(10) << std::setiosflags(std::ios::left) << "array:" << '|';
				for (size_t i = 0; i < length; ++i)
				{
					pointer_array[i] = rand() % 41 - 20;
					std::cout << std::setw(3) << pointer_array[i] << '|';
				}
				std::cout << '\n' << std::endl;

				pointer_array = add_elem_anywhere_arr(pointer_array, array_add, length, size, index);

				std::cout << '\n' << std::setw(10) << std::setiosflags(std::ios::left) << "new array:" << '|';
				for (size_t i = 0; i < length + size; ++i)
				{
					std::cout << std::setw(3) << pointer_array[i] << '|';
				}
				std::cout << '\n' << std::endl;

				delete[] pointer_array;

				break;
			}
			case 7:
			{

				size_t length = 0;

				int index = 0;

				int* pointer_array = nullptr;

				CASE7RETRY:
				std::cout << "enter the size of array: ";
				std::cin >> length;

				if (length < 2) goto CASE7RETRY;

				RETRYDELETE:
				std::cout << "enter index add block of elements: ";
				std::cin >> index;

				if (index < 1 || index > length) goto RETRYDELETE;

				pointer_array = new int[length];

				std::cout << '\n' << std::setw(10) << std::setiosflags(std::ios::left) << "array:" << '|';
				for (size_t i = 0; i < length; ++i)
				{
					pointer_array[i] = rand() % 41 - 20;
					std::cout << std::setw(3) << pointer_array[i] << '|';
				}
				std::cout << '\n' << std::endl;

				pointer_array = remov_elem_arr(pointer_array, index);

				std::cout << '\n' << std::setw(10) << std::setiosflags(std::ios::left) << "new array:" << '|';
				for (size_t i = 0; i < index - 1; ++i)
				{
					std::cout << std::setw(3) << pointer_array[i] << '|';
				}
				std::cout << '\n' << std::endl;

				delete[] pointer_array;

				break;
			}
			default:
				std::cout << "select the correct menu item" << std::endl;
				break;
		}
		std::cout << "continue(1.yes/0.no): ";
		std::cin >> choise;
	} while (choise);
	system("pause");
	return 0;
}

/*
Задание 1. Написать функцию, которая получает указатель на массив и его размер, и возвращает сумму и произведение его элементов в двух параметрах-указателях.

Задание 2. Написать функцию, которая получает указатель на массив и его размер, и возвращает количество отрицательных, положительных и нулевых элементов массива.

Задание 3. Написать функцию, принимающую в качестве аргумента, указатели на два массива (А и В) и размеры массивов. Функция проверяет, является ли массив В подмножеством массива А и возвращает указатель на начало найденного фрагмента, либо возвращает 0 в противном случае.

Задание 4. Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все отрицательные числа и вернуть указатель на новый динамический массив.

Задание 5. Создать функцию, позволяющую добавлять блок элементов в конец массива.

Задание 6. Создать функцию, позволяющую вставлять блок элементов, начиная с произвольного индекса массива.

Задание 7. Создать функцию, позволяющую удалять блок элементов, начиная с произвольного индекса массива.
*/
