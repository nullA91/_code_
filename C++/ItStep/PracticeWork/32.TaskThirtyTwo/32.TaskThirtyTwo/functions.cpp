#include "functions.h"

void del_str_contain_zero_elem(int**& matrix, size_t& rows, size_t& columns)
{
	size_t length = 0;

	bool* flags = nullptr;

	int** pointer_new_matrix = nullptr;

	length = rows;
	flags = new bool[rows];
	for (size_t i = 0; i < rows; ++i)
	{
		flags[i] = true;
	}

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			if (matrix[i][j] == 0)
			{
				--length;
				flags[i] = false;
				break;
			}
		}
	}
	pointer_new_matrix = new int* [length];
	for (size_t i = 0; i < length; ++i)
	{
		pointer_new_matrix[i] = new int[columns];
	}

	for (size_t i = 0, index = 0; i < rows; ++i)
	{
		if (flags[i])
		{
			for (size_t j = 0; j < columns; ++j)
			{
				pointer_new_matrix[index][j] = matrix[i][j];
			}
			index++;
		}
	}

	for (size_t i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;

	rows = length;
	matrix = pointer_new_matrix;
}

void matrix_summation(int**& first_matrix, int**& second_matrix, int**& third_matrix, const size_t & rows, const size_t & columns)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			third_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
		}
	}
}

void matrix_product(int**& first_matrix, int**& second_matrix, int**& third_matrix, const size_t& rows_first_m, const size_t& columns_first_m, const size_t& rows_second_m, const size_t& columns_second_m)
{
	/*
	for (size_t i = 0; i < rows_first_m; ++i)
	{
		for (size_t j = 0; j < columns_second_m; ++j)
		{
			third_matrix[i][j] = 0;
		}
	}
	*/
	for (size_t i = 0; i < rows_first_m; ++i)
	{
		for (size_t j = 0; j < columns_second_m; ++j)
		{
			third_matrix[i][j] = 0;
			for (size_t k = 0; k < columns_first_m; ++k)
			{
				third_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
			}
		}
	}
}

char* _convert_ANSI_string_to_ASCII_string(const char string[])
{
	char* _new_string = new char[strlen(string) + 2];

	int i = 0;

	while (string[i] != '\0')
	{
		unsigned char symbol = string[i];

		if ((symbol >= 192) && (symbol <= 255))
			if (symbol < 240)
				_new_string[i] = string[i] - 64;
			else
				_new_string[i] = string[i] - 16;
		else
			_new_string[i] = string[i];
		i++;
	}

	_new_string[i] = '\0';

	return _new_string;
}

char* _convert_ANSI_string_to_ASCII_string(char string[])
{
	char* _new_string = new char[strlen(string) + 2];

	int i = 0;

	while (string[i] != '\0')
	{
		unsigned char symbol = string[i];

		if ((symbol >= 192) && (symbol <= 255))
			if (symbol < 240)
				_new_string[i] = string[i] - 64;
			else
				_new_string[i] = string[i] - 16;
		else
			_new_string[i] = string[i];
		i++;
	}

	_new_string[i] = '\0';

	return _new_string;
}

void menu_output()
{
	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < 14; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185);
	std::cout << _convert_ANSI_string_to_ASCII_string("опереции над матрицами");
	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 18; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(187) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << _convert_ANSI_string_to_ASCII_string("1. удаление строк содержащих нулевые элементы.          ");
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
	{
		if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << _convert_ANSI_string_to_ASCII_string("2. сумма двух матриц.                                   ");
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
	{
		if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << _convert_ANSI_string_to_ASCII_string("3. произведение двух матриц.                            ");
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(204);
	for (size_t i = 0; i < 56; ++i)
	{
		if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	
	std::cout << static_cast<char>(185) << '\n';
	std::cout << static_cast<char>(186);
	std::cout << _convert_ANSI_string_to_ASCII_string("0. выход.                                               ");
	std::cout << static_cast<char>(186) << '\n';

	std::cout << static_cast<char>(200);
	for (size_t i = 0; i < 56; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(188) << '\n';
}

void matrix_output(int**& matrix, const size_t& rows, const size_t& columns)
{
	const int elem_size = 4;

	std::cout << static_cast<char>(201);
	for (size_t i = 0, k = 0; i < columns * (elem_size + 1) - 1; ++i)
	{
		if (i == (k + elem_size))
		{
			std::cout << static_cast<char>(203);
			k += elem_size + 1;
		}
		else if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(187) << '\n';

	for (size_t i = 0; i < rows; ++i)
	{
		std::cout << static_cast<char>(186);
		for (size_t j = 0; j < columns; ++j)
		{
			std::cout << std::setw(elem_size) << matrix[i][j];
			std::cout << static_cast<char>(186);
		}
		std::cout << std::endl;
	}

	std::cout << static_cast<char>(200);
	for (size_t i = 0, k = 0; i < columns * (elem_size + 1) - 1; ++i)
	{
		if (i == (k + elem_size))
		{
			std::cout << static_cast<char>(202);
			k += elem_size + 1;
		}
		else if (i % 2 == 0)
			std::cout << static_cast<char>(205);
		else
			std::cout << ' ';
	}
	std::cout << static_cast<char>(188) << '\n';
}

/*
third_matrix[i][j] = 0;
for (size_t k = 0; k < columns_second_m; ++k)
{
	third_matrix += first_matrix[i][k] * second_matrix[k][j];
}
*/

/*
for (size_t i = 0; i < rows_first_m; ++i)
	{
		for (size_t j = 0; j < columns_second_m; ++j)
		{
			third_matrix[i][j] += first_matrix[i][j] * second_matrix[j][i];
		}
	}
*/

/*
int ind = 0;
for (size_t i = 0; i < rows_first_m; ++i)
{
	ind = 0;
	for (size_t j = 0; j < columns_second_m; ++j)
	{
		third_matrix[i][j] += first_matrix[i][ind] * second_matrix[ind][j];
		ind++;
	}
}
*/