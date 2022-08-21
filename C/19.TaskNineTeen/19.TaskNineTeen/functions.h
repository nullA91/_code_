#pragma once
#include<iostream>

void output_rectangle(const int& width, const int& height);
int factorial(const int& number);
bool composite_number(const int& number);

template <typename data_type>
data_type cube_number(const data_type& number)
{
	return number * number* number;
}

template <typename data_type>
data_type max_number(const data_type& number_one, const data_type& number_two)
{
	if (number_two > number_one) return number_two;

	return number_one;
}

template <typename data_type>
bool check_number(const data_type& number)
{
	if (number > -1) return true;
	
	return false;
}