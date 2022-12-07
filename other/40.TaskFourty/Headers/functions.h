#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../../Headers/file.h"

unsigned int numberWordsFile(struct File* file, const char symbol, const int TYPE);
unsigned int numberCharactersFile(struct File* file, const int TYPE);

void menu(void);

#endif // FUNCTIONS_H
