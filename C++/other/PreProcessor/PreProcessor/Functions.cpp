#include "Functions.h"

// функции заполнения массива
void _fill_int_array_random_numbers(int* array, size_t size) {
	srand(static_cast<unsigned int>(time(NULL)));
	for (unsigned int i = 0; i < size; i++)
		array[i] = rand() % 21;
}

void _fill_double_array_random_numbers(double* array, size_t size) {
	srand(static_cast<unsigned int>(time(NULL)));
	for (unsigned int i = 0; i < size; i++)
		array[i] = rand() / 32767.0 * 21;
}

void _fill_char_array_random_numbers(char* array, size_t size) {
	srand(static_cast<unsigned int>(time(NULL)));
	for (unsigned int i = 0; i < size; i++)
		array[i] = static_cast<char>(rand() % 256);
}

// функции вывода массива на консоль
void _output_int_array(const int* array, size_t size) {
	printf("%s", "array: ");
	for (unsigned int i = 0; i < size; i++)
		printf("%c%d", '|', array[i]);
	printf("%c%c", '|', '\n');
}

void _output_double_array(const double* array, size_t size) {
	printf("%s", "array: ");
	for (unsigned int i = 0; i < size; i++)
		printf("%c%f", '|', array[i]);
	printf("%c%c", '|', '\n');
}

void _output_char_array(const char* array, size_t size) {
	printf("%s", "array: ");
	for (unsigned int i = 0; i < size; i++)
		printf("%c%c", '|', array[i]);
	printf("%c%c", '|', '\n');
}

// функции поиска минимального элемента
int search_int_minimum_element(const int* array, size_t size) {
	int minimum = array[0];
	for (unsigned int i = 1; i < size; i++)
		if (array[i] < minimum)
			minimum = array[i];
	return minimum;
}

double search_double_minimum_element(const double* array, size_t size) {
	double minimum = array[0];
	for (unsigned int i = 1; i < size; i++)
		if (array[i] < minimum)
			minimum = array[i];
	return minimum;
}

char search_char_minimum_element(const char* array, size_t size) {
	char minimum = array[0];
	for (unsigned int i = 1; i < size; i++)
		if (array[i] < minimum)
			minimum = array[i];
	return minimum;
}

// функции поиска максимального элемента
int search_int_maximum_element(const int* array, size_t size) {
	int maximum = array[0];
	for (unsigned int i = 1; i < size; i++)
		if (array[i] > maximum)
			maximum = array[i];
	return maximum;
}

double search_double_maximum_element(const double* array, size_t size) {
	double maximum = array[0];
	for (unsigned int i = 1; i < size; i++)
		if (array[i] > maximum)
			maximum = array[i];
	return maximum;
}

char search_char_maximum_element(const char* array, size_t size) {
	char maximum = array[0];
	for (unsigned int i = 1; i < size; i++)
		if (array[i] > maximum)
			maximum = array[i];
	return maximum;
}

// функции сортировки массива
void _sorting_int_array(int* array, size_t size) {
	int _temporary_variable;
	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = size - 1; j > i; j--) {
			if (array[j] < array[i]) {
				_temporary_variable = array[i];
				array[i] = array[j];
				array[j] = _temporary_variable;
			}
		}
	}
}

void _sorting_double_array(double* array, size_t size) {
	double _temporary_variable;
	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = size - 1; j > i; j--) {
			if (array[j] < array[i]) {
				_temporary_variable = array[i];
				array[i] = array[j];
				array[j] = _temporary_variable;
			}
		}
	}
}

void _sorting_char_array(char* array, size_t size) {
	char _temporary_variable;
	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = size - 1; j > i; j--) {
			if (array[j] < array[i]) {
				_temporary_variable = array[i];
				array[i] = array[j];
				array[j] = _temporary_variable;
			}
		}
	}
}

// функции редактирования значения массива

void _change_value_int_array(int* array, size_t size, const int index, const int value) {
	(index > 0 && index < size) ? array[index] = value : printf("%s", "there is no index entered in the array, enter the correct index sequence number.\n");
}

void _change_value_double_array(double* array, size_t size, const int index, const double value) {
	(index > 0 && index < size) ? array[index] = value : printf("%s", "there is no index entered in the array, enter the correct index sequence number.\n");
}

void _change_value_char_array(char* array, size_t size, const int index, const char value) {
	(index > 0 && index < size) ? array[index] = value : printf("%s", "there is no index entered in the array, enter the correct index sequence number.\n");
}