#pragma once

#include "GLOBAL.h"

void _function_drawing_field(char array[row][column]);
void _function_filling_field(char array[row][column]);
void _function_drawing_ship(char array[row][column], int _ship_size, char symbol);

void _function_dot_filling(char array[row][column], const char symbol);
void _function_dot_erasing(char array[row][column]);