#include "..\Headers\ComplexNumber.h"

int Complex::object_counter = 0;

// перегрузка оператора >>
std::istream& operator>>(std::istream& input_stream, Complex& complex_number)
{
	std::cout << "enter real part of complex number: ";
	input_stream >> complex_number.Rez;
	std::cout << "enter imaginary part of complex number: ";
	input_stream >> complex_number.Imz;

	return input_stream;
}
// перегрузка оператора << 
std::ostream& operator<<(std::ostream& output_stream, const Complex& complex_number)
{
	bool sign = false;

	char** view = nullptr;
	char* number = nullptr;

	const unsigned char border = 197;
	const unsigned char point = 254;

	unsigned int A = 0;
	unsigned int B = 0;
	unsigned int rows = 0;
	unsigned int columns = 0;
	unsigned int digit_capacity = 0;

	int counter = 0;
	int figure = 0;
	int index = 0;

	int x = 0;
	int y = 0;

	A = (complex_number.Rez < 0) ? -(complex_number.Rez) : complex_number.Rez;
	B = (complex_number.Imz < 0) ? -(complex_number.Imz) : complex_number.Imz;

	if (A == 0 && B == 0)
	{
		rows = 5;
		columns = 11;
	}
	else
	{
		rows = (A >= B) ? A : B;
		rows *= 2;
		++rows;
		columns = rows * 2;
		++columns;
	}
	// выделение памяти
	view = new char*[rows];
	for (size_t i = 0; i < rows; ++i)
		view[i] = new char[columns];
	// создание координатной плоскости
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			if (i == rows / 2 && j != columns / 2)
			{
				view[i][j] = border;
				view[i][++j] = unsigned char(196);
			}
			else if (j == columns / 2)
				view[i][j] = border;
			else
				view[i][j] = ' ';
		}
	}
	view[rows / 2][columns / 2] = border;
	// координаты точки
	if (A != B)
	{
		// видимая координата по оси X
		if (complex_number.Rez > 0)
		{
			x = columns / 2;
			++x;
			counter = 0;
			while (counter < A - 1)
			{
				x += 2;
				++counter;
			}
		}
		else if (complex_number.Rez < 0)
		{
			x = columns / 2;
			++x;
			counter = 0;
			while (counter < A)
			{
				x -= 2;
				++counter;
			}
		}
		else x = columns / 2;
		// видимая координата по оси Y
		if (complex_number.Imz > 0)
			y = rows / 2 - B;
		else if (complex_number.Imz < 0)
			y = rows / 2 + B;
		else y = rows / 2;
	}
	else if(A == B)
	{
		// видимая координата по оси X
		if (complex_number.Rez > 0)
			x = complex_number.Rez * 4;
		else if (complex_number.Rez < 0)
			x = 2;
		else x = columns / 2;
		// видимая координата по оси Y
		if (complex_number.Imz > 0)
			y = 0;
		else if (complex_number.Imz < 0)
			y = rows - 1;
		else
			y = rows / 2;
	}
	sign = (y < rows / 2) ? true : false;
	view[y][x] = point;
	// точки
	if (A != 0 && B != 0)
	{
		if (y < rows / 2)
		{
			for (size_t i = y, j = x; i < rows / 2; ++i)
			{
				if (i == y)
				{
					if (x > columns / 2)
					{
						for (size_t k = columns / 2 + 1; k < x; ++k)
							view[i][k] = '.';
					}
					else if (x < columns / 2)
					{
						for (size_t k = columns / 2 - 1; k > x; --k)
							view[i][k] = '.';
					}
				}
				else view[i][j] = '.';
			}
		}
		else if (y > rows / 2)
		{
			for (size_t i = y, j = x; i > rows / 2; --i)
			{
				if (i == y)
				{
					if (x > columns / 2)
					{
						for (size_t k = columns / 2 + 1; k < x; ++k)
							view[i][k] = '.';
					}
					else if (x < columns / 2)
					{
						for (size_t k = columns / 2 - 1; k > x; --k)
							view[i][k] = '.';
					}
				}
				else view[i][j] = '.';
			}
		}
	}
	// ******************** //
	// ****** ВЫВОД ******* //
	// ******************** //
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
			output_stream << view[i][j];
		output_stream << '\n';
	} std::cout << "result: " << complex_number.Rez;
	if (sign) std::cout << '+';
	std::cout << complex_number.Imz << 'i' << std::endl;
	// возврат потока
	return output_stream;
}
// запись данных в файл
std::ofstream& operator<<(std::ofstream& file, const Complex& complex_number)
{
	bool execution = true;
	bool flag = true;

	int X = 0;
	int Y = 0;
	int counter = 0;
	int start_point = 0;
	int stop_point = 0;

	unsigned int rows = 0;
	unsigned int columns = 0;

	const unsigned int multiplier = 8;
	const unsigned int divider = 2;
	const unsigned int step_col = 4;
	const unsigned int step_row = 2;

	X = (complex_number.Rez < 0) ? -complex_number.Rez : complex_number.Rez;
	Y = (complex_number.Imz < 0) ? -complex_number.Imz : complex_number.Imz;
	if ((X >= 0 && X < 5 || X <= 0 && X > -5) && (Y >= 0 && Y < 5 || Y <= 0 && Y > -5)) rows = columns = 5;
	else columns = rows = (X >= Y) ? X : Y;
	//std::cout << complex_number.Imz << std::endl; system("pause");
	rows = rows * step_col + 1;
	columns *= multiplier;
	// координата по оси X
	if (X)
	{
		counter = complex_number.Rez * step_col;
		X = columns / divider + counter;
		if (complex_number.Rez > 0 && complex_number.Imz != 0) X -= step_row;
	}
	else X = columns / divider;
	// координата по оси Y
	if (Y)
	{
		counter = rows / step_col;
		Y = 0;
		while (counter != complex_number.Imz)
		{
			Y += step_row;
			--counter;
			if (counter == 0) --counter;
		} if (complex_number.Imz <= 0) Y += step_row;
	}
	else Y = rows / divider;

	if (Y > rows / 2) flag = false;
	// координатная плоскость
	for (size_t i = 0; i < columns; ++i)
	{
		if (i == columns / divider)
			file.put('^');
		else
			file.put(' ');
	} file.put('\n');
	for (size_t i = 0; i < rows; ++i)
	{
		if (i != rows / divider)
		{
			if (i % 2 == 0)
			{
				for (size_t j = 0; j < columns + 1; ++j)
				{
					if (i == Y)
					{
						if (X > columns / divider)
						{
							while (j < X && j > columns / divider)
							{
								file.put('-');
								++j;
							}
						}
						else if (X < columns / divider)
						{
							while (j > X && j < columns / divider - step_row)
							{
								file.put('-');
								++j;
							}
						}
					}

					if (j == columns / divider - 1)
					{
						file.put('-');
						if (complex_number.Rez == 0 && i == Y)
						{
							file.put('o');
							execution = false;
						}
						else
							file.put('+');
						file.put('-');
					}
					else if (i == Y && j == X)
					{
						if (execution)
							file.put('o');
					}
					else if (i > Y && i < rows / divider && flag == true && j == X && complex_number.Rez != 0)
						file.put('.');
					else if (i < Y && i > rows / divider && flag == false && j == X && complex_number.Rez != 0)
						file.put('.');
					else
						file.put(' ');
				} file.put('\n');
			}
			else
			{
				if (i != rows / divider - 1 && i != rows / divider + 1)
				{
					for (size_t j = 0; j < columns + 1; ++j)
					{
						if (j == columns / divider)
							file.put('|');
						else if (i > Y && i < rows / divider && flag == true && j == X)
						{
							if (X > columns / divider)
							{
								file.put(' '); 
								file.put(' ');
								file.put('.');
								j += 3;
							}
							else
								file.put('.');
						}
						else if (i < Y && i > rows / divider && flag == false && j == X)
						{
							if (X > columns / divider)
							{
								file.put(' ');
								file.put(' ');
								file.put('.');
								j += 3;
							}
							else
								file.put('.');
						}
						else
							file.put(' ');
					} file.put('\n');
				}
			}
		}
		else
		{
			for (size_t j = 0; j < columns + step_col; ++j)
			{
				if (j % step_col == 0)
				{
					if (j == X && i == Y)
					{
						file.put('o');
						execution = false;
					}
					else
						file.put('|');
				}
				else if (i == Y && j == X)
				{
					if (execution)
						file.put('o');
				}
				else
					file.put('-');
			}
			file.put('>'); file.put('\n');
		}
	}
	/*
	file.write("Rez: " + complex_number.Rez, 10);
	file.put('\t');
	file.write("Imz: " + complex_number.Imz, 10);
	file.put('\n');
	*/
	for (size_t i = 0; i < columns + step_col; ++i)
		file.put('-');
	file.put('\n');

	return file;
}
// перегрузка оператора +
Complex Complex::operator+(const Complex& second_value)
{
	Complex number;

	number.Rez = this->Rez + second_value.Rez;
	number.Imz = this->Imz + second_value.Imz;

	return number;
}
// перегрузка оператора -
Complex Complex::operator-(const Complex & second_value)
{
	Complex number;

	number.Rez = this->Rez - second_value.Rez;
	number.Imz = this->Imz - second_value.Imz;

	return number;
}
// перегрузка оператора ==
bool Complex::operator==(const Complex & second_value)
{
	bool return_value = false;

	if (this->Rez == second_value.Rez && this->Imz == second_value.Imz)
		return_value = true;

	return return_value;
}
// перегрузка оператора !=
bool Complex::operator!=(const Complex & second_value)
{
	bool return_value = true;

	if (*this == second_value)
		return_value = false;

	return return_value;
}
