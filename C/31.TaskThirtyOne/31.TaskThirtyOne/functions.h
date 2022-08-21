#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

void add_line_end(char**& array, size_t& rows, size_t& columns, const char* string);
void add_line_begin(char**& array, size_t& rows, size_t& columns, const char* string);
void add_line_index(char**& array, size_t& rows, size_t& columns, const char* string, const int& index);
void del_line_index(char**& array, size_t& rows, size_t& columns, const int& index);

void menu_output();

char* _convert_ANSI_string_to_ASCII_string(const char string[]);
char* _convert_ANSI_string_to_ASCII_string(char string[]);