#include "../../Headers/file.h"
// функция открытия файла
int fileOpen(struct File* file, char* path, char* mode, int TYPE)
{
    char symbol = '\0';
    unsigned int length = 0;

    // открытие исходного файла
    if(TYPE)
    {
        // установка начального значения для количества строк и столбцов в файле
        file->rows_source = 0;
        file->columns_source = 0;
        // открытие файла
        fopen_s(&(file->file_source), path, mode);
        // если файл не открылся, вывести ошибку
        if(file->file_source == NULL)
        {
            printf_s("%s\n", "error opening source file");
            return 0;
        }
        symbol = (char)fgetc(file->file_source);
        if(!strcmp(mode, "r"))
        {
            if(symbol == EOF)
            {
                // установить указатель в начало файла
                fseek(file->file_source, 0, SEEK_SET);
                // прервать работу цикла
                return EOF;
            }
        }
        // чтение файла
        while(!feof(file->file_source))
        {
            if(symbol == EOF)
                break;
            symbol = (char)fgetc(file->file_source);
            ++length;
            if(symbol == '\n')
            {
                file->rows_source++;
                if(length > file->columns_source)
                    file->columns_source = length;
                length = 0;
            }
        }
        file->rows_source++;
        file->columns_source++;
        // установка указателя в начало файла
        fseek(file->file_source, 0, SEEK_SET);
        // вывод сообщения об успешном открытии файла
        //printf_s("%s\n", "successful opening of source file");
    }
    // открытие результативного файла
    else
    {
        // установка начального значения для количества строк и столбцов в файле
        file->rows_result = 0;
        file->columns_result = 0;
        // открытие файла
        fopen_s(&(file->file_result), path, mode);
        // если файл не открылся, вывести ошибку
        if(file->file_result == NULL)
        {
            printf_s("%s\n", "error opening resulting file");
            return 0;
        }
        symbol = (char)fgetc(file->file_result);
        if(!strcmp(mode, "r"))
        {
            if(symbol == EOF)
            {
                // установить указатель в начало файла
                fseek(file->file_result, 0, SEEK_SET);
                // прервать работу цикла
                return EOF;
            }
        }
        // чтение файла
        while(!feof(file->file_result))
        {
            if(symbol == EOF)
                break;
            symbol = (char)fgetc(file->file_result);
            ++length;
            if(symbol == '\n')
            {
                file->rows_result++;
                if(length > file->columns_result)
                    file->columns_result = length;
                length = 0;
            }
        }
        file->rows_result++;
        file->columns_result++;
        // установка указателя в начало файла
        fseek(file->file_result, 0, SEEK_SET);
        // вывод сообщения об успешном открытии файла
        //printf_s("%s\n", "successful opening of the resulting file");
    }

    return !strcmp(mode, "r") ? 1 : !strcmp(mode, "w") ? 2 : !strcmp(mode, "a") ? 3 : 0;
}
// функция чтения данных из файла
char** fileRead(struct File* file, int TYPE)
{
    unsigned int index = 0;

    char symbol = '\0';
    char* string = NULL;
    char** arrayData = NULL;

    //********выделение памяти под**********//
    //****************ШАГ №1****************//
    //******двумерный массив с данными******//
    // исходный файл
    if(TYPE)
    {
        // выделение памяти под двумерный массив с данными
        arrayData = (char**)malloc(file->rows_source * sizeof (char*));
        for(unsigned int i = 0; i < file->rows_source; ++i)
            arrayData[i] = (char*)malloc(file->columns_source * sizeof (char));
        // выделение памяти под строку
        string = (char*)malloc(file->columns_source * sizeof (char));
    }
    // результативный файл
    else
    {
        // выделение памяти под двумерный массив с данными
        arrayData = (char**)malloc(file->rows_result * sizeof (char*));
        for(unsigned int i = 0; i < file->rows_result; ++i)
            arrayData[i] = (char*)malloc(file->columns_result * sizeof (char));
        // выделение памяти под строку
        string = (char*)malloc(file->columns_result * sizeof (char));
    }
    //******копирование данных******//
    //************ШАГ №2************//
    //******в двумерный массив******//
    // исходный файл
    if(TYPE)
    {
        // чтение файла
        // прочитать первый символ из файла(для проверки файла на пустоту)
        symbol = (char)fgetc(file->file_source);
        // если файл пустой
        if(symbol == EOF)
        {
            // установить указатель в начало файла
            //fseek(file->file_source, 0, SEEK_SET);
            // закрыть файл
            fclose(file->file_source);
            // прервать работу функции
            return NULL;
        }
        else
        {
            // установить указатель в начало файла
            fseek(file->file_source, 0, SEEK_SET);
        }
        // цикл чтения файла
        while(!feof(file->file_source))
        {
            // чтение строки из файла и последующее её копирование в массив с данными
            fgets(string, (int)file->columns_source, file->file_source);
            if(index <= file->rows_source)
            {
                strcpy_s(arrayData[index], file->columns_source, string);
                ++index;
            }
        }
        // установка указателя в начало файла
        fseek(file->file_source, 0, SEEK_SET);
        // закрытие файла
        fclose(file->file_source);
    }
    // результативный файл
    else
    {
        // прочитать первый символ из файла(для проверки файла на пустоту)
        symbol = (char)fgetc(file->file_result);
        // если файл пустой
        if(symbol == EOF)
        {
            // установить указатель в начало файла
            //fseek(file->file_result, 0, SEEK_SET);
            // закрыть файл
            fclose(file->file_result);
            // прервать работу цикла
            return NULL;
        }
        else
        {
            // установить указатель в начало файла
            fseek(file->file_result, 0, SEEK_SET);
        }
        // чтение файла
        while(!feof(file->file_result))
        {
            // чтение строки из файла и последующее её копирование в массив с данными
            fgets(string, (int)file->columns_result, file->file_result);
            if(index <= file->rows_result)
            {
                strcpy_s(arrayData[index], file->columns_result, string);
                ++index;
            }
        }
        // установка указателя в начало файла
        fseek(file->file_result, 0, SEEK_SET);
        // закрытие файла
        fclose(file->file_result);
    }

    free(string);
    return arrayData;
}
// функция записи данных в файл
int fileWrite(struct File* file, char** arrayData, unsigned int rows, int TYPE)
{
    char symbol = '\0';
    char* string;
    unsigned int length = 0;
    unsigned int index = 0;

    // запись в исходный файл
    if(TYPE)
    {
        /*
        // если файл не открылся, вывести ошибку
        if(file->file_source == NULL)
        {
            printf_s("%s\n", "error opening source file for writing");
            return 0;
        }
        */
        // запись данных в файл из другого файла
        if(arrayData == NULL)
        {
            // прочитать первый символ из файла(для проверки файла на пустоту)
            symbol = (char)fgetc(file->file_result);
            // если файл пустой
            if(symbol == EOF)
            {
                // установить указатель в начало файла
                //fseek(file->file_result, 0, SEEK_SET);
                // закрыть файл
                fclose(file->file_result);
                // прервать работу функции
                return EOF;
            }
            else
            {
                // установить указатель в начало файла
                fseek(file->file_result, 0, SEEK_SET);
            }
            // выделение памяти для строки
            string = (char*)malloc(file->columns_result * sizeof (char));
            // цикл чтения файла
            while(!feof(file->file_result))
            {
                fgets(string, (int)file->columns_result, file->file_result);
                fputs(string, file->file_source);
            }
            free(string);
            // установка указателя в начало файла
            fseek(file->file_source, 0, SEEK_SET);
            fseek(file->file_result, 0, SEEK_SET);
            // закрытие файлов
            fclose(file->file_source);
            fclose(file->file_result);
        }
        // запись данных в файл из двумерного массива данных
        else
        {
            while(index < rows)
            {
                length = strlen(arrayData[index]) + 1;
                string = (char*)malloc(length * sizeof (char) + 1);
                strcpy_s(string, length, arrayData[index]);
                fputs(string, file->file_source);
                ++index;
                free(string);
            }
            // установка указателя в начало файла
            fseek(file->file_source, 0, SEEK_SET);
            // закрытие файла
            fclose(file->file_source);
        }
    }
    // запись в результативный файл
    else
    {
        /*
        // если файл не открылся, вывести ошибку
        if(file->file_result == NULL)
        {
            printf_s("%s\n", "error opening resulting file for writing");
            return 0;
        }
        */
        // запись данных в файл из другого файла
        if(arrayData == NULL)
        {
            // прочитать первый символ из файла(для проверки файла на пустоту)
            symbol = (char)fgetc(file->file_source);
            // если файл пустой
            if(symbol == EOF)
            {
                // установить указатель в начало файла
                //fseek(file->file_source, 0, SEEK_SET);
                // закрыть файл
                fclose(file->file_source);
                // прервать работу функции
                return EOF;
            }
            else
            {
                // установить указатель в начало файла
                fseek(file->file_source, 0, SEEK_SET);
            }
            // выделение памяти для строки
            string = (char*)malloc(file->columns_source * sizeof (char));
            // цикл чтения файла
            while(!feof(file->file_source))
            {
                string = fgets(string, (int)file->columns_source, file->file_source);
                fputs(string, file->file_result);
            }
            free(string);
            // установка указателя в начало файла
            fseek(file->file_result, 0, SEEK_SET);
            fseek(file->file_source, 0, SEEK_SET);
            // закрытие файлов
            fclose(file->file_result);
            fclose(file->file_source);
        }
        // запись данных в файл из двумерного массива данных
        else
        {
            while(index < rows)
            {
                length = strlen(arrayData[index]) + 1;
                string = (char*)malloc(length * sizeof (char));
                strcpy_s(string, length, arrayData[index]);
                fputs(string, file->file_result);
                ++index;
                free(string);
            }
            // установка указателя в начало файла
            fseek(file->file_result, 0, SEEK_SET);
            // закрытие файла
            fclose(file->file_result);
        }
    }

    return 1;
}

/*
"r" — открыть файл для чтения (файл должен существовать); 1
"w" — открыть пустой файл для записи; если файл существует, то его содержимое теряется; 2
"a" — открыть файл для записи в конец (для добавления); файл создается, если он не существует; 3
"r+" — открыть файл для чтения и записи (файл должен существовать); 4
"w+" — открыть пустой файл для чтения и записи; если файл существует, то его содержимое теряется; 5
"a+" — открыть файл для чтения и дополнения, если файл не существует, то он создаётся. 6
*/


//char** fileRead(struct File* file, int type)
//{
//    char symbol = 0;
//    char* string = NULL;
//    char** arrayData = NULL;

//    unsigned int length = 0;
//    unsigned int index = 0;

//    file->rows_source = 0;
//    file->columns_source = 0;
//    file->rows_result = 0;
//    file->columns_result = 0;

//    //*******количество строк*******//
//    //************ШАГ №1************//
//    //***********в файле************//
//    // исходный файл
//    if(type == 1)
//    {
//        // если файл не был открыт для чтения
//        if(file->file_source == NULL)
//        {
//            printf_s("%s\n", "source file read error");
//            return NULL;
//        }
//        // чтение файла
//        while(!feof(file->file_source))
//        {
//            symbol = (char)fgetc(file->file_source);
//            ++length;
//            if(symbol == '\n')
//            {
//                file->rows_source++;
//                if(length > file->columns_source)
//                    file->columns_source = length;
//                length = 0;
//            }
//        }
//        // установка указателя в начало файла
//        fseek(file->file_source, 0, SEEK_SET);
//    }
//    // результативный файл
//    else
//    {
//        // если файл не был открыт для чтения
//        if(file->file_result == NULL)
//        {
//            printf_s("%s\n", "result file read error");
//            return NULL;
//        }
//        // чтение файла
//        while(!feof(file->file_result))
//        {
//            symbol = (char)fgetc(file->file_result);
//            ++length;
//            if(symbol == '\n')
//            {
//                file->rows_result++;
//                if(length > file->columns_result)
//                    file->columns_result = length;
//                length = 0;
//            }
//        }
//        // установка указателя в начало файла
//        fseek(file->file_result, 0, SEEK_SET);
//    }
//    //********выделение памяти под**********//
//    //****************ШАГ №2****************//
//    //******двумерный массив с данными******//
//    // исходный файл
//    if(type == 1)
//    {
//        file->rows_source++;
//        file->columns_source++;
//        // выделение памяти под двумерный массив с данными
//        arrayData = (char**)malloc(file->rows_source * sizeof (char*));
//        for(unsigned int i = 0; i < file->rows_source; ++i)
//            arrayData[i] = (char*)malloc(file->columns_source * sizeof (char));
//        // выделение памяти под строку
//        string = (char*)malloc(file->columns_source * sizeof (char));
//    }
//    // результативный файл
//    else
//    {
//        file->rows_result++;
//        file->columns_result++;
//        // выделение памяти под двумерный массив с данными
//        arrayData = (char**)malloc(file->rows_result * sizeof (char*));
//        for(unsigned int i = 0; i < file->rows_result; ++i)
//            arrayData[i] = (char*)malloc(file->columns_result * sizeof (char));
//        // выделение памяти под строку
//        string = (char*)malloc(file->columns_result * sizeof (char));
//    }
//    //******копирование данных******//
//    //************ШАГ №3************//
//    //******в двемерный массив******//
//    // исходный файл
//    if(type == 1)
//    {
//        // чтение файла
//        while(!feof(file->file_source))
//        {
//            fgets(string, (int)file->columns_source, file->file_source);
//            if(index <= file->rows_source)
//            {
//                strcpy_s(arrayData[index], file->columns_source, string);
//                ++index;
//            }
//        }
//        // установка указателя в начало файла
//        fseek(file->file_source, 0, SEEK_SET);
//        // закрытие файла
//        fclose(file->file_source);
//    }
//    // результативный файл
//    else
//    {
//        // чтение файла
//        while(!feof(file->file_result))
//        {
//            fgets(string, (int)file->columns_result, file->file_result);
//            strcpy_s(arrayData[index], file->columns_result, string);
//            ++index;
//        }
//        // установка указателя в начало файла
//        fseek(file->file_result, 0, SEEK_SET);
//        // закрытие файла
//        fclose(file->file_result);
//    }

//    return arrayData;
//}

