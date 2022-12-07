#include "../Headers/Functions/boiler_f.h"

// ввод данных
void product_data_entry(struct Boiler* boiler)
{
    system("cls");

    unsigned int length = 0;

    char temp_value[1024];

    // производитель
    printf_s("%s", "enter the name of the company that manufactures the product: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    boiler->company = (char*)malloc(length * sizeof (char));
    strcpy_s(boiler->company, length, temp_value);
    boiler->company[length - 1] = '\0';
    // цвет
    printf_s("%s", "enter product color: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    boiler->color = (char*)malloc(length * sizeof (char));
    strcpy_s(boiler->color, length, temp_value);
    boiler->color[length - 1] = '\0';
    // мощность
    printf_s("%s", "enter the power consumption of the product: ");
    scanf("%u", &(boiler->power));
    // объем
    printf_s("%s", "enter the water volume of the product: ");
    scanf("%u", &(boiler->volume));
    // температура
    printf_s("%s", "enter product heating temperature: ");
    scanf("%u", &(boiler->heating_temperature));
}
// вывод данных в консоль
void product_data_output(const struct Boiler* boiler)
{
    const size_t length = 35;
    const size_t lines = 5;

    char parameter[256];
    char value[256];

    for(size_t i = 0; i < lines; ++i)
    {
        // ########################################################### //
        switch(i)
        {
            case 0:
                strcpy_s(parameter, 256, "company:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, boiler->company);
                value[strlen(value)] = '\0';
                break;
            case 1:
                strcpy_s(parameter, 256, "color:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, boiler->color);
                value[strlen(value)] = '\0';
                break;
            case 2:
                strcpy_s(parameter, 256, "power:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)boiler->power, value, 10);
                value[strlen(value)] = '\0';
                break;
            case 3:
                strcpy_s(parameter, 256, "water volume:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)boiler->volume, value, 10);
                value[strlen(value)] = '\0';
                break;
            case 4:
                strcpy_s(parameter, 256, "heating temperature:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)boiler->heating_temperature, value, 10);
                value[strlen(value)] = '\0';
                break;
        }
        // ########################################################### //
        // верх
        printf_s("%c", '+');
        for(size_t i = 0; i < length; ++i)
        {
            printf_s("%c", '-');
        }
        printf_s("%c\n", '+');
        // середина
        printf_s("%c", '|');
        printf_s("%s", parameter);
        for(size_t i = strlen(parameter); i < length - strlen(value); ++i)
            printf_s("%c", ' ');
        printf_s("%s%c\n", value, '|');
        // низ
        printf_s("%c", '+');
        for(size_t i = 0; i < length; ++i)
        {
            printf_s("%c", '-');
        }
        printf_s("%c\n", '+');
    }
}
// запись данных в файл
void writing_data_file(const char* path, const struct Boiler* boiler)
{
    FILE* file;

    const size_t length = 35;
    const size_t lines = 5;

    char parameter[256];
    char value[256];

    fopen_s(&file, path, "a");

    if(file == NULL)
    {
        printf_s("%s\n", "error opening file for writing");
        exit(1);
    }

    for(size_t i = 0; i < lines; ++i)
    {
        // ########################################################### //
        switch(i)
        {
            case 0:
                strcpy_s(parameter, 256, "company:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, boiler->company);
                value[strlen(value)] = '\0';
                break;
            case 1:
                strcpy_s(parameter, 256, "color:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, boiler->color);
                value[strlen(value)] = '\0';
                break;
            case 2:
                strcpy_s(parameter, 256, "power:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)boiler->power, value, 10);
                value[strlen(value)] = '\0';
                break;
            case 3:
                strcpy_s(parameter, 256, "water volume:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)boiler->volume, value, 10);
                value[strlen(value)] = '\0';
                break;
            case 4:
                strcpy_s(parameter, 256, "heating temperature:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)boiler->heating_temperature, value, 10);
                value[strlen(value)] = '\0';
                break;
        }
        // ########################################################### //
        // верх
        fputc('+', file);
        for(size_t i = 0; i < length; ++i)
        {
            fputc('-', file);
        }
        fputc('+', file);
        fputc('\n', file);
        // середина
        fputc('|', file);
        fputs(parameter, file);
        for(size_t i = strlen(parameter); i < length - strlen(value); ++i)
        {
            fputc(' ', file);
        }
        fputs(value, file);
        fputc('|', file);
        fputc('\n', file);
        // низ
        fputc('+', file);
        for(size_t i = 0; i < length; ++i)
        {
            fputc('-', file);
        }
        fputc('+', file);
        fputc('\n', file);
    }
    fputc('-', file);
    for(size_t i = 0; i < length; ++i)
    {
        fputc('#', file);
    }
    fputc('-', file);
    fputc('\n', file);
}
// освобождение памяти
void destruct_struct(const struct Boiler* boiler)
{
    free(boiler->company);
    free(boiler->color);
}
