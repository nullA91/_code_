#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************************************************
Задание 1. Дан текстовый файл. Необходимо создать
новый файл, в который переписать из исходного файла
все слова, состоящие не менее чем из семи букв.
**********************************************************************
Задание 2. Дан текстовый файл. Необходимо переписать
его строки в другой файл. Порядок строк во втором файле
должен совпадать с порядком строк в заданном файле.
**********************************************************************
Задание 3. Дан текстовый файл. Необходимо переписать
его строки в другой файл. Порядок строк во втором файле
должен быть обратным по отношению к порядку строк
в заданном файле.
**********************************************************************
Задание 4. Дан текстовый файл. Добавить в него строку
из двенадцати черточек (------------), поместив ее после
последней из строк, в которых нет пробела. Если таких
строк нет, то новая строка должна быть добавлена после
всех строк имеющегося файла. Результат записать в другой файл.
*********************************************************************/
int main(int arg_c, char* arg_v[])
{   
    const char path_source[] = "C:/Projects/C/ItStep/PracticeWork/39.TaskThirtyNine/source.txt";
    const char path_destination[] = "C:/Projects/C/ItStep/PracticeWork/39.TaskThirtyNine/destination.txt";
    const char path_copy_c[] = "C:/Projects/C/ItStep/PracticeWork/39.TaskThirtyNine/copy correct.txt";
    const char path_copy_r[] = "C:/Projects/C/ItStep/PracticeWork/39.TaskThirtyNine/copy reverse.txt";
    const char path_source_dash[] = "C:/Projects/C/ItStep/PracticeWork/39.TaskThirtyNine/source dash.txt";


    size_t length = 1048576;
    size_t _length_ = 1024;

    FILE* file_source;
    FILE* file_destination;
    FILE* file_coppied_correct;
    FILE* file_coppied_reverse;
    FILE* file_source_dash;

    char symbol = '\0';
    char space = '\0';
    char word[256];
    char words[1048576];
    char string[1024];

    char **strings;

    int index = 0;
    int value_t = 0;

    //###################################//
    //*************ЗАДАНИЕ 1*************//
    //###################################//
    strcpy_s(words, 2, "");
    strcpy_s(word, 2, "");

    fopen_s(&file_source, path_source, "r");
    if(file_source == NULL)
    {
        printf_s("%s\n", "file open error");
        return 1;
    }
    // чтение данных из файла источнока
    while(!feof(file_source))
    {
        symbol = (char)fgetc(file_source);
        if( (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z') )
        {
            word[index] = symbol;
            ++index;
        }
        else
        {
            word[index] = '\0';
            if(strlen(word) > 6)
            {
                strcat_s(words, length, word);
                strcat_s(words, length, "\n");
            }
            index = 0;
        }
    }
    words[strlen(words)] = '\0';
    fclose(file_source);
    // запись данных в файл назначения
    fopen_s(&file_destination, path_destination, "a");
    if(file_destination == NULL)
    {
        printf_s("%s\n", "file open error");
        return 1;
    }
    for(size_t i = 0; i < strlen(words); ++i)
        fputc(words[i], file_destination);
    fputs("\n-##########-\n", file_destination);
    fclose(file_destination);
    //###################################//
    //*************ЗАДАНИЕ 2*************//
    //###################################//
    fopen_s(&file_source, path_source, "r");
    if(file_source == NULL)
    {
        printf_s("%s\n", "file open error");
        return 1;
    }
    fopen_s(&file_coppied_correct, path_copy_c, "a");
    if(file_coppied_correct == NULL)
    {
        printf_s("%s\n", "file open error");
        return 1;
    }
    while(!feof(file_source))
    {
        fgets(string, (int)_length_, file_source);
        fputs(string, file_coppied_correct);
        ++value_t;
    }
    fputs("\n-##############################-\n", file_coppied_correct);
    fclose(file_source);
    fclose(file_coppied_correct);
    //###################################//
    //*************ЗАДАНИЕ 3*************//
    //###################################//
    fopen_s(&file_source, path_source, "r");
    if(file_source == NULL)
    {
        printf_s("%s\n", "file open error");
        return 1;
    }

    value_t = 0;
    while(!feof(file_source))
    {
        fgets(string, (int)_length_, file_source);
        ++value_t;
    }
    fseek(file_source, 0, SEEK_SET);

    fopen_s(&file_coppied_reverse, path_copy_r, "a");
    if(file_coppied_reverse == NULL)
    {
        printf_s("%s\n", "file open error");
        return 1;
    }

    index = value_t;

    strings = (char**)malloc((unsigned int)value_t * sizeof (char*));
    for(size_t i = 0; i < (size_t)value_t; ++i)
    {
        strings[i] = (char*)malloc(_length_ * sizeof (char));
    }
    while(!feof(file_source))
    {
        fgets(string, (int)_length_, file_source);
        strcpy_s(strings[value_t - 1], _length_, string);
        if(strings[value_t - 1][strlen(strings[value_t - 1]) - 1] != '\n')
            strcat_s(strings[value_t - 1], _length_, "\n");
        --value_t;
    }

    for(size_t i = 0; i < (size_t)index; ++i)
    {
        fputs(strings[i], file_coppied_reverse);
    }
    fputs("\n-##############################-\n", file_coppied_reverse);

    for(size_t i = 0; i < (size_t)index; ++i)
        free(strings[i]);
    free(strings);
    fclose(file_source);
    fclose(file_coppied_reverse);
    //###################################//
    //*************ЗАДАНИЕ 4*************//
    //###################################//
    fopen_s(&file_source, path_source, "r");
    if(file_source == NULL)
    {
        printf_s("%s\n", "file open error");
        return 1;
    }

    value_t = 0;
    while(!feof(file_source))
    {
        fgets(string, (int)_length_, file_source);
        ++value_t;
    }
    fseek(file_source, 0, SEEK_SET);

    index = value_t;

    strings = (char**)malloc((unsigned int)value_t * sizeof (char*));
    for(size_t i = 0; i < (size_t)value_t; ++i)
    {
        strings[i] = (char*)malloc(_length_ * sizeof (char));
    }

    while(!feof(file_source))
    {
        fgets(string, (int)_length_, file_source);
        strcpy_s(strings[value_t - 1], _length_, string);
        if(strings[value_t - 1][strlen(strings[value_t - 1]) - 1] != '\n')
            strcat_s(strings[value_t - 1], _length_, "\n");
        printf_s("%i\n", strlen(strings[value_t - 1]));
        --value_t;
    }

    for(size_t i = 0; i < (size_t)index; ++i)
    {
        if(strlen(strings[i]) == 1)
            continue;

        space = '\0';
        for(size_t j = 0; j < strlen(strings[i]); ++j)
        {
            symbol = strings[i][j];

            if(symbol == ' ')
                space = ' ';
        }
        if(space != ' ')
        {
            value_t = (int)i;
            break;
        }
    }

    fopen_s(&file_source_dash, path_source_dash, "a");
    if(file_source_dash == NULL)
    {
        printf_s("%s\n", "file open error");
        return 1;
    }

    if(value_t)
    {
        for(size_t i = (size_t)index - 1; i >= (size_t)value_t; --i)
        {
            fputs(strings[i], file_source_dash);
        }
        fputs("------------\n", file_source_dash);
        for(int i = value_t - 1; i > -1; --i)
        {
            fputs(strings[i], file_source_dash);
        }
    }
    else
    {
        for(int i = index - 1; i > -1; --i)
        {
            fputs(strings[i], file_source_dash);
        }
        fputs("------------\n", file_source_dash);
    }
    fputs("\n-##############################-\n", file_source_dash);

    for(size_t i = 0; i < (size_t)index; ++i)
        free(strings[i]);
    free(strings);
    fclose(file_source);
    fclose(file_source_dash);
    return 0;
}
