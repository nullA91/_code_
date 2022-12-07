#ifndef FILE_H
#define FILE_H

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct File
{
    FILE* file_source;
    FILE* file_result;

    unsigned int rows_source;
    unsigned int columns_source;
    unsigned int rows_result;
    unsigned int columns_result;
};

int fileOpen(struct File* file, char* path, char* mode, int TYPE);
char** fileRead(struct File* file, int TYPE);
int fileWrite(struct File* file, char** arrayData, unsigned int rows, int TYPE);

#endif // FILE_H
