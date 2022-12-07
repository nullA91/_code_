#include "../Headers/Triangle.h"

// воод данных треугольника
void Triangle::input()
{
	const unsigned int size = 10;

	char value[size];

	LENGTH:
	std::cout << "enter length of triangle: ";
	std::cin >> value;
	a = atoi(value);
	if (a <= 0) goto LENGTH;

	WIDTH:
	std::cout << "enter width of triangle: ";
	std::cin >> value;
	b = atoi(value);
	if (b <= 0) goto WIDTH;

	HEIGHT:
	std::cout << "enter height of triangle: ";
	std::cin >> value;
	c = atoi(value);
	if (c <= 0) goto HEIGHT;
}
// вывод данных треугольника
void Triangle::output()
{
	int type_triangle = 0;
	// если невозможно найти все стороны
	if ((a == 0 && b == 0) || (a == 0 && c == 0) || (b == 0 && c == 0))
	{
		system("cls"); std::cout << "error, two sides of triangle set to zero"; system("pause");
		return;
	}
	// нахождение третьей стороны, если известны две другие
	if (a == 0 && b != 0 && c != 0)
		a = sqrt((pow(c, 2) + pow(b, 2)));
	if(b == 0 && a != 0 && c != 0)
		b = sqrt((pow(c, 2) + pow(a, 2)));
	if(c == 0 && a != 0 && b != 0)
		c = sqrt((pow(b, 2) + pow(a, 2)));
	// если треугольник неправильный
	std::cout << a << '\t' << b << '\t' << c << std::endl; system("pause");
	if (c > a + b)
	{
		system("cls"); std::cout << "impossible to form a triangle" << std::endl; system("pause");
		return;
	}
	// если треугольник прямоугольный
	if (pow(c, 2) == (pow(a, 2) + pow(b, 2)))
		type_triangle = 0;
	// если треугольник остроугольный
	else if (pow(c, 2) < (pow(a, 2) + pow(b, 2)))
		type_triangle = 1;
	// если треугольник тупоугольный
	else if (pow(c, 2) > (pow(a, 2) + pow(b, 2)))
		type_triangle = -1;
	// прямоугольный треугольник
	if (type_triangle == 0)
	{
		int start = 0;
		int stop = 0;

		for (size_t i = 0; i < c; ++i)
		{
			std::cout << '|';
			stop = start;
			while (stop--)
				std::cout << ' ';
			std::cout << '\\';
			++start;
			std::cout << '\n';
		}
		std::cout << '|';
		for (size_t i = 0; i < c; ++i)
			std::cout << '-';
		std::cout << '\\' << '\n';
	}
	// остроугольный треугольник
	else if (type_triangle == 1)
	{
		int start = 0;
		int stop = 0;
		int peak = c;

		for (size_t i = 0; i < c; ++i)
		{
			for (int j = 0; j < peak; ++j)
				std::cout << ' ';
			std::cout << '/';
			stop = start;
			while (stop--)
				std::cout << ' ';
			std::cout << '\\';
			start += 2;
			std::cout << '\n';
			--peak;
		}
		std::cout << '/';
		for (size_t i = 0; i < c * 2; ++i)
			std::cout << '_';
		std::cout << '\\' << '\n';
	}
	// тупоугольный треугольник
	else if (type_triangle == -1)
	{
		int start = 0;
		int stop = 0;
		int peak = 0;

		for (int i = 0; i < c; ++i)
		{
			for (int j = 0; j < peak; ++j)
				std::cout << ' ';
			std::cout << '\\';
			stop = start;
			if (i != c - 1)
			{
				while (stop--)
					std::cout << ' ';
				std::cout << '.';
			}
			else
			{
				while (stop--)
					std::cout << '_';
				std::cout << '.';
			}
			start += 2;
			std::cout << '\n';
			++peak;
		}
	}
}
// перегрузка оператора ввода
std::istream& operator>>(std::istream& stream_input, Triangle triangle)
{
	const unsigned int size = 10;

	char value[size];

	LENGTH:
	std::cout << "enter length of triangle: ";
	std::cin >> value;
	triangle.a = atoi(value);
	if (triangle.a <= 0) goto LENGTH;

	WIDTH:
	std::cout << "enter width of triangle: ";
	std::cin >> value;
	triangle.b = atoi(value);
	if (triangle.b <= 0) goto WIDTH;

	HEIGHT:
	std::cout << "enter height of triangle: ";
	std::cin >> value;
	triangle.c = atoi(value);
	if (triangle.c <= 0) goto HEIGHT;

	return stream_input;
}

std::ostream& operator<<(std::ostream& stream_output, const Triangle& triangle)
{


	return stream_output;
}
