#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <Windows.h>

static int attempt = 0;
static int part = 1;

const char symbol = static_cast<char>(254);

const int rows = 30;
const int columns = 50;

const int _step_row = 3;
const int _step_column = 5;

void _function_output_filed(const char field[rows][columns]);
void _function_console_cursor(int x, int y);
<<<<<<< HEAD
int length(int array[]);
=======
int length(int array[]);
>>>>>>> 0d80803abda4533978ae41c6cf0c9b47261bce0f
