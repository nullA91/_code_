#include "structures.h"

void geometric_figure::moving()
{
	char symbol = '\0';

	static int X = 0;
	static int Y = 0;

	symbol = _getch();

	if (symbol == arrows)
	{
		symbol = _getch();

		if (symbol == down)
		{
			system("cls");
			++Y;
			output(X, Y);
		}
		else if (symbol == up)
		{
			if (Y > 0)
			{
				system("cls");
				--Y;
				output(X, Y);
			}
		}
		else if (symbol == left)
		{
			if (X > 0)
			{
				system("cls");
				--X;
				output(X, Y);
			}
		}
		else if (symbol == right)
		{
			system("cls");
			++X;
			output(X, Y);
		}
	}
}

void geometric_figure::resizing()
{
CINWIDTH:
	std::cout << convert_ANSI_string_to_ASCII_string("введите ширину прямоугольника: ");
	std::cin >> geometric_figure::width;
	if (width < 2)
	{
		std::cout << convert_ANSI_string_to_ASCII_string("введенная ширина слишком маленькая\n");
		goto CINWIDTH;
	}
CINLENGTH:
	std::cout << convert_ANSI_string_to_ASCII_string("введите длину прямоугольника: ");
	std::cin >> geometric_figure::length;
	if (length < 2)
	{
		std::cout << convert_ANSI_string_to_ASCII_string("введенная длина слишком маленькая\n");
		goto CINLENGTH;
	}
}

void geometric_figure::output(int& X, int& Y)
{
	int x = X;
	int y = Y;

	for (size_t i = 0; i < length; ++i)
	{
		cursor_position(x, y);
		for (size_t j = 0; j < width; ++j)
		{
			if (i == 0)
			{
				if (j == 0)
					std::cout << top_left_corner;
				else if (j > 0 && j < width - 1)
				{
					if (j % 2 == 0)
						std::cout << horizontal_border;
					else
						std::cout << ' ';
				}
				else
					std::cout << top_right_corner;
			}
			else if (i > 0 && i < length - 1)
			{
				if (j == 0 || j == width - 1)
					std::cout << vertical_border;
				else
					std::cout << ' ';
			}
			else
			{
				if (j == 0)
					std::cout << bottom_left_corner;
				else if (j > 0 && j < width - 1)
				{
					if (j % 2 == 0)
						std::cout << horizontal_border;
					else
						std::cout << ' ';
				}
				else
					std::cout << bottom_right_corner;
			}
		}
		++y;
	}
}
// ############################### //
// ############################### //
double point::distance(const point & point)
{
	double return_value = 0.0;

	return_value = sqrt(pow((point.X - this->X), 2) + pow(point.Y - this->Y, 2));

	return return_value;
}
// ############################### //
// ############################### //
simple_fraction simple_fraction::addition(const simple_fraction & fraction)
{
	simple_fraction temp_fraction = { 0, 0, 0 };

	if (this->whole_part == 0 && fraction.whole_part == 0)
	{
		if (this->denominator == fraction.denominator)
		{
			temp_fraction.numerator = this->numerator + fraction.numerator;
			temp_fraction.denominator = this->denominator;
			temp_fraction.whole_part = 0;
			if (temp_fraction.numerator < 0 || temp_fraction.denominator < 0)
			{
				sign = false;
				if (temp_fraction.numerator < 0)
				{
					temp_fraction.sign = false;
					temp_fraction.numerator = ~temp_fraction.numerator + 1;
				}
				if (temp_fraction.denominator < 0)
				{
					temp_fraction.sign = false;
					temp_fraction.denominator = ~temp_fraction.denominator + 1;
				}
			}
			temp_fraction.fraction_reduction();
			if (temp_fraction.numerator >= temp_fraction.denominator)
				temp_fraction.fraction_conversion();
		}
	}

	return temp_fraction;
}
////////////////////////////////////////////////////
simple_fraction simple_fraction::subtraction(const simple_fraction & fraction)
{
	simple_fraction temp_fraction = { 0, 0, 0 };

	int first_numerator = 0;
	int first_denominator = 0;
	int second_numerator = 0;
	int second_denominator = 0;
	int _whole_part = 0;

	first_numerator = this->numerator * fraction.denominator;
	second_numerator = fraction.numerator * this->denominator;
	first_denominator = this->denominator * fraction.denominator;
	second_denominator = fraction.denominator * this->denominator;
	_whole_part = this->whole_part - fraction.whole_part;
	if (first_numerator < second_numerator)
	{
		if (_whole_part > 0)
		{
			_whole_part--;
			first_numerator += first_denominator;
		}
	}

	temp_fraction.numerator = first_numerator - second_numerator;
	temp_fraction.denominator = first_denominator;
	temp_fraction.whole_part = _whole_part;
	temp_fraction.fraction_reduction();
	if(temp_fraction.numerator > temp_fraction.denominator)
		temp_fraction.fraction_conversion();

	return temp_fraction;
}
///////////////////////////////////////////////////
void simple_fraction::fraction_reduction()
{
	int* dividers = nullptr;
	int length = 0;
	int index = 0;
	int divider = 0;

	if (this->numerator < this->denominator)
	{
		for (size_t i = 2; i <= this->numerator; ++i)
		{
			if (this->numerator % i == 0)
			{
				++length;
				dividers = (int*)realloc(dividers, length * sizeof(int));
				dividers[index] = i;
				++index;
			}
		}
		for (size_t i = 0; i < length; ++i)
		{
			if (this->denominator % dividers[i] == 0)
			{
				divider = dividers[i];
			}
		}
		if (divider)
		{
			this->numerator /= divider;
			this->denominator /= divider;
		}
		free(dividers);
	}
	else
	{
		for (size_t i = 2; i <= this->denominator; ++i)
		{
			if (this->denominator % i == 0)
			{
				++length;
				dividers = (int*)realloc(dividers, length * sizeof(int));
				dividers[index] = i;
				++index;
			}
		}
		for (size_t i = 0; i < length; ++i)
		{
			if (this->numerator % dividers[i] == 0)
			{
				divider = dividers[i];
			}
		}
		if (divider)
		{
			this->numerator /= divider;
			this->denominator /= divider;
		}
		free(dividers);
	}
}

void simple_fraction::fraction_conversion()
{
	if (this->numerator == this->denominator)
	{
		this->whole_part += 1;
		this->numerator = 0;
		this->denominator = 0;
	}
	else
	{
		this->whole_part += this->numerator / this->denominator;
		this->numerator = this->numerator % this->denominator;
	}
}

void simple_fraction::output()
{
	int X = 0;
	int Y = 0;
	int digit_capacity = 0;
	int temp_variable = 0;

	if (this->whole_part != 0)
	{
		temp_variable = this->whole_part;
		while (temp_variable)
		{
			++digit_capacity;
			temp_variable /= 10;
		}
		// вывод целочисленной части дроби
		if (this->sign == 0)
		{
			++Y;
			cursor_position(X, Y);
			std::cout << '-';
			++X;
		}
		Y = 1;
		cursor_position(X, Y);
		std::cout << this->whole_part;
		
		if (numerator != 0 || denominator != 0)
		{
			// вывод числителя
			Y = 0;
			if (this->whole_part > 0)
			{
				X = digit_capacity;
			}
			else
			{
				X = digit_capacity + 1;
			}
			cursor_position(X, Y);
			std::cout << this->numerator;
			// вывод горизонтальной границы
			digit_capacity = 0;

			if (this->numerator > this->denominator)
				temp_variable = this->numerator;
			else
				temp_variable = this->denominator;

			while (temp_variable)
			{
				++digit_capacity;
				temp_variable /= 10;
			}

			++Y;
			for (size_t i = 0; i < digit_capacity; ++i)
			{
				cursor_position(X, Y);
				std::cout << horizontal_border;
				++X;
			}
			X -= digit_capacity;
			// вывод знаменателя
			++Y;
			cursor_position(X, Y);
			std::cout << this->denominator;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	else
	{
		if (this->sign == false)
		{
			Y = 1;
			cursor_position(X, Y);
			std::cout << static_cast<char>(196);
			X += 2;
		}

		digit_capacity = 0;

		if (this->numerator > this->denominator)
			temp_variable = this->numerator;
		else
			temp_variable = this->denominator;

		while (temp_variable)
		{
			++digit_capacity;
			temp_variable /= 10;
		}
		Y = 0;
		cursor_position(X, Y);
		std::cout << this->numerator;
		++Y;
		for (size_t i = 0; i < digit_capacity; ++i)
		{
			cursor_position(X, Y);
			std::cout << horizontal_border;
			++X;
		}
		X -= digit_capacity;
		++Y;
		cursor_position(X, Y);
		std::cout << this->denominator;
		std::cout << std::endl;
	}
}

// ~number + 1 - изменение знака ???