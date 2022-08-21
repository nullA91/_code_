#include "../../Headers/functions.h"

#include <locale.h>
#include <windows.h>

#define SOURCE 1
#define RESULT 0

int main(/*int arg_c, char* arg_v[]*/)
{
    // подключение кодировки UTF - 8, QT creator
    setlocale(LC_ALL, "PL_pl.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    // структура для работы с файлами
    struct File file;
    // путь к исходному файлу
    char path_source[128] = "../../Files/source.txt";
    // путь к результативному файлу
    char path_result[128] = "../../Files/result.txt";

    int menuItem = 0;

    do
    {
        system("cls");
        menu();
        printf_s("%s", "select menu item: ");
        scanf("%i", &menuItem);

        switch (menuItem)
        {
            case 1:
            {
                /*
                Дан текстовый файл. Подсчитать количество слов,
                начинающихся с символа, который задаёт пользователь.
                */
                char symbol = '\0';
                int result = 0;
                unsigned int wordCount = 0;

                printf_s("enter character: ");
                symbol = (char)_getch(); //scanf("%c", &symbol);
                printf_s("%c", '\n');

                result = fileOpen(&file, path_source, "r", SOURCE);
                if(result == 1)
                {
                    wordCount = numberWordsFile(&file, symbol, SOURCE);
                    printf_s("%s%c%s%i\n", "number of words in file, starting with a character ", symbol, ": ", wordCount);
                }
                else if(result == -1)
                {
                    printf_s("%s\n", "file is empty");
                    fclose(file.file_source);
                }

                printf_s("%s\n", "press any key to continue");
                _getch();
                break;
            }
            case 2:
            {
                /*
                Дан текстовый файл. Переписать в другой файл все его
                строки с заменой в них символа 0 на символ 1 и наоборот.
                */
                int result;
                char** arrayData = NULL;

                result = fileOpen(&file, path_source, "r", SOURCE);
                if(result == 1)
                {
                    arrayData = fileRead(&file, SOURCE);
                    if(arrayData == NULL)
                        printf_s("%s\n", "error writing data to array from file");
                    else
                    {
                        for(unsigned int i = 0; i < file.rows_source; ++i)
                        {
                            for(unsigned int j = 0; j < file.columns_source; ++j)
                            {
                                if(arrayData[i][j] == '0')
                                    arrayData[i][j] = '1';
                                else if(arrayData[i][j] == '1')
                                    arrayData[i][j] = '0';
                            }
                        }
                        result = fileOpen(&file, path_result, "w", RESULT);
                        if(result == 2)
                            result = fileWrite(&file, arrayData, file.rows_source, RESULT);
                        if(result)
                        {
                            printf_s("%s\n", "recording was successful");
                            if(arrayData != NULL)
                            {
                                for(unsigned int i = 0; i < file.rows_source; ++i)
                                    free(arrayData[i]);
                                free(arrayData);
                            }
                        }
                        else
                            printf_s("%s\n", "file write error");
                    }
                }

                else if(result == -1)
                {
                    printf_s("%s\n", "read failed, file is empty, add data to file");
                    fclose(file.file_source);
                }

                printf_s("%s\n", "press any key to continue");
                _getch();
                break;
            }
            case 3:
            {
                /*
                Дан массив строк. Записать их в файл, расположив каждый
                элемент массива на отдельной строке с сохранением порядка.
                */
                const unsigned int rows = 9;
                unsigned int length = 0;
                int result = 0;
                char** poem = NULL;

                poem = (char**)malloc(rows * sizeof (char*));
                for(unsigned int i = 0; i < rows; ++i)
                {
                    if(i == 0)
                    {
                        length = strlen("\nSome say the world will end in fire,\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "\nSome say the world will end in fire,\n");
                    }
                    else if(i == 1)
                    {
                        length = strlen("Some say in ice.\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "Some say in ice.\n");
                    }
                    else if(i == 2)
                    {
                        length = strlen("From what I’ve tasted of desire\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "From what I’ve tasted of desire\n");
                    }
                    else if(i == 3)
                    {
                        length = strlen("I hold with those who favor fire.\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "I hold with those who favor fire.\n");
                    }
                    else if(i == 4)
                    {
                        length = strlen("But if it had to perish twice,\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "But if it had to perish twice,\n");
                    }
                    else if(i == 5)
                    {
                        length = strlen("I think I know enough of hate\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "I think I know enough of hate\n");
                    }
                    else if(i == 6)
                    {
                        length = strlen("To say that for destruction ice\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "To say that for destruction ice\n");
                    }
                    else if(i == 7)
                    {
                        length = strlen("Is also great\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "Is also great\n");
                    }
                    else if(i == 8)
                    {
                        length = strlen("And would suffice.\n") + 1;
                        poem[i] = (char*)malloc(length * sizeof (char));
                        strcpy_s(poem[i], length, "And would suffice.\n");
                    }
                }

                result = fileOpen(&file, path_source, "a", SOURCE);
                if(result == 3)
                    result = fileWrite(&file, poem, rows, SOURCE);
                if(result)
                {
                    printf_s("%s\n", "recording was successful");
                    if(poem != NULL)
                    {
                        for(unsigned int i = 0; i < rows; ++i)
                            free(poem[i]);
                        free(poem);
                    }
                }
                else
                    printf_s("%s\n", "file write error");

                printf_s("%s\n", "press any key to continue");
                _getch();
                break;
            }
            case 4:
            {
                /*
                Дан текстовый файл. Подсчитать количество символов в нём.
                */
                unsigned int characterCount = 0;
                int result;

                result = fileOpen(&file, path_result, "r", RESULT);
                if(result == 1)
                {
                    characterCount = numberCharactersFile(&file, RESULT);
                    printf_s("%s%i\n", "number of characters in file: ", characterCount);
                }
                else if(result == -1)
                {
                    printf_s("%s\n", "file is empty");
                    fclose(file.file_result);
                }

                printf_s("%s\n", "press any key to continue");
                _getch();
                break;
            }
            case 5:
            {
                /*
                Дан текстовый файл. Подсчитать количество строк в нём.
                */
                unsigned int rows = 0;
                int result = 0;

                result = fileOpen(&file, path_source, "r", SOURCE);
                if(result == 1)
                {
                    rows = file.rows_source;
                    printf_s("%s%i\n", "number of lines in file: ", rows);
                }
                else if(result == -1)
                {
                    printf_s("%s\n", "file is empty");
                    fclose(file.file_source);
                }

                printf_s("%s\n", "press any key to continue");
                _getch();
                break;
            }
        }

    } while(menuItem);

    printf_s("%s\n", "completion of the program");
    return 0;
}

/* выделение памяти под двумерный массив
array = (char**)malloc(file.rows_source * sizeof (char*));
for(int i = 0; i < file.rows_source; ++i)
    array[i] = (char*)malloc(file.columns_source * sizeof (char));
*/

/* освобождение памяти для двумерного массива
if(array != NULL)
{
    for(unsigned int i = 0; i < file.rows_source; ++i)
        free(array[i]);
    free(array);
}
*/

/*
Some say the world will end in fire,
Some say in ice.
From what I’ve tasted of desire
I hold with those who favor fire.
But if it had to perish twice,
I think I know enough of hate
To say that for destruction ice
Is also great
And would suffice.
*/
