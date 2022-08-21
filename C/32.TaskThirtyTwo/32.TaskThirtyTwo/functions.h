#pragma once
#include <cstring>
#include <iomanip>
#include <iostream>

char* _convert_ANSI_string_to_ASCII_string(const char string[]);
char* _convert_ANSI_string_to_ASCII_string(char string[]);

void del_str_contain_zero_elem(int**& matrix, size_t& rows, size_t& columns);
void matrix_summation(int**& first_matrix, int**& second_matrix, int**& third_matrix, const size_t& rows, const size_t& columns);
void matrix_product(int**& first_matrix, int**& second_matrix, int**& third_matrix, const size_t& rows_first_m, const size_t& columns_first_m, const size_t& rows_second_m, const size_t& columns_second_m);

void menu_output();
void matrix_output(int**& matrix, const size_t& rows, const size_t& columns);