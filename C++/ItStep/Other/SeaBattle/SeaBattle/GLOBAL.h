#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

const char symbol = static_cast<char>(254);

const int row = 30;
const int column = 50;
const int size = 10;

const int r_step = 3;
const int c_step = 5;

const int rows[size] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28 };
const int columns[size] = { 2, 7, 12, 17, 22, 27, 32, 37, 42, 47 };

// const char b_letters[10]{ 'A','B','C','D','E','F','G','H','I','J' };
// const char s_letters[10]{ 'a','b','c','d','e','f','g','h','i','j' };

void _function_output_filed(char array[row][column], const int size);

static int attempt = 0;
static int part = 1;
static int hit = 0;