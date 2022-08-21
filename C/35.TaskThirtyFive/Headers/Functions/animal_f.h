#ifndef ANIMAL_F_H
#define ANIMAL_F_H

#include "../Headers/libraries.h"
#include "../Headers/Structures/animal.h"

void product_data_entry(struct Animal* animal);
void product_data_output(const struct Animal* animal);
void writing_data_file(const char* path, const struct Animal* animal);
void destruct_struct(const struct Animal* animal);
void cast_vote(const struct Animal* animal, wchar_t* path);

#endif // ANIMAL_F_H
