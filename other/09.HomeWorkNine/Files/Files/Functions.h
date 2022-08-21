#pragma once

#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

// file functions
int file_open(FILE*& file, const  char* path);
void file_writing(FILE*& file, const char* string);
char* file_reading(FILE*& file);
bool file_close(FILE*& file, int& mode);
// menu output functions
int opening_mode();
void menu();
// functions for counting data in a file
int characters(FILE*& file, const char* path);
int lines(FILE*& file, const char* path);
int vowels(FILE*& file, const char* path);
int consonants(FILE*& file, const char* path);
int digits(FILE*& file, const char* path);
// функция нахождения букв
int letters(const char& symbol);
//
bool escape_sequences(const char& symbol);