#include "functions.h"

#include <ctime>
/*
Задание 1. Написать программу, которая удаляет из двухмерного массива, заполненного случайными числами строки, содержащие нулевые элементы.
Задание 2. Написать программу, которая поэлементно суммирует два динамических двумерных массива, заполненных случайными числами и сохраняет
результат в третьем массиве. Размеры исходных массивов задаются пользователем.
Задание 3. Напишите функцию умножения матриц. Матрица представляет собой таблицу чисел. Произведением матрицы A размером M × N (M строк, N столбцов)
на матрицу B размером N × K является матрица C размером N × K такая, что c[i][j]= a1b1j + ai2b2j + ... + aiNbNj, для 1 <= i <= M и 1 <= j <= K, где
■ axy — элемент, находящийся на пересечении строки x и столбца y матрицы A;
■ bxy — элемент, находящийся на пересечении строки x и столбца y матрицы B;
■ cxy — элемент, находящийся на пересечении строки x и столбца y матрицы C.
*/

// min + rand() % (max - min + 1)
// с[i][j] = a[i][j] + b[i][j];

int main(int arg_c, char* arg_v[])
{
	srand(time(NULL));

	int choise = 0;

	do
	{
		system("cls");

		menu_output();
		std::cout << _convert_ANSI_string_to_ASCII_string("выберите пункт меню: ");
		std::cin >> choise;

		switch (choise)
		{
		case 1:
		{
			const int check = 2;

			size_t rows = 0;
			size_t columns = 0;

			int min = 0;
			int max = 0;

			int** matrix = nullptr;

			CINROW:
			std::cout << _convert_ANSI_string_to_ASCII_string("введите количество строк в матрице: ");
			std::cin >> rows;
			CINCOL:
			std::cout << _convert_ANSI_string_to_ASCII_string("введите количество столбцов в матрице: ");
			std::cin >> columns;

			if (rows < check)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("введенный размер строк не соответствует минимальному представлению матрицы\n");
				goto CINROW;
			}
			else if (columns < check)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("введенный размер столбцов не соответствует минимальному представлению матрицы\n");
				goto CINCOL;
			}

			matrix = new int* [rows];
			for (size_t i = 0; i < rows; ++i)
			{
				matrix[i] = new int[columns];
			}

			RETRY:
			std::cout << _convert_ANSI_string_to_ASCII_string("диапазон значений которыми будет заполнена матрица\n");
			std::cout << _convert_ANSI_string_to_ASCII_string("начальное значение: ");
			std::cin >> min;
			std::cout << _convert_ANSI_string_to_ASCII_string("конечное значение: ");
			std::cin >> max;

			if (min > max)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("начальное значение больше конечного\n");
				goto RETRY;
			}

			for (size_t i = 0; i < rows; ++i)
			{
				for (size_t j = 0; j < columns; ++j)
				{
					matrix[i][j] = min + rand() % (max - min + 1);
				}
			}

			matrix_output(matrix, rows, columns);
			del_str_contain_zero_elem(matrix, rows, columns);
			matrix_output(matrix, rows, columns);

			for (size_t i = 0; i < rows; ++i)
				delete[] matrix[i];
			delete[] matrix;
			break;
		}
		case 2:
		{
			size_t rows = 0;
			size_t columns = 0;

			int min = 0;
			int max = 0;

			int** first_matrix = nullptr;
			int** second_matrix = nullptr;
			int** third_matrix = nullptr;

			std::cout << _convert_ANSI_string_to_ASCII_string("введите размер матрицы: ");
			std::cin >> rows;
			columns = rows;

			RETRYCASE2:
			std::cout << _convert_ANSI_string_to_ASCII_string("диапазон значений которыми будет заполнена матрица\n");
			std::cout << _convert_ANSI_string_to_ASCII_string("начальное значение: ");
			std::cin >> min;
			std::cout << _convert_ANSI_string_to_ASCII_string("конечное значение: ");
			std::cin >> max;

			if (min > max)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("начальное значение больше конечного\n");
				goto RETRYCASE2;
			}
			first_matrix = new int* [rows];
			second_matrix = new int* [rows];
			third_matrix = new int* [rows];
			for (size_t i = 0; i < rows; ++i)
			{
				first_matrix[i] = new int[columns];
				second_matrix[i] = new int[columns];
				third_matrix[i] = new int[columns];
			}

			for (size_t i = 0; i < rows; ++i)
			{
				for (size_t j = 0; j < columns; ++j)
				{
					first_matrix[i][j] = min + rand() % (max - min + 1);
					second_matrix[i][j] = min + rand() % (max - min + 1);
				}
			}

			matrix_summation(first_matrix, second_matrix, third_matrix, rows, columns);
			matrix_output(first_matrix, rows, columns);
			matrix_output(second_matrix, rows, columns);
			matrix_output(third_matrix, rows, columns);

			for (size_t i = 0; i < rows; ++i)
			{
				delete[] first_matrix[i];
				delete[] second_matrix[i];
				delete[] third_matrix[i];
			}
			delete[] first_matrix;
			delete[] second_matrix;
			delete[] third_matrix;

			break;
		}
		case 3:
		{
			const int check = 2;

			size_t rows_first_m = 0;
			size_t columns_first_m = 0;
			size_t rows_second_m = 0;
			size_t columns_second_m = 0;

			int min = 0;
			int max = 0;

			int** first_matrix = nullptr;
			int** second_matrix = nullptr;
			int** third_matrix = nullptr;

			FIRSTROW:
			std::cout << _convert_ANSI_string_to_ASCII_string("введите количество строк для первой матрицы: ");
			std::cin >> rows_first_m;
			FIRSTCOL:
			std::cout << _convert_ANSI_string_to_ASCII_string("введите количество столбцов для первой матрицы: ");
			std::cin >> columns_first_m;
			if (rows_first_m < check)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("введенный размер строк не соответствует минимальному представлению матрицы\n");
				goto FIRSTROW;
			}
			else if (columns_first_m < check)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("введенный размер столбцов не соответствует минимальному представлению матрицы\n");
				goto FIRSTCOL;
			}
			FIRSTRANGE:
			std::cout << _convert_ANSI_string_to_ASCII_string("диапазон значений которыми будет заполнена матрица\n");
			std::cout << _convert_ANSI_string_to_ASCII_string("начальное значение: ");
			std::cin >> min;
			std::cout << _convert_ANSI_string_to_ASCII_string("конечное значение: ");
			std::cin >> max;
			if (min > max)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("начальное значение больше конечного\n");
				goto FIRSTRANGE;
			}
			first_matrix = new int* [rows_first_m];
			for (size_t i = 0; i < rows_first_m; ++i)
			{
				first_matrix[i] = new int[columns_first_m];
			}
			for (size_t i = 0; i < rows_first_m; ++i)
			{
				for (size_t j = 0; j < columns_first_m; ++j)
				{
					first_matrix[i][j] = min + rand() % (max - min + 1);
				}
			}

			rows_second_m = columns_first_m;
			SECONDCOL:
			std::cout << _convert_ANSI_string_to_ASCII_string("введите количество столбцов для второй матрицы: ");
			std::cin >> columns_second_m;
			if (columns_second_m < check)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("введенный размер столбцов не соответствует минимальному представлению матрицы\n");
				goto SECONDCOL;
			}
			SECONDRANGE:
			std::cout << _convert_ANSI_string_to_ASCII_string("диапазон значений которыми будет заполнена матрица\n");
			std::cout << _convert_ANSI_string_to_ASCII_string("начальное значение: ");
			std::cin >> min;
			std::cout << _convert_ANSI_string_to_ASCII_string("конечное значение: ");
			std::cin >> max;

			if (min > max)
			{
				std::cout << _convert_ANSI_string_to_ASCII_string("начальное значение больше конечного\n");
				goto SECONDRANGE;
			}
			second_matrix = new int* [rows_second_m];
			for (size_t i = 0; i < rows_second_m; ++i)
			{
				second_matrix[i] = new int[columns_second_m];
			}
			for (size_t i = 0; i < rows_second_m; ++i)
			{
				for (size_t j = 0; j < columns_second_m; ++j)
				{
					second_matrix[i][j] = min + rand() % (max - min + 1);
				}
			}

			//rows_first_m x columns_second_m;
			third_matrix = new int* [rows_first_m];
			for (size_t i = 0; i < rows_first_m; ++i)
			{
				third_matrix[i] = new int[columns_second_m];
			}

			matrix_product(first_matrix, second_matrix, third_matrix, rows_first_m, columns_first_m, rows_second_m, columns_second_m);
			matrix_output(first_matrix, rows_first_m, columns_first_m);
			matrix_output(second_matrix, rows_second_m, columns_second_m);
			matrix_output(third_matrix, rows_first_m, columns_second_m);

			for (size_t i = 0; i < rows_first_m; ++i)
				delete[] first_matrix[i];
			delete[] first_matrix;

			for (size_t i = 0; i < rows_second_m; ++i)
				delete[] second_matrix[i];
			delete[] second_matrix;

			for (size_t i = 0; i < rows_first_m; ++i)
				delete[] third_matrix[i];
			delete[] third_matrix;

			break;
		}
		default:
			break;
		}
		if (choise)
			system("pause");
	} while (choise);

	system("pause");
	return 0;
}