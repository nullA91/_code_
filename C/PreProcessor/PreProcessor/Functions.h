/*
������� ������ � ������� :
1. ������� ��� ����� : (function.h, function.cpp, prog.cpp)
2. � ����� function.cpp ���������� �������� ��������� ������� ��� ������ � �������� ������ :

�) ������� ��� ���������� ������� ���������� ����������;
�) ������� ��� ������ �������� ������� �� �������;
�) ������� ��� ������ ������������ ��������;
�) ������� ��� ������ ������������� ��������;
�) ������� ��� ����������;
�) ������� ��� �������������� �������� �������.
������ ������� ���������� �������� ��� ������ � �������� �����, �������������� � ���������� ��������. (��� ������� ���� �������� ��������� �������) .
3. � ����� function.h ����� :
�) ������� ��������� ���� �������;
4. � ����� prog.cpp ����� :
a) ������� �������� ���������� �� ���������, ����������� �� ��� ������(#ifdef INTEGER)
�) � ������� main ������� ��� ������� .
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// �������� ����������� ��� ��������� ���� �������
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

// ������� ���������� �������
void _fill_int_array_random_numbers(int* array, size_t size);

void _fill_double_array_random_numbers(double* array, size_t size);

void _fill_char_array_random_numbers(char* array, size_t size);

// ������� ������ ������� �� �������
void _output_int_array(const int* array, size_t size);

void _output_double_array(const double* array, size_t size);

void _output_char_array(const char* array, size_t size);

// ������� ������ ������������ ��������
int search_int_minimum_element(const int* array, size_t size);

double search_double_minimum_element(const double* array, size_t size);

char search_char_minimum_element(const char* array, size_t size);

// ������� ������ ������������� ��������
int search_int_maximum_element(const int* array, size_t size);

double search_double_maximum_element(const double* array, size_t size);

char search_char_maximum_element(const char* array, size_t size);

// ������� ���������� �������
void _sorting_int_array(int* array, size_t size);

void _sorting_double_array(double* array, size_t size);

void _sorting_char_array(char* array, size_t size);

// ������� �������������� �������� �������

void _change_value_int_array(int* array, size_t size, const int index, const int value);

void _change_value_double_array(double* array, size_t size, const int index, const double value);

void _change_value_char_array(char* array, size_t size, const int index, const char value);
