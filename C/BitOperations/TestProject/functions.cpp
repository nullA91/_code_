#include "functions.h"

// ������� ��������� ������������� ������ �������������� �����
void bin_rep_pos_int(const unsigned int* number)
{
	UINT8 size = 0;

	if (number < 0)
	{
		printf_s("%s\n", "������� ���������� ������");
		exit(1);
	}

	if (*number > 255) size = 15;
	else if (*number > 65535) size = 23;
	else if (*number > 4294967295) size = 31;
	else size = 7;

	for (int i = size; i >= 0; --i)
	{
		if (*number & (one << i)) printf_s("%c", '1');
		else printf_s("%c", '0');
	}
	printf_s("%c", '\n');
}
// ###########################################################

// ������� �������� ������ � �������� ������������� ������ �������������� �����
UINT8 units_counter(const unsigned int* number)
{
	UINT8 value = 0;
	UINT8 size = 0;

	if (*number > 255) size = 15;
	else if (*number > 65535) size = 23;
	else if (*number > 4294967295) size = 31;
	else size = 7;

	for (int i = size; i >= 0; --i)
	{
		if (*number & (one << i)) ++value;
	}

	return value;
}
// ###########################################################

// ������� ������� ����� �������� ���� � �������� ������������� ������ �������������� �����
UINT8 most_significant_bit_index(const unsigned int* number)
{
	UINT8 value = 0;
	UINT8 size = 0;

	if (*number > 255) size = 15;
	else if (*number > 65535) size = 23;
	else if (*number > 4294967295) size = 31;
	else size = 7;

	for (int i = size; i >= 0; --i)
	{
		if (*number & (one << i))
		{
			value = i;
			return value;
		}
	}

	return value;
}
// ###########################################################

// ������� ��������� ���������� ���� � ��������� �������
void set_one_bit(unsigned int* number, const unsigned int* position)
{
	*number |= (one << *position);
}
// ###########################################################

// ������� ��������� �������� ���� � ��������� �������
void set_null_bit(unsigned int* number, const unsigned int* position)
{
	*number &= ~(one << *position);
}
// ###########################################################

// ������� �������� ���� � ��������� �������
void inversion_bit(unsigned int* number, const unsigned int* position)
{
	*number ^= (one << *position);
}
// ###########################################################

// ������� ������� ������� ��� ����������� 11 � �������� ������������� �����
UINT8 counter_eleven(const unsigned int* number)
{
	UINT8 counter = 0;
	UINT8 size = 0;

	if (*number > 255) size = 15;
	else if (*number > 65535) size = 23;
	else if (*number > 4294967295) size = 31;
	else size = 7;

	for (int i = size; i >= 0; --i)
	{
		if ( static_cast<bool>((one << i) & *number) == 1 && static_cast<bool>((one << i+1) & *number) == 1 ) ++counter;
	}

	return counter;
}
// ###########################################################

// ������� ������ ������� ��� ���� � ��������� ��������
void swap_two_bits(unsigned int* number, const unsigned int* position_first, const unsigned int* position_last)
{
	bool bit_one = 0;
	bool bit_two = 0;

	bit_one = ((one << *position_first) & *number);
	bit_two = ((one << *position_last) & *number);

	(bit_one) ? *number |= (one << *position_last) : *number &= ~(one << *position_last);
	(bit_two) ? *number |= (one << *position_first) : *number &= ~(one << *position_first);
}
// ###########################################################

// ������� ����������� ��� � ��������� �������
void strike_out_bit(unsigned int* number, const unsigned int* position)
{
	UINT8 size = 0;

	if (*number > 255) size = 15;
	else if (*number > 65535) size = 23;
	else if (*number > 4294967295) size = 31;
	else size = 7;

	if( static_cast<bool>(((one << *position) & *number) == 1) ) *number &= ~(one << *position);

	for (int i = *position; i < size; ++i)
	{
		if (static_cast<bool>((*number & (one << i + 1))) == 1)
			*number |= (one << i);
		else
			*number &= ~(one << i);
	}

	*number &= ~(one << size);
}
// ###########################################################