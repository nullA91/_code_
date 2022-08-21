#include <ctime>
#include <iostream>

const unsigned int zero = 0;

template<typename data_type>
data_type* add_elem_start(data_type* array, size_t& size, const data_type element);

template<typename data_type>
data_type* add_elem_index(data_type* array, size_t& size, const data_type element, const unsigned int index);

template<typename data_type>
data_type* rem_elem_start(data_type* array, size_t& size);

template<typename data_type>
data_type* rem_elem_end(data_type* array, size_t& size);

template<typename data_type>
data_type* rem_elem_index(data_type* array, size_t& size, const unsigned int index);

void menu_output();

int main(int arg_c, char* arg_v[])
{
	srand(time(zero));

	size_t size = 0;

	int element = 0;
	int index = 0;
	int choise = 0;

	int* pointer_array = nullptr;

	do
	{
		system("cls");

		menu_output();
		std::cout << "select menu item: ";
		std::cin >> choise;

		switch (choise)
		{
			case 1:
				CINSIZE:
				std::cout << "enter the size of the array: ";
				std::cin >> size;

				if (size < 1)
				{
					std::cout << "array must contain at least one element" << std::endl;
					goto CINSIZE;
				}

				pointer_array = new int[size];

				for (size_t i = 0; i < size; ++i)
				{
					*pointer_array++ = rand() % 21 + 1;
				}

				pointer_array -= size;
				std::cout << "array: |";
				for (size_t i = 0; i < size; ++i)
				{
					std::cout << *pointer_array++ << '|';
				}
				pointer_array -= size;
				std::cout << '\n' << std::endl;

				std::cout << "enter the value of the element to be added to the beginning of the array: ";
				std::cin >> element;

				pointer_array = add_elem_start(pointer_array, size, element);

				std::cout << "array: |";
				for (size_t i = 0; i < size; ++i)
				{
					std::cout << *pointer_array++ << '|';
				}
				pointer_array -= size;
				std::cout << '\n' << std::endl;
				break;
			case 2:
				if (size)
				{
					CININDEXADD:
					std::cout << "enter the position number in the array where you want to add the element: ";
					std::cin >> index;
					if (index < 1 || index > size)
					{
						std::cout << "the number entered exceeds the size of the array" << std::endl;
						goto CININDEXADD;
					}
					std::cout << "enter the value of the element to be added to the array: ";
					std::cin >> element;

					pointer_array = add_elem_index(pointer_array, size, element, index);

					std::cout << "array: |";
					for (size_t i = 0; i < size; ++i)
					{
						std::cout << *pointer_array++ << '|';
					}
					pointer_array -= size;
					std::cout << '\n' << std::endl;
				}
				else
					std::cout << "the array is empty, use the item adding an element to the beginning of an array" << std::endl;
				break;
			case 3:
				if (size)
				{
					pointer_array = rem_elem_start(pointer_array, size);

					std::cout << "array: |";
					for (size_t i = 0; i < size; ++i)
					{
						std::cout << *pointer_array++ << '|';
					}
					pointer_array -= size;
					std::cout << '\n' << std::endl;
				}
				else
					std::cout << "the array is empty, use the item adding an element to the beginning of an array" << std::endl;
				break;
			case 4:
				if (size)
				{
					pointer_array = rem_elem_end(pointer_array, size);

					std::cout << "array: |";
					for (size_t i = 0; i < size; ++i)
					{
						std::cout << *pointer_array++ << '|';
					}
					pointer_array -= size;
					std::cout << '\n' << std::endl;
				}
				else
					std::cout << "the array is empty, use the item adding an element to the beginning of an array" << std::endl;
				break;
			case 5:
				if (size)
				{
					CININDEXDEL:
					std::cout << "enter the position number in the array from which the element will be removed: ";
					std::cin >> index;
					if (index < 1 || index > size)
					{
						std::cout << "the number entered exceeds the size of the array" << std::endl;
						goto CININDEXDEL;
					}

					pointer_array = rem_elem_index(pointer_array, size, index);

					std::cout << "array: |";
					for (size_t i = 0; i < size; ++i)
					{
						std::cout << *pointer_array++ << '|';
					}
					pointer_array -= size;
					std::cout << '\n' << std::endl;
				}
				else
					std::cout << "the array is empty, use the item adding an element to the beginning of an array" << std::endl;
				break;

			case 0:
				std::cout << "the program is over" << std::endl;
				break;

			default:
				std::cout << "select the correct menu item" << std::endl;
				break;
		}

		if(choise)
			system("pause");
	} while (choise);

	delete[] pointer_array;
	system("pause");
	return 0;
}

template<typename data_type>
data_type* add_elem_start(data_type* array, size_t& size, const data_type element)
{
	const int start = 0;
	data_type* pointer_new_array = nullptr;
	
	++size;
	pointer_new_array = new data_type[size];
	pointer_new_array[start] = element;

	for (size_t i = 1, j = start; j < size - 1; ++i, ++j)
		pointer_new_array[i] = array[j];

	delete[] array;

	return pointer_new_array;
}

template<typename data_type>
data_type* add_elem_index(data_type* array, size_t& size, const data_type element, const unsigned int index)
{
	data_type* pointer_new_array = nullptr;

	++size;
	pointer_new_array = new data_type[size];
	pointer_new_array[index - 1] = element;

	for (size_t i = 0; i < index - 1; ++i)
		pointer_new_array[i] = array[i];
	for(size_t i = index; i < size; ++i)
		pointer_new_array[i] = array[i - 1];
	
	delete[] array;

	return pointer_new_array;
}

template<typename data_type>
data_type* rem_elem_start(data_type* array, size_t& size)
{
	data_type* pointer_new_array = nullptr;

	--size;
	pointer_new_array = new data_type[size];

	for (size_t i = 1; i <= size; ++i)
		pointer_new_array[i - 1] = array[i];

	delete[] array;

	return pointer_new_array;
}

template<typename data_type>
data_type* rem_elem_end(data_type* array, size_t& size)
{
	data_type* pointer_new_array = nullptr;

	--size;
	pointer_new_array = new data_type[size];

	for (size_t i = 0; i < size; ++i)
		pointer_new_array[i] = array[i];

	delete[] array;

	return pointer_new_array;
}

template<typename data_type>
data_type* rem_elem_index(data_type* array, size_t& size, const unsigned int index)
{
	data_type* pointer_new_array = nullptr;

	if (index == 1)
		rem_elem_start(array, size);
	else if (index == size)
		rem_elem_end(array, size);
	else
	{
		--size;

		pointer_new_array = new data_type[size];

		for (size_t i = 0; i < index - 1; ++i)
			pointer_new_array[i] = array[i];
		for (size_t i = index; i < size + 1; ++i)
			pointer_new_array[i - 1] = array[i];

		delete[] array;

		return pointer_new_array;
	}
}

void menu_output()
{
	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < 22; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185);
	std::cout << "menu";
	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 22; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(187) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 50; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "1. adding an element to the beginning of an array.";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 50; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "2. adding an element to an array by index.        ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 50; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "3. removing the first element of the array.       ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 50; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "4. removing the last element of the array.        ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 50; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "5. deleting an element in an array by index.      ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 50; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << "0. exit.                                          ";
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < 50; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(188) << '\n';
}

// min + rand() % (max - min + 1)