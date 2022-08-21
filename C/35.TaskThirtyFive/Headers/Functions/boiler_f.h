#ifndef BOILER_F_H
#define BOILER_F_H

#include "../Headers/libraries.h"
#include "../Headers/Structures/boiler.h"

void product_data_entry(struct Boiler* boiler);
void product_data_output(const struct Boiler* boiler);
void writing_data_file(const char* path, const struct Boiler* boiler);
void destruct_struct(const struct Boiler* boiler);

#endif // BOILER_F_H
