#ifndef SMOOTHING_IRON_H
#define SMOOTHING_IRON_H

#include "../Headers/Structures/smoothingiron.h"

void product_data_entry(struct SmoothingIron* smoothingIron);
void product_data_output(const struct SmoothingIron* smoothingIron);
void writing_data_file(const char* path, const struct SmoothingIron* smoothingIron);
void destruct_struct(const struct SmoothingIron* smoothingIron);

#endif // SMOOTHING_IRON_H
