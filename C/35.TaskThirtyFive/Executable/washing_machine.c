#include "../Headers/Functions/washing_machine.h"

//ввод данных
void product_data_entry(struct WashingMachine* washingMachine)
{
    system("cls");
    //scanf("%[^\n]s");
    unsigned int length = 0;

    char temp_value[1024];

    // производитель
    printf_s("%s", "enter the name of the company that manufactures the product: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    washingMachine->company = (char*)malloc(length * sizeof (char));
    strcpy_s(washingMachine->company, length, temp_value);
    washingMachine->company[length - 1] = '\0';
    // цвет
    printf_s("%s", "enter product color: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    washingMachine->color = (char*)malloc(length * sizeof (char));
    strcpy_s(washingMachine->color, length, temp_value);
    washingMachine->color[length - 1] = '\0';
    // ширина
    printf_s("%s", "enter product width: ");
    scanf("%f", &(washingMachine->width));
    // длина
    printf_s("%s", "enter product length: ");
    scanf("%f", &(washingMachine->length));
    // высота
    printf_s("%s", "enter product height: ");
    scanf("%f", &(washingMachine->height));
    // мощность
    printf_s("%s", "enter the power consumption of the product: ");
    scanf("%f", &(washingMachine->power));
    // скорость отжима
    printf_s("%s", "enter the spin speed of the product: ");
    scanf("%u", &(washingMachine->spin_speed));
    // температура
    printf_s("%s", "enter the heating temperature of the product: ");
    scanf("%u", &(washingMachine->temperature));
}
// вывод данных
void product_data_output(const struct WashingMachine* washingMachine)
{
    system("cls");

    const size_t length = 75;
    const size_t size = 5;

    char string[256];
     // ########################## //
    // ##### первая строка ###### //
   // ########################## //
    printf_s("%c", '+');
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length / 2 || i == length / 2 + 1)
            printf_s("%c", '+');
        else
            printf_s("%c", '-');
    }
    printf_s("%c\n", '+');
    // производитель
    printf_s("%c", '|');
    printf_s("%s", "company:");
    for(size_t i = strlen("company:"); i < length / 2 - strlen(washingMachine->company); ++i)
        printf_s("%c", ' ');
    printf_s("%s%c", washingMachine->company, '|');
    // цвет
    printf_s("%c", '|');
    printf_s("%s", "color:");
    for(size_t i = strlen("color:"); i < length / 2 - strlen(washingMachine->color) - 1; ++i)
        printf_s("%c", ' ');
    printf_s("%s%c\n", washingMachine->color, '|');
    //
    printf_s("%c", '+');
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length / 2 || i == length / 2 + 1 || i == length / 3 || i == length / 3 + 1 || i == 52 || i == 53)
            printf_s("%c", '+');
        else
            printf_s("%c", '-');
    }
    printf_s("%c\n", '+');
    // ########################## //
   // ##### вторая строка ###### //
  // ######### ширина ######### //
    printf_s("%c", '|');
    printf_s("%s", "width:");
    gcvt((double)washingMachine->width, size, string);
    for(size_t i = strlen("width:"); i < length / 3 - strlen(string); ++i)
        printf_s("%c", ' ');
    printf_s("%s", string);
    printf_s("%c", '|');
    // длина
    printf_s("%c", '|');
    printf_s("%s", "length:");
    gcvt((double)washingMachine->length, size, string);
    for(size_t i = strlen("length:"); i < length / 3 - strlen(string); ++i)
        printf_s("%c", ' ');
    printf_s("%s", string);
    printf_s("%c", '|');
    // высота
    printf_s("%c", '|');
    printf_s("%s", "height:");
    gcvt((double)washingMachine->height, size, string);
    for(size_t i = strlen("height:"); i < length / 3 - strlen(string) - 4; ++i)
        printf_s("%c", ' ');
    printf_s("%s", string);
    printf_s("%c\n", '|');
    //
    printf_s("%c", '+');
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length / 2 || i == length / 2 + 1 || i == length / 3 || i == length / 3 + 1 || i == 52 || i == 53)
            printf_s("%c", '+');
        else
            printf_s("%c", '-');
    }
    printf_s("%c\n", '+');
    // ########################## //
   // ##### третья строка ###### //
  // ######## мощность ######## //
    printf_s("%c", '|');
    printf_s("%s", "power:");
    gcvt((double)washingMachine->power, size, string);
    for(size_t i = strlen("power:"); i < length / 3 - strlen(string); ++i)
        printf_s("%c", ' ');
    printf_s("%s", string);
    printf_s("%c", '|');
    // скорость отжима
    printf_s("%c", '|');
    printf_s("%s", "spin speed:");
    itoa((int)washingMachine->spin_speed, string, 10);
    for(size_t i = strlen("spin speed:"); i < length / 3 - strlen(string); ++i)
        printf_s("%c", ' ');
    printf_s("%s", string);
    printf_s("%c", '|');
    // температура
    printf_s("%c", '|');
    printf_s("%s", "temperature:");
    itoa((int)washingMachine->temperature, string, 10);
    for(size_t i = strlen("temperature:"); i < length / 3 - strlen(string) - 6; ++i)
        printf_s("%c", ' ');
    printf_s("%s%c%c", string, 248, 'C');
    printf_s("%c\n", '|');
    //
    printf_s("%c", '+');
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length / 2 || i == length / 2 + 1 || i == length / 3 || i == length / 3 + 1 || i == 52 || i == 53)
            printf_s("%c", '+');
        else
            printf_s("%c", '-');
    }
    printf_s("%c\n", '+');
}
// запись данных в файл
void writing_data_file(const char* path, const struct WashingMachine* washingMachine)
{
    FILE* file;

    const size_t length = 75;
    const size_t size = 5;

    char string[256];

    fopen_s(&file, path, "a");

    if(file == NULL)
    {
        printf_s("%s\n", "file open error");
        exit(1);
    }

      // ###### начало строки ##### //
     // ##### первая строка ###### //
    // ########################## //
    fputc('+', file);
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length / 2 || i == length / 2 + 1)
            fputc('+', file);
        else
            fputc('-', file);
    }
    fputc('+', file);
    fputc('\n', file);
    // производитель
    fputc('|', file);
    fputs("company:", file);
    for(size_t i = strlen("company:"); i < length / 2 - strlen(washingMachine->company); ++i)
        fputc(' ', file);
    fputs(washingMachine->company, file);
    fputc('|', file);
    // цвет
    fputc('|', file);
    fputs("color:", file);
    for(size_t i = strlen("color:"); i < length / 2 - strlen(washingMachine->color) - 1; ++i)
        fputc(' ', file);
    fputs(washingMachine->color, file);
    fputc('|', file);
    fputc('\n', file);
    // конец строки
    fputc('+', file);
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length / 2 || i == length / 2 + 1 || i == length / 3 || i == length / 3 + 1 || i == 52 || i == 53)
            fputc('+', file);
        else
            fputc('-', file);
    }
    fputc('+', file);
    fputc('\n', file);
      // ###### начало строки ##### //
     // ##### вторая строка ###### //
    // ######### ширина ######### //
    fputc('|', file);
    fputs("width:", file);
    gcvt((double)washingMachine->width, size, string);
    for(size_t i = strlen("width:"); i < length / 3 - strlen(string); ++i)
        fputc(' ', file);
    fputs(string, file);
    fputc('|', file);
    // длина
    fputc('|', file);
    fputs("length:", file);
    gcvt((double)washingMachine->length, size, string);
    for(size_t i = strlen("length:"); i < length / 3 - strlen(string); ++i)
        fputc(' ', file);
    fputs(string, file);
    fputc('|', file);
    // высота
    fputc('|', file);
    fputs("height:", file);
    gcvt((double)washingMachine->height, size, string);
    for(size_t i = strlen("height:"); i < length / 3 - strlen(string) - 4; ++i)
        fputc(' ', file);
    fputs(string, file);
    fputc('|', file);
    fputc('\n', file);
    // конец строки
    fputc('+', file);
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length / 3 || i == length / 3 + 1 || i == 52 || i == 53)
            fputc('+', file);
        else
            fputc('-', file);
    }
    fputc('+', file);
    fputc('\n', file);
      // ###### начало строки ##### //
     // ##### третья строка ###### //
    // ######## мощность ######## //
    fputc('|', file);
    fputs("power:", file);
    gcvt((double)washingMachine->power, size, string);
    for(size_t i = strlen("power:"); i < length / 3 - strlen(string); ++i)
        fputc(' ', file);
    fputs(string, file);
    fputc('|', file);
    // скорость отжима
    fputc('|', file);
    fputs("spin speed:", file);
    itoa((int)washingMachine->spin_speed, string, 10);
    for(size_t i = strlen("spin speed:"); i < length / 3 - strlen(string); ++i)
        fputc(' ', file);
    fputs(string, file);
    fputc('|', file);
    // температура
    fputc('|', file);
    fputs("temperature:", file);
    itoa((int)washingMachine->temperature, string, 10);
    for(size_t i = strlen("temperature:"); i < length / 3 - strlen(string) - 4; ++i)
        fputc(' ', file);
    fputs(string, file);
    fputc('|', file);
    fputc('\n', file);
    // конец строки
    fputc('+', file);
    for(size_t i = 0; i < length; ++i)
    {
        if(i == length / 3 || i == length / 3 + 1 || i == 52 || i == 53)
            fputc('+', file);
        else
            fputc('-', file);
    }
    fputc('+', file);
    fputc('\n', file);

    fputc(' ', file);
    for(size_t i = 0; i < length; ++i)
        fputc('#', file);
    fputc(' ', file);
    fputc('\n', file);

    fclose(file);
}
// освобождение памяти
void destruct_struct(const struct WashingMachine* washingMachine)
{
    free(washingMachine->company);
    free(washingMachine->color);
}
