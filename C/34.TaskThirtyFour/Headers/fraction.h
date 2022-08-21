#ifndef FRACTION_H
#define FRACTION_H

/*
Задание 3. Создайте структуру, описывающую простую
дробь. Реализуйте арифметические операции с дробями:
сумму, разность, умножение, деление.
Учесть возможность сокращения дробей и перевод
из неправильной дроби в простую.
*/

#include <stdio.h>
#include <stdlib.h>

struct Fraction
{
    int sign;

    int whole_part;
    int numerator;
    int denominator;

    size_t rows;
    size_t columns;

    char** view;
};
// установка значений дроби
int setSign(struct Fraction* fraction, int whole_part, int numerator, int denominator);
int setWholePart(int value, struct Fraction* fraction);
int setNumerator(int value, struct Fraction* fraction);
int setDenominator(int value, struct Fraction* fraction);
void setViewManual(struct Fraction* fraction);
void setViewAuto(struct Fraction* fraction);
// вывод дроби
void output_fraction(const struct Fraction* fraction, unsigned int Y, unsigned int X);
// арифметические операции с дробями
struct Fraction sum(const struct Fraction* fraction_one, const struct Fraction* fraction_two);
struct Fraction difference(const struct Fraction* fraction_one, const struct Fraction* fraction_two);
struct Fraction multiplication(const struct Fraction* fraction_one, const struct Fraction* fraction_two);
struct Fraction division(const struct Fraction* fraction_one, const struct Fraction* fraction_two);
// ******************************** //
// ***** преобразование дроби ***** //
// ******************************** //
// наименьшее общее кратное
int  LCM(const struct Fraction* fraction);
//сокращение дроби
void fraction_reduction(struct Fraction* fraction);
// ******************************** //
// ******************************** //
// ******************************** //
// меню функций дроби
void menu_fraction(struct Fraction* fraction);
#endif // FRACTION_H
