#include "Headers/Functions/number_f.h"
// ввод числа
int input_number(union Number* _number)
{
    printf_s("%s", "enter a number: ");
    scanf("%i", &(_number->number_u));

    return _number->number_u;
}
// просмотр всех байтов числа
void view_bytes_all(union Number* _number)
{
    system("cls");

    for(size_t i = 0; i < size; ++i)
        view_byte(_number, i + 1);

    byte_info(_number);
}
// просмотр выбранного байта
void view_byte(union Number* _number, const unsigned int index)
{
    const unsigned int length = 8;
    const unsigned int columns = 75;
    const unsigned int col_f = 35;
    const unsigned int col_s = 55;
    const unsigned int col_t = 65;

    size_t _index = 0;
    size_t stop = 0;

    int value = 0;

    char string[256];

    // верх
    printf_s("%c", 201);
    for(size_t i = 0; i < columns; ++i)
    {
        if(i == col_f || i == col_s || i == col_t)
            printf_s("%c", 203);
        else
            printf_s("%c", 205);
    }
    printf_s("%c", 187);
    printf_s("%c", '\n');
    // середина
    printf_s("%c", 186);
    printf_s("%s", "BYTE");
    for(_index = strlen("BYTE"); _index < col_f; ++_index)
        printf_s("%c", ' ');
    printf_s("%c", 186);
    //
    for(; _index < col_s - strlen("HexaDecimal") - 1; ++_index)
        printf_s("%c", ' ');
    printf_s("%s%c", "HexaDecimal", 186);
    //
    for(; _index < col_s - strlen("Decimal") - 3; ++_index)
        printf_s("%c", ' ');
    printf_s("%s%c", "Decimal", 186);
    //
    for(; _index < col_s - strlen("Binary") - 1; ++_index)
        printf_s("%c", ' ');
    printf_s("%s%c\n", "Binary", 186);
    // низ
    printf_s("%c", 204);
    for(size_t i = 0; i < columns; ++i)
    {
        if(i == col_f || i == col_s || i == col_t)
            printf_s("%c", 206);
        else
            printf_s("%c", 205);
    }
    printf_s("%c", 185);
    printf_s("%c", '\n');
      //#################################//
     //********** вывод байта **********//
    //#################################//
    value = _number->number_u;
    _number->number_u = _number->byte_representation[index - 1];

    strcpy_s(string, length - 1, "First");
    string[strlen(string)] = '\0';

    if(index == 2)
    {
        strcpy_s(string, length - 1, "Second");
        string[strlen(string)] = '\0';
    }
    else if(index == 3)
    {
        strcpy_s(string, length - 1, "Third");
        string[strlen(string)] = '\0';
    }
    else if(index == 4)
    {
        strcpy_s(string, length - 1, "Fourth");
        string[strlen(string)] = '\0';
    }

    printf_s("%c", 186);
    printf_s("%s", string);

    for(_index = strlen(string); _index < col_f; ++_index)
        printf_s("%c", ' ');
    printf_s("%c", 186);
      //###############################################//
     //***** шестнадцатирицная система счисления *****//
    //###############################################//
    itoa(_number->number_u, string, 16);
    stop = col_s - strlen(string) - 1;
    for(; _index < stop; ++_index)
        printf_s("%c", ' ');
    printf_s("%X%c", _number->number_u, 186);
    _index = col_s + 1;
      //###############################################//
     //******** десятичная система счисления *********//
    //###############################################//
    itoa(_number->number_u, string, 10);
    stop = col_t - strlen(string);
    for(; _index < stop; ++_index)
        printf_s("%c", ' ');
    printf_s("%i%c", _number->number_u, 186);
    _index = col_t + 1;
      //###############################################//
     //********* двоичная система счисления **********//
    //###############################################//
    string[8] = '\0';
    string[7] = _number->bit.zero + 48;
    string[6] = _number->bit.first + 48;
    string[5] = _number->bit.second + 48;
    string[4] = _number->bit.third + 48;
    string[3] = _number->bit.fourth + 48;
    string[2] = _number->bit.fifth + 48;
    string[1] = _number->bit.sixth + 48;
    string[0] = _number->bit.seventh + 48;

    stop = columns - strlen(string);
    for(; _index < stop; ++_index)
        printf_s("%c", ' ');
    printf_s("%s%c\n", string, 186);
    // низ
    printf_s("%c", 200);
    for(size_t i = 0; i < columns; ++i)
    {
        if(i == col_f || i == col_s || i == col_t)
            printf_s("%c", 202);
        else
            printf_s("%c", 205);
    }
    printf_s("%c", 188);
    printf_s("%c", '\n');

    _number->number_u = value;
}
// информация о байтах числа
void byte_info(union Number* _number)
{
    unsigned int zero_bit_c = 0;
    unsigned int single_bit_c = 0;

    for(size_t i = 0; i < size; ++i)
    {
        if(_number->byte_representation[i])
            ++single_bit_c;
        else
            ++zero_bit_c;
    }

    printf_s("%s%i", "number of zero bits: ", zero_bit_c);
    for(size_t i = 0; i < 30; ++i) printf_s("%c", ' ');
    printf_s("%s%i\n", "number of single bits:  ", single_bit_c);
}
// запись данных в файл
int write_data_file(union Number* _number, const char* path)
{
    FILE* file;

    const unsigned int length = 8;
    const unsigned int columns = 75;
    const unsigned int col_f = 35;
    const unsigned int col_s = 55;
    const unsigned int col_t = 65;

    size_t _index = 0;
    size_t stop = 0;

    int value = 0;

    char string[256];

    fopen_s(&file, path, "a");

    if(file == NULL)
    {
        printf_s("%s\n", "file open error");
        return 0;
    }
    for(size_t index = 0; index < size; ++index)
    {
        _index = 0;

        // верх
        fputc('+', file);
        for(size_t i = 0; i < columns; ++i)
        {
            if(i == col_f || i == col_s || i == col_t)
                fputc('+', file);
            else
                fputc('-', file);
        }
        fputc('+', file);
        fputc('\n', file);;
        // середина
        fputc('|', file);
        fputs("BYTE", file);
        for(_index = strlen("BYTE"); _index < col_f; ++_index)
            fputc(' ', file);
        fputc('|', file);
        //
        for(; _index < col_s - strlen("HexaDecimal") - 1; ++_index)
            fputc(' ', file);
        fputs("HexaDecimal", file);
        fputc('|', file);
        //
        for(; _index < col_s - strlen("Decimal") - 3; ++_index)
            fputc(' ', file);
        fputs("Decimal", file);
        fputc('|', file);
        //
        for(; _index < col_s - strlen("Binary") - 1; ++_index)
            fputc(' ', file);
        fputs("Binary", file);
        fputc('|', file);
        fputc('\n', file);
        // низ
        fputc('+', file);
        for(size_t i = 0; i < columns; ++i)
        {
            if(i == col_f || i == col_s || i == col_t)
                fputc('+', file);
            else
                fputc('-', file);
        }
        fputc('+', file);
        fputc('\n', file);
        //#################################//
        //********** вывод байта **********//
        //#################################//
        value = _number->number_u;
        _number->number_u = _number->byte_representation[index];

        strcpy_s(string, length - 1, "First");
        string[strlen(string)] = '\0';

        if(index == 1)
        {
            strcpy_s(string, length - 1, "Second");
            string[strlen(string)] = '\0';
        }
        else if(index == 2)
        {
            strcpy_s(string, length - 1, "Third");
            string[strlen(string)] = '\0';
        }
        else if(index == 3)
        {
            strcpy_s(string, length - 1, "Fourth");
            string[strlen(string)] = '\0';
        }

        fputc('|', file);
        fputs(string, file);

        for(_index = strlen(string); _index < col_f; ++_index)
            fputc(' ', file);
        fputc('|', file);
        //###############################################//
        //***** шестнадцатирицная система счисления *****//
        //###############################################//
        itoa(_number->number_u, string, 16);
        stop = col_s - strlen(string) - 1;
        for(; _index < stop; ++_index)
            fputc(' ', file);
        fputs(strupr(string), file);
        fputc('|', file);
        _index = col_s + 1;
        //###############################################//
        //******** десятичная система счисления *********//
        //###############################################//
        itoa(_number->number_u, string, 10);
        stop = col_t - strlen(string);
        for(; _index < stop; ++_index)
            fputc(' ', file);
        fputs(string, file);
        fputc('|', file);
        _index = col_t + 1;
        //###############################################//
        //********* двоичная система счисления **********//
        //###############################################//
        string[8] = '\0';
        string[7] = _number->bit.zero + 48;
        string[6] = _number->bit.first + 48;
        string[5] = _number->bit.second + 48;
        string[4] = _number->bit.third + 48;
        string[3] = _number->bit.fourth + 48;
        string[2] = _number->bit.fifth + 48;
        string[1] = _number->bit.sixth + 48;
        string[0] = _number->bit.seventh + 48;

        stop = columns - strlen(string);
        for(; _index < stop; ++_index)
            fputc(' ', file);
        fputs(string, file);
        fputc('|', file);
        fputc('\n', file);
        // низ
        fputc('+', file);
        for(size_t i = 0; i < columns; ++i)
        {
            if(i == col_f || i == col_s || i == col_t)
                fputc('+', file);
            else
                fputc('-', file);
        }
        fputc('+', file);
        fputc('\n', file);

        _number->number_u = value;
    }

    fputc(' ', file);
    for(size_t i = 0; i < columns - 1; ++i)
        fputc('#', file);
    fputc(' ', file);
    fputc('\n', file);
}
