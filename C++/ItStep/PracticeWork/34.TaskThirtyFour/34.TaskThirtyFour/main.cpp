#include "functions.h"
#include "libraries.h"
#include "structures.h"

/*
Задание 1. Создать структуру, описывающую прямоугольник. Написать функции для работы с этой
структурой: перемещение прямоугольника, изменение размера прямоугольника, печать прямоугольника.

Задание 2. Создайте структуру, описывающую точку в двумерной системе координат (x, y). С помощью этой
структуры задайте две точки. Напишите функцию, которая вычисляет расстояние между этими двумя точками?

Задание 3. Создайте структуру, описывающую простую дробь. Реализуйте арифметические операции с дробями:
сумму, разность, умножение, деление. Учесть возможность сокращения дробей и перевод из неправильной дроби в простую.
*/
char symbol = '\0';

int main(int arg_c, char* arg_v[])
{
	geometric_figure rectangle;
	point A;
	point B;

	A.X = -2;
	A.Y = 4;
	B.X = 8.5;
	B.Y = 0.7;

	//std::cout << A.distance(B) << std::endl;

	simple_fraction fract = { 2625, 1350 };

	fract.fraction_reduction();
	fract.fraction_conversion();
	//std::cout << fract.numerator << ' ' << fract.denominator << ' ' << fract.whole_part << std::endl;
	//std::cout << std::endl;

	simple_fraction one = { 5, 12, 0, 0 };
	simple_fraction two = { -23, 12, 0, 0 };
	simple_fraction three = one.addition(two);

	/*
	std::cout << "whole part: " << three.whole_part << std::endl;
	std::cout << "numerator: " << three.numerator << std::endl;
	std::cout << "denominator: " << three.denominator << std::endl;
	std::cout << "sign: " << three.sign << std::endl;
	*/

	three.output(); // проблемы с выводом -1 1/2

	system("pause");
	return 0;
}