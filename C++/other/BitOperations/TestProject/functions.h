#pragma once

#include "GLOBAL.h"

void bin_rep_pos_int(const unsigned int* number);
UINT8 units_counter(const unsigned int* number);
UINT8 most_significant_bit_index(const unsigned int* number);
void set_one_bit(unsigned int* number, const unsigned int* position);
void set_null_bit(unsigned int* number, const unsigned int* position);
void inversion_bit(unsigned int* number, const unsigned int* position);
UINT8 counter_eleven(const unsigned int* number);
void swap_two_bits(unsigned int* number, const unsigned int* position_first, const unsigned int* position_last);
void strike_out_bit(unsigned int* number, const unsigned int* position);