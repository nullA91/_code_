#pragma once

#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int file_open(FILE*& file);
void file_writing(FILE*& file);
char* file_reading(FILE*& file);
bool file_close(FILE*& file, int& mode);
// 
int opening_mode();
void menu();
//
int characters(FILE*& file, const char* path);
int lines(FILE*& file, const char* path);
int vowels(FILE*& file, const char* path);
int consonants(FILE*& file, const char* path);
int digits(FILE*& file, const char* path);
//
int letters(const char& symbol);