#ifndef WASHING_MACHINE_H
#define WASHING_MACHINE_H

#include "../Headers/libraries.h"
#include "../Structures/washingmachine.h"

void product_data_entry(struct WashingMachine* washingMachine);
void product_data_output(const struct WashingMachine* washingMachine);
void writing_data_file(const char* path, const struct WashingMachine* washingMachine);
void destruct_struct(const struct WashingMachine* washingMachine);

#endif // WASHING_MACHINE_H
