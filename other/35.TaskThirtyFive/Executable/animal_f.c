#include "../Headers/Functions/animal_f.h"
// ввод данных о животном
void product_data_entry(struct Animal* animal)
{
    system("cls");

    unsigned int length = 0;

    char temp_value[1024];

    // название
    printf_s("%s", "enter the name of the animal: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    animal->tittle = (char*)malloc(length * sizeof (char));
    strcpy_s(animal->tittle, length, temp_value);
    animal->tittle[length - 1] = '\0';
    // класс
    printf_s("%s", "enter the class of belonging of the animal: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    animal->class = (char*)malloc(length * sizeof (char));
    strcpy_s(animal->class, length, temp_value);
    animal->class[length - 1] = '\0';
    // кличка
    printf_s("%s", "enter the nickname of the animal: ");
    scanf("%s", temp_value);
    length = strlen(temp_value) + 1;
    animal->nickname = (char*)malloc(length * sizeof (char));
    strcpy_s(animal->nickname, length, temp_value);
    animal->nickname[length - 1] = '\0';
}
// вывод в консоль данных о животном
void product_data_output(const struct Animal* animal)
{
    const size_t length = 35;
    const size_t lines = 3;

    char parameter[256];
    char value[256];

    for(size_t i = 0; i < lines; ++i)
    {
        // ########################################################### //
        switch(i)
        {
            case 0:
                strcpy_s(parameter, 256, "name:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, animal->tittle);
                value[strlen(value)] = '\0';
                break;
            case 1:
                strcpy_s(parameter, 256, "class:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, animal->class);
                value[strlen(value)] = '\0';
                break;
            case 2:
                strcpy_s(parameter, 256, "nickname:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, animal->nickname);
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
// запись данных о животном в файл
void writing_data_file(const char* path, const struct Animal* animal)
{
    FILE* file;

    const size_t length = 35;
    const size_t lines = 3;

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
                strcpy_s(parameter, 256, "name:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, animal->tittle);
                value[strlen(value)] = '\0';
                break;
            case 1:
                strcpy_s(parameter, 256, "class:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, animal->class);
                value[strlen(value)] = '\0';
                break;
            case 2:
                strcpy_s(parameter, 256, "nickname:");
                parameter[strlen(parameter)] = '\0';
                strcpy_s(value, 256, animal->nickname);
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
// подать голос
void cast_vote(const struct Animal* animal, wchar_t* path)
{
    wchar_t path_c[] = L"";
    wchar_t path_b[] = L"";



    if(strcmp(animal->class, "Dog") == 0 || strcmp(animal->class, "dog") == 0 || strcmp(animal->class, "DOG") == 0)
        strcat_s((char*)path, 1023, "alarm.wav");
    else if(strcmp(animal->class, "Cat") == 0 || strcmp(animal->class, "cat") == 0 || strcmp(animal->class, "CAT") == 0)
        strcat_s((char*)path, 1023, "alarm.wav");

    printf_s(path);
    wchar_t t[] = L"C:/Projects/C/ItStep/PracticeWork/35.TaskThirtyFive/Resources/sounds/alarm.wav";
    //TEXT(c)
    PlaySound(path, NULL, SND_ALIAS);
    Sleep(10000);
}
// освобождение памяти
void destruct_struct(const struct Animal* animal)
{
    free(animal->tittle);
    free(animal->class);
    free(animal->nickname);
}
