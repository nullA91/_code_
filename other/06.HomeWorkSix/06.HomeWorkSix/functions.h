#pragma once

#include "global.h"

long double calculator(const double& number_one, const double& number_two, const char& operation);

double triangle_area(const double& first_side, const double& second_side, const double& third_side);

bool triangle_check_existence(const double& first_side, const double& second_side, const double& third_side);

void filling_array(int* array, const size_t& size, const int& range);

int even_numbers(const int* array, const size_t& size);

int maximum_value(const int* array, const size_t& size);

int maximum_element_index(const int* array, const size_t& size);

int average(const int* array, const size_t& size);

int num_elem_larg_than_average_val_arr(const int* array, const size_t& size);
//////////////////////
void calculator_menu();
void triangle_menu();
void array_menu(const int* array, const size_t& size);