#ifndef NUMBER_F_H
#define NUMBER_F_H

#include "Headers/libraries.h"
#include "Headers/Structures/bitrepresentation.h"
#include "Headers/Unions/number_u.h"

int input_number(union Number* _number);
void view_bytes_all(union Number* _number);
void view_byte(union Number* _number, const unsigned int index);
void byte_info(union Number* _number);
int write_data_file(union Number* _number, const char* path);

#endif // NUMBER_F_H
