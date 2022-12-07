#ifndef NUMBER_U_H
#define NUMBER_U_H

#include "Headers/Structures/bitrepresentation.h"

#define size 4

union Number
{
    struct BitRepresentation bit;
    unsigned int number_u;
    signed int number_s;
    char byte_representation[size];
};

#endif // NUMBER_U_H
