#include "../Headers/libraries.h"
#include "../Headers/Functions/smoothing_iron.h"

#define TRUE 1
#define FALSE 0
// ввод данных
void product_data_entry(struct SmoothingIron* smoothingIron)
{
    system("cls");

    unsigned int choise = 3;
    unsigned int length = 0;

    char temp_value[1024];

    // производитель
    printf_s("%s", "enter product manufacturer: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    smoothingIron->company = (char*)malloc(length);
    strcpy_s(smoothingIron->company, length, temp_value);
    smoothingIron->company[length - 1] = '\0';
    // модель
    printf_s("%s", "enter product model id: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    smoothingIron->model = (char*)malloc(length);
    strcpy_s(smoothingIron->model, length, temp_value);
    smoothingIron->model[length - 1] = '\0';
    // цвет
    printf_s("%s", "enter product color: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    smoothingIron->color = (char*)malloc(length);
    strcpy_s(smoothingIron->color, length, temp_value);
    smoothingIron->color[length - 1] = '\0';
    // минимальная температура
    printf_s("%s","enter the value of the minimum temperature for the product: ");
    scanf("%u", &smoothingIron->temp_min);
    // максимальная температура
    printf_s("%s", "enter the maximum temperature for the product: ");
    scanf("%u", &smoothingIron->temp_max);
    // подача пара
    while(choise)
    {
        printf_s("%s", "the presence of steam at the product(1.yes/0.no): ");
        scanf("%i", &choise);
        if(choise == TRUE || choise == FALSE)
        {
            smoothingIron->steam_supply = choise;
            break;
        }
    }
    // мощность
    printf_s("%s", "enter the maximum power value of the product: ");
    scanf("%u", &smoothingIron->power);
}
// вывод даннах в консоль
void product_data_output(const struct SmoothingIron* smoothingIron)
{
    const size_t length = 35;
    const size_t lines = 6;

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
                strcpy_s(value, 256, smoothingIron->company);
                value[strlen(value)] = '\0';
                break;
            case 1:
                strcpy_s(parameter, 256, "model:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, smoothingIron->model);
                value[strlen(value)] = '\0';
                break;
            case 2:
                strcpy_s(parameter, 256, "color:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, smoothingIron->color);
                value[strlen(value)] = '\0';
                break;
            case 3:
                strcpy_s(parameter, 256, "minimum temperature:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)smoothingIron->temp_min, value, 10);
                value[strlen(value)] = '\0';
                break;
            case 4:
                strcpy_s(parameter, 256, "maximum temperature:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)smoothingIron->temp_max, value, 10);
                value[strlen(value)] = '\0';
                break;
            case 5:
                strcpy_s(parameter, 256, "steam supply:");
                parameter[strlen(parameter)] = '\0';
                (smoothingIron->steam_supply == TRUE) ? strcpy_s(value, 256, "yes") : strcpy_s(value, 256, "no");
                value[strlen(value)] = '\0';
                break;
            case 6:
                strcpy_s(parameter, 256, "power:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)smoothingIron->power, value, 10);
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
void writing_data_file(const char* path, const struct SmoothingIron* smoothingIron)
{
    FILE* file;

    const size_t length = 35;
    const size_t lines = 6;

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
                strcpy_s(value, 256, smoothingIron->company);
                value[strlen(value)] = '\0';
                break;
            case 1:
                strcpy_s(parameter, 256, "model:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, smoothingIron->model);
                value[strlen(value)] = '\0';
                break;
            case 2:
                strcpy_s(parameter, 256, "color:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, smoothingIron->color);
                value[strlen(value)] = '\0';
                break;
            case 3:
                strcpy_s(parameter, 256, "minimum temperature:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)smoothingIron->temp_min, value, 10);
                value[strlen(value)] = '\0';
                break;
            case 4:
                strcpy_s(parameter, 256, "maximum temperature:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)smoothingIron->temp_max, value, 10);
                value[strlen(value)] = '\0';
                break;
            case 5:
                strcpy_s(parameter, 256, "steam supply:");
                parameter[strlen(parameter)] = '\0';
                (smoothingIron->steam_supply == TRUE) ? strcpy_s(value, 256, "yes") : strcpy_s(value, 256, "no");
                value[strlen(value)] = '\0';
                break;
            case 6:
                strcpy_s(parameter, 256, "power:");
                parameter[strlen(parameter)] = '\0';
                itoa((int)smoothingIron->power, value, 10);
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
void destruct_struct(const struct SmoothingIron* smoothingIron)
{
    free(smoothingIron->company);
    free(smoothingIron->model);
    free(smoothingIron->color);
}
