#include "../../Headers/fraction.h"
#include "../../Headers/functions.h"

// установка значения знака дроби
int setSign(struct Fraction* fraction, int whole_part, int numerator, int denominator)
{
    if(whole_part < 0 && numerator < 0 && denominator < 0)
    {
        fraction->numerator = -numerator;
        fraction->denominator = -denominator;
        fraction->whole_part = -whole_part;
        fraction->sign = 1;
        return 1;
    }
    else if(whole_part < 0 && numerator >= 0 && denominator >= 0)
    {
        fraction->whole_part = -whole_part;
        fraction->sign = 1;
        return 1;
    }
    else if(whole_part >= 0 && numerator < 0 && denominator >= 0)
    {
        fraction->numerator = -numerator;
        fraction->sign = 1;
        return 1;
    }
    else if(whole_part >= 0 && numerator >= 0 && denominator < 0)
    {
        fraction->denominator = -denominator;
        fraction->sign = 1;
        return 1;
    }
    else
    {
        fraction->sign = 0;
        return 0;
    }
}
// установка значения целой части дроби
int setWholePart(int value, struct Fraction* fraction)
{
    int digit_capacity = 0;
    int temp_value = 0;

    if(fraction->numerator > fraction->denominator)
    {
        value += fraction->numerator / fraction->denominator;
    }

    if(value)
    {
        if(value < 0)
        {
            fraction->whole_part = -value;
            temp_value = -value;
        }
        else
        {
            fraction->whole_part = value;
            temp_value = value;
        }
        while(temp_value)
        {
            ++digit_capacity;
            temp_value /= 10;
        }

        return digit_capacity;
    }
    else
    {
        fraction->whole_part = 0;

        return digit_capacity;
    }
}
// установка значения числителя дроби
int setNumerator(int value, struct Fraction* fraction)
{

    int digit_capacity = 0;
    int temp_value = 0;

    if(value)
    {
        if(value < 0)
        {
            fraction->numerator = -value;
            temp_value = -value;
        }
        else
        {
            fraction->numerator = value;
            temp_value = value;
        }

        while(temp_value)
        {
            ++digit_capacity;
            temp_value /= 10;
        }

        return digit_capacity;
    }
    else
    {
        fraction->numerator = 0;

        return digit_capacity;
    }
}
// установка значения знаменателя дроби
int setDenominator(int value, struct Fraction* fraction)
{
    int digit_capacity = 0;
    int temp_value = 0;

    if(value)
    {
        if(value < 0)
        {
            fraction->denominator = -value;
            temp_value = -value;
        }
        else
        {
            fraction->denominator = value;
            temp_value = value;
        }
        while(temp_value)
        {
            ++digit_capacity;
            temp_value /= 10;
        }

        return digit_capacity;
    }
    else
    {
        fraction->denominator = 0;

        return digit_capacity;
    }
}
// настройка вида дроби
// ручная
void setViewManual(struct Fraction* fraction)
{
    int value = 0;
    int whole_part = 0;
    int numerator = 0;
    int denominator = 0;

    unsigned int columns[3] = { 0 };

    fraction->rows = 3;

    fraction->view = (char**)malloc(fraction->rows * sizeof (char*));

    // числитель
    NUMERATOR:
    printf_s("enter the numerator of the fraction: ");
    scanf("%i", &value);
    numerator = value;
    if(value)
        columns[0] = (unsigned int)setNumerator(value, fraction);
    else
        goto NUMERATOR;
    // знаменатель
    DENOMINATOR:
    printf_s("enter the denominator of the fraction: ");
    scanf("%i", &value);
    denominator = value;
    if(value)
        columns[2] = (unsigned int)setDenominator(value, fraction);
    else
        goto DENOMINATOR;
    // целая часть
    printf_s("enter the whole fraction: ");
    scanf("%i", &value);
    whole_part = value;
    if(value)
        columns[1] = (unsigned int)setWholePart(value, fraction);
    else
    {
        setWholePart(0, fraction);
        columns[1] = 1;
    }
    // знак дроби
    setSign(fraction, whole_part, numerator, denominator);
    // сокращение дроби
    fraction_reduction(fraction);
    columns[0] = (unsigned int)setNumerator(fraction->numerator, fraction);
    columns[2] = (unsigned int)setDenominator(fraction->denominator, fraction);

    if(columns[0] < columns[2])
        columns[0] = columns[2];

    fraction->columns = 0;
    fraction->columns += (columns[0]);
    fraction->columns += (columns[1]);

    ++(fraction->columns);

    for(size_t i = 0; i < fraction->rows; ++i)
    {
        if(i == 0)
            value = fraction->numerator;
        else if(i == 1)
            value = fraction->whole_part;
        else
            value = fraction->denominator;

        fraction->view[i] = (char*)malloc((fraction->columns + 1) * sizeof (char));

        if(i != 1)
        {
            for(int j = (int)(fraction->columns - 1); j > (int)(fraction->columns - columns[i] - 1); --j)
            {
                if(value)
                {
                    fraction->view[i][j] = value % 10 + 48;
                    value /= 10;
                }
                else
                {
                    fraction->view[i][j] = ' ';
                    value /= 10;
                }
            }
            for(size_t j = 0; j <= fraction->columns - columns[i] - 1; ++j)
                fraction->view[i][j] = ' ';
        }
        else
        {
            for(int j = (int)(fraction->columns - 1); j > (int)(columns[i]); --j)
            {
                fraction->view[i][j] = (char)22;
            }

            for(int j = (int)(columns[i]); j > 0; --j)
            {
                if(value)
                {
                    fraction->view[i][j] = value % 10 + 48;
                    value /= 10;
                }
                else
                    fraction->view[i][j] = ' ';
            }

            if(fraction->sign)
                fraction->view[i][0] = '-';
            else
                fraction->view[i][0] = ' ';
        }

        fraction->view[i][fraction->columns] = '\0';
    }
}
// автоматическая
void setViewAuto(struct Fraction* fraction)
{
    int value = 0;
    int digit_capcity = 0;

    unsigned int columns[3] = { 0 };

    fraction->rows = 3;

    fraction->view = (char**)malloc(fraction->rows * sizeof (char*));

    // числитель
    value = fraction->numerator;
    while(value)
    {
        ++digit_capcity;
        value /= 10;
    }
    columns[0] = (unsigned int)digit_capcity;
    digit_capcity = 0;
    // знаменатель
    value = fraction->denominator;
    while(value)
    {
        ++digit_capcity;
        value /= 10;
    }
    columns[2] = (unsigned int)digit_capcity;
    digit_capcity = 0;
    // целая часть
    value = fraction->whole_part;
    while(value)
    {
        ++digit_capcity;
        value /= 10;
    }
    columns[1] = (unsigned int)digit_capcity;
    digit_capcity = 0;

    if(columns[0] < columns[2])
        columns[0] = columns[2];

    fraction->columns = 0;
    fraction->columns += (columns[0]);
    fraction->columns += (columns[1]);

    ++(fraction->columns);

    for(size_t i = 0; i < fraction->rows; ++i)
    {
        if(i == 0)
            value = fraction->numerator;
        else if(i == 1)
            value = fraction->whole_part;
        else
            value = fraction->denominator;

        fraction->view[i] = (char*)malloc((fraction->columns + 1) * sizeof (char));

        if(i != 1)
        {
            for(int j = (int)(fraction->columns - 1); j > (int)(fraction->columns - columns[i] - 1); --j)
            {
                if(value)
                {
                    fraction->view[i][j] = value % 10 + 48;
                    value /= 10;
                }
                else
                {
                    fraction->view[i][j] = ' ';
                    value /= 10;
                }
            }
            for(size_t j = 0; j <= fraction->columns - columns[i] - 1; ++j)
                fraction->view[i][j] = ' ';
        }
        else
        {
            for(int j = (int)(fraction->columns - 1); j > (int)(columns[i]); --j)
            {
                fraction->view[i][j] = (char)22;
            }

            for(int j = (int)(columns[i]); j > 0; --j)
            {
                if(value)
                {
                    fraction->view[i][j] = value % 10 + 48;
                    value /= 10;
                }
                else
                    fraction->view[i][j] = ' ';
            }

            if(fraction->sign)
                fraction->view[i][0] = '-';
            else
                fraction->view[i][0] = ' ';
        }

        fraction->view[i][fraction->columns] = '\0';
    }
}
// вывод дроби
void output_fraction(const struct Fraction* fraction, unsigned int Y, unsigned int X)
{
    for(size_t i = 0; i < fraction->rows; ++i)
    {
        set_console_cursor(Y, X);
        for(size_t j = 0; j < fraction->columns; ++j)
            printf_s("%c", fraction->view[i][j]);
        ++Y;
    }
    printf_s("%c", '\n');
}
// наименьшее общее кратное
int  LCM(const struct Fraction* fraction)
{
    int divider = 0;
    int value = 0;

    // если числитель меньше знаменателя
    if(fraction->numerator < fraction->denominator)
    {
        for(int i = 2; i <= fraction->numerator; ++i)
        {
            if(fraction->numerator % i == 0)
            {
                divider = i;
                if(fraction->denominator % divider == 0)
                    value = divider;
                else
                    divider = 0;
            }
        }
    }
    // если числитель равен знаменателю
    else if(fraction->numerator == fraction->denominator) return 1;
    //если числитель больше знаменателя
    else
    {
        for(int i = 2; i <= fraction->denominator; ++i)
        {
            if(fraction->denominator % i == 0)
            {
                divider = i;
                if(fraction->numerator % divider == 0)
                    value = divider;
                else
                    divider = 0;
            }
        }
    }
    return value;
}
// сокращение дроби
void fraction_reduction(struct Fraction* fraction)
{
    int divider = 0;

    divider = LCM(fraction);

    if(divider)
    {
        if(divider != 1)
        {
            fraction->numerator = fraction->numerator / divider;
            fraction->denominator = fraction->denominator / divider;
        }
        else
        {
            fraction->whole_part += divider;
            fraction->numerator = 0;
            fraction->denominator = 0;
        }
    }

    if(fraction->numerator > fraction->denominator)
    {
        fraction->numerator = fraction->numerator % fraction->denominator;
        if(fraction->numerator == 0)
            fraction->denominator = 0;
    }
    else if(fraction->numerator == fraction->denominator)
    {
        fraction->numerator = 0;
        fraction->denominator = 0;
    }

    if(fraction->numerator == 0)
        fraction->denominator = 0;
}

// ******************************************************* //
// ********** арифметические операции с дробями ********** //
// ******************************************************* //
// сумма дробей
struct Fraction sum(const struct Fraction* fraction_one, const struct Fraction* fraction_two)
{
    int numerator_one = 0;
    int numerator_two = 0;
    int denominator_one = 0;
    int denominator_two = 0;

    int numerator = 0;
    int denominator = 0;

    struct Fraction fraction_result;

    // первая дробь
    if(fraction_one->numerator == 0 && fraction_one->denominator == 0)
    {
        numerator_one = fraction_one->whole_part;
        denominator_one = 1;
    }
    else
    {
        numerator_one = fraction_one->denominator * fraction_one->whole_part + fraction_one->numerator;
        denominator_one = fraction_one->denominator;
    }
    // вторая дробь
    if(fraction_two->numerator == 0 && fraction_two->denominator == 0)
    {
        numerator_two = fraction_two->whole_part;
        denominator_two = 1;
    }
    else
    {
        numerator_two = fraction_two->denominator * fraction_two->whole_part + fraction_two->numerator;
        denominator_two = fraction_two->denominator;
    }

    // установка знаков
    if(fraction_one->sign)
        numerator_one = -numerator_one;
    if(fraction_two->sign)
        numerator_two = -numerator_two;
    // сумма дробей
    if(denominator_one == denominator_two)
    {
        numerator = numerator_one + numerator_two;
        denominator = denominator_two;
    }
    else
    {
        numerator = (numerator_one * denominator_two) + (numerator_two * denominator_one);
        denominator = denominator_one * denominator_two;
    }

    fraction_result.numerator = numerator;
    fraction_result.denominator = denominator;
    setSign(&fraction_result, fraction_result.whole_part, fraction_result.numerator, fraction_result.denominator);
    setWholePart(0, &fraction_result);
    // сокращение дроби
    fraction_reduction(&fraction_result);
    // возврат значения
    setViewAuto(&fraction_result);
    return fraction_result;
}
// разность дробей
struct Fraction difference(const struct Fraction* fraction_one, const struct Fraction* fraction_two)
{
    int numerator_one = 0;
    int numerator_two = 0;
    int denominator_one = 0;
    int denominator_two = 0;

    int numerator = 0;
    int denominator = 0;

    struct Fraction fraction_result;

    // первая дробь
    if(fraction_one->numerator == 0 && fraction_one->denominator == 0)
    {
        numerator_one = fraction_one->whole_part;
        denominator_one = 1;
    }
    else
    {
        numerator_one = fraction_one->denominator * fraction_one->whole_part + fraction_one->numerator;
        denominator_one = fraction_one->denominator;
    }
    // вторая дробь
    if(fraction_two->numerator == 0 && fraction_two->denominator == 0)
    {
        numerator_two = fraction_two->whole_part;
        denominator_two = 1;
    }
    else
    {
        numerator_two = fraction_two->denominator * fraction_two->whole_part + fraction_two->numerator;
        denominator_two = fraction_two->denominator;
    }

    // установка знаков
    if(fraction_one->sign)
        numerator_one = -numerator_one;
    if(fraction_two->sign)
        numerator_two = -numerator_two;
    // разность дробей
    if(denominator_one == denominator_two)
    {
        numerator = numerator_one - numerator_two;
        denominator = denominator_two;
    }
    else
    {
        numerator = (numerator_one * denominator_two) - (numerator_two * denominator_one);
        denominator = denominator_one * denominator_two;
    }

    fraction_result.numerator = numerator;
    fraction_result.denominator = denominator;
    setSign(&fraction_result, fraction_result.whole_part, fraction_result.numerator, fraction_result.denominator);
    setWholePart(0, &fraction_result);
    // сокращение дроби
    fraction_reduction(&fraction_result);
    // возврат значения
    setViewAuto(&fraction_result);
    return fraction_result;
}
// произведение дробей
struct Fraction multiplication(const struct Fraction* fraction_one, const struct Fraction* fraction_two)
{
    int numerator_one = 0;
    int numerator_two = 0;
    int denominator_one = 0;
    int denominator_two = 0;

    int numerator = 0;
    int denominator = 0;

    struct Fraction fraction_result;

    // первая дробь
    if(fraction_one->numerator == 0 && fraction_one->denominator == 0)
    {
        numerator_one = fraction_one->whole_part;
        denominator_one = 1;
    }
    else
    {
        numerator_one = fraction_one->denominator * fraction_one->whole_part + fraction_one->numerator;
        denominator_one = fraction_one->denominator;
    }
    // вторая дробь
    if(fraction_two->numerator == 0 && fraction_two->denominator == 0)
    {
        numerator_two = fraction_two->whole_part;
        denominator_two = 1;
    }
    else
    {
        numerator_two = fraction_two->denominator * fraction_two->whole_part + fraction_two->numerator;
        denominator_two = fraction_two->denominator;
    }

    // установка знаков
    if(fraction_one->sign)
        numerator_one = -numerator_one;
    if(fraction_two->sign)
        numerator_two = -numerator_two;
    // произведение дробей
    numerator = numerator_one * numerator_two;
    denominator = denominator_one * denominator_two;

    fraction_result.numerator = numerator;
    fraction_result.denominator = denominator;
    setSign(&fraction_result, fraction_result.whole_part, fraction_result.numerator, fraction_result.denominator);
    setWholePart(0, &fraction_result);
    // сокращение дроби
    fraction_reduction(&fraction_result);
    // возврат значения
    setViewAuto(&fraction_result);
    return fraction_result;
}
// частное дробей
struct Fraction division(const struct Fraction* fraction_one, const struct Fraction* fraction_two)
{
    int numerator_one = 0;
    int numerator_two = 0;
    int denominator_one = 0;
    int denominator_two = 0;

    int numerator = 0;
    int denominator = 0;

    struct Fraction fraction_result;
    // первая дробь
    if(fraction_one->numerator == 0 && fraction_one->denominator == 0)
    {
        numerator_one = fraction_one->whole_part;
        denominator_one = 1;
    }
    else
    {
        numerator_one = fraction_one->denominator * fraction_one->whole_part + fraction_one->numerator;
        denominator_one = fraction_one->denominator;
    }
    // вторая дробь
    if(fraction_two->numerator == 0 && fraction_two->denominator == 0)
    {
        numerator_two = fraction_two->whole_part;
        denominator_two = 1;
    }
    else
    {
        numerator_two = fraction_two->denominator * fraction_two->whole_part + fraction_two->numerator;
        denominator_two = fraction_two->denominator;
    }

    // установка знаков
    if(fraction_one->sign)
        numerator_one = -numerator_one;
    if(fraction_two->sign)
        numerator_two = -numerator_two;
    // частное дробей
    numerator = numerator_one * denominator_two;
    denominator = denominator_one * numerator_two;

    fraction_result.numerator = numerator;
    fraction_result.denominator = denominator;
    setSign(&fraction_result, fraction_result.whole_part, fraction_result.numerator, fraction_result.denominator);
    setWholePart(0, &fraction_result);

    if(numerator < 0)
        fraction_result.numerator = -numerator;
    if(denominator < 0)
        fraction_result.denominator = - denominator;
    // сокращение дроби
    fraction_reduction(&fraction_result);
    // возврат значения
    setViewAuto(&fraction_result);
    return fraction_result;
}
// ******************************************************* //
// ******************************************************* //
// ******************************************************* //
// меню функций дроби
void menu_fraction(struct Fraction* fraction)
{
    struct Fraction fraction_one;
    struct Fraction fraction_two;

    unsigned int choise = 0;

    do
    {
        system("cls");
        printf_s("\t%s\n", "menu");
        printf_s("%s\n", "1. Entering a fraction");
        printf_s("%s\n", "2. Output fraction");
        printf_s("%s\n", "3. Sum of fractions");
        printf_s("%s\n", "4. Difference of fractions");
        printf_s("%s\n", "5. Multiplication of fractions");
        printf_s("%s\n", "6. Division of fractions");
        printf_s("%s\n", "0. EXIT");
        printf_s("select menu item: ");
        scanf("%u", &choise);

        system("cls");
        switch(choise)
        {
            case 1:
            {
                setViewManual(fraction);
                break;
            }
            case 2:
            {
                output_fraction(fraction, 0, 0);
                break;
            }
            case 3:
            {
                unsigned int Y = 0;
                unsigned int X = 0;

                setViewManual(&fraction_one);
                setViewManual(&fraction_two);
                *fraction = sum(&fraction_one, &fraction_two);
                // очистка консоли
                system("cls");
                // вывод первой дроби
                Y = 0;
                X = 0;
                output_fraction(&fraction_one, Y, X);
                // вывод знака +
                Y = 1;
                X = fraction_one.columns + 2;
                set_console_cursor(Y, X);
                printf_s("%c", '+');
                //вывод второй дроби
                Y = 0;
                X = fraction_one.columns + 4;
                output_fraction(&fraction_two, Y, X);
                // вывод знака равно
                Y = 1;
                X = fraction_one.columns + fraction_two.columns + 5;
                set_console_cursor(Y, X);
                printf_s("%c", '=');
                // вывод результата
                Y = 0;
                X = fraction_one.columns + fraction_two.columns + 7;
                output_fraction(fraction, Y, X);
                break;
            }
            case 4:
            {
                unsigned int Y = 0;
                unsigned int X = 0;

                setViewManual(&fraction_one);
                setViewManual(&fraction_two);
                *fraction = difference(&fraction_one, &fraction_two);
                // очистка консоли
                system("cls");
                // вывод первой дроби
                Y = 0;
                X = 0;
                output_fraction(&fraction_one, Y, X);
                // вывод знака -
                Y = 1;
                X = fraction_one.columns + 2;
                set_console_cursor(Y, X);
                printf_s("%c", '-');
                //вывод второй дроби
                Y = 0;
                X = fraction_one.columns + 4;
                output_fraction(&fraction_two, Y, X);
                // вывод знака равно
                Y = 1;
                X = fraction_one.columns + fraction_two.columns + 5;
                set_console_cursor(Y, X);
                printf_s("%c", '=');
                // вывод результата
                Y = 0;
                X = fraction_one.columns + fraction_two.columns + 7;
                output_fraction(fraction, Y, X);
                break;
            }
            case 5:
            {
                unsigned int Y = 0;
                unsigned int X = 0;

                setViewManual(&fraction_one);
                setViewManual(&fraction_two);
                *fraction = multiplication(&fraction_one, &fraction_two);
                // очистка консоли
                system("cls");
                // вывод первой дроби
                Y = 0;
                X = 0;
                output_fraction(&fraction_one, Y, X);
                // вывод знака *
                Y = 1;
                X = fraction_one.columns + 2;
                set_console_cursor(Y, X);
                printf_s("%c", '*');
                //вывод второй дроби
                Y = 0;
                X = fraction_one.columns + 4;
                output_fraction(&fraction_two, Y, X);
                // вывод знака равно
                Y = 1;
                X = fraction_one.columns + fraction_two.columns + 5;
                set_console_cursor(Y, X);
                printf_s("%c", '=');
                // вывод результата
                Y = 0;
                X = fraction_one.columns + fraction_two.columns + 7;
                output_fraction(fraction, Y, X);
                break;
            }
            case 6:
            {
                unsigned int Y = 0;
                unsigned int X = 0;

                setViewManual(&fraction_one);
                setViewManual(&fraction_two);
                *fraction = division(&fraction_one, &fraction_two);
                // очистка консоли
                system("cls");
                // вывод первой дроби
                Y = 0;
                X = 0;
                output_fraction(&fraction_one, Y, X);
                // вывод знака :
                Y = 1;
                X = fraction_one.columns + 2;
                set_console_cursor(Y, X);
                printf_s("%c", ':');
                //вывод второй дроби
                Y = 0;
                X = fraction_one.columns + 4;
                output_fraction(&fraction_two, Y, X);
                // вывод знака равно
                Y = 1;
                X = fraction_one.columns + fraction_two.columns + 5;
                set_console_cursor(Y, X);
                printf_s("%c", '=');
                // вывод результата
                Y = 0;
                X = fraction_one.columns + fraction_two.columns + 7;
                output_fraction(fraction, Y, X);
                break;
            }
            default:
                if(choise != 0)
                    printf_s("%s\n", "select the correct menu item");
                break;
        }
        if(choise)
        {
            printf_s("%s", "continue(1.yes/0.no): ");
            scanf("%u", &choise);
        }
    }while(choise);
}
