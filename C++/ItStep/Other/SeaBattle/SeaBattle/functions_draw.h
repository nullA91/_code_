#pragma once

#include "GLOBAL.h"

void _function_drawing_field(char field[rows][columns]);
void _function_filling_field(char field[rows][columns]);
void _function_drawing_ship(char field[rows][columns], const int _ship_size, const char symbol);

void _function_dot_filling(char field[rows][columns], const char symbol);
void _function_dot_erasing(char field[rows][columns]);