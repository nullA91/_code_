#pragma once

#define _CRT_SECURE_NO_WARRNINGS

#include <cstring>
#include <iostream>

char* _convert_ANSI_string_to_ASCII_string(const char string[]); // функция конвертации ANSI строки в строку формата ASCII пренимающая константную строку
char* _convert_ANSI_string_to_ASCII_string(char string[]); // функция конвертации ANSI строки в строку формата ASCII пренимающая неконстантную строку

void _console_menu_creation_pyramid(const char* string, const size_t _max_length);
void _console_menu_creation(const char* string, const size_t _max_length); // функция создания меню в консоли
