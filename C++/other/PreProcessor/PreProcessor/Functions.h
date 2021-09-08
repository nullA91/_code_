/*
Создать проект в котором :
1. создать три файла : (function.h, function.cpp, prog.cpp)
2. в файле function.cpp необходимо написать следующие функции для работы с массивом данных :

а) функцию для заполнения массива случайными значениями;
б) функцию для вывода значений массива на консоль;
в) функцию для поиска минимального элемента;
г) функцию для поиска максимального элемента;
д) функцию для сортировки;
е) функцию для редактирования значения массива.
Данные функции необходимо написать для работы с массивом целых, действительных и символьных значений. (Для каждого типа написать отдельную функцию) .
3. в файле function.h нужно :
а) описать прототипы всех функций;
4. в файле prog.cpp нужно :
a) сделать проверку определена ли константа, указывающая на тип данных(#ifdef INTEGER)
б) в функции main вызвать все функции .
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// условная конструкция для обобщения имен функций
#ifdef NINTEGER
#define _data_type int
#define _fill_array _fill_int_array_random_numbers
#define _output_array _output_int_array
#define _finding_minimum_item search_int_minimum_element
#define _finding_maximum_item search_int_maximum_element
#define _sorting_array _sorting_int_array
#define _change_value_array _change_value_int_array
#endif

#ifdef NDOUBLE
#define _data_type double
#define _fill_array _fill_double_array_random_numbers
#define _output_array _output_double_array
#define _finding_minimum_item search_double_minimum_element
#define _finding_maximum_item search_double_maximum_element
#define _sorting_array _sorting_double_array
#define _change_value_array _change_value_double_array
#endif

#ifdef NCHAR
#define _data_type char
#define _fill_array _fill_char_array_random_numbers
#define _output_array _output_char_array
#define _finding_minimum_item search_char_minimum_element
#define _finding_maximum_item search_char_maximum_element
#define _sorting_array _sorting_char_array
#define _change_value_array _change_value_char_array
#endif

// функции заполнения массива
void _fill_int_array_random_numbers(int* array, size_t size);

void _fill_double_array_random_numbers(double* array, size_t size);

void _fill_char_array_random_numbers(char* array, size_t size);

// функции вывода массива на консоль
void _output_int_array(const int* array, size_t size);

void _output_double_array(const double* array, size_t size);

void _output_char_array(const char* array, size_t size);

// функции поиска минимального элемента
int search_int_minimum_element(const int* array, size_t size);

double search_double_minimum_element(const double* array, size_t size);

char search_char_minimum_element(const char* array, size_t size);

// функции поиска максимального элемента
int search_int_maximum_element(const int* array, size_t size);

double search_double_maximum_element(const double* array, size_t size);

char search_char_maximum_element(const char* array, size_t size);

// функции сортировки массива
void _sorting_int_array(int* array, size_t size);

void _sorting_double_array(double* array, size_t size);

void _sorting_char_array(char* array, size_t size);

// функции редактирования значения массива

void _change_value_int_array(int* array, size_t size, const int index, const int value);

void _change_value_double_array(double* array, size_t size, const int index, const double value);

void _change_value_char_array(char* array, size_t size, const int index, const char value);
