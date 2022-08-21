#include "../../Headers/functions.h"

// функция считает количество слов в файле, начинающихся с заданного пользователем символа
unsigned int numberWordsFile(struct File* file, const char symbol, const int TYPE)
{
    char symbol_file = '\0';
    unsigned int wordCount = 0;
    // исходный файл
    if(TYPE)
    {
        // пока не конец файла
        while(!feof(file->file_source))
        {
            // считать символ из файла
            symbol_file = (char)fgetc(file->file_source);
            // если файл пустой завершить работу цикла
            if(symbol_file == EOF)
            {
                // установить указатель в начало файла
                fseek(file->file_source, 0, SEEK_SET);
                // закрыть файл
                fclose(file->file_source);
                // прервать работу цикла
                break;
            }
            // если считанный из файла символ равен букве
            if( (symbol_file >= 'A' && symbol_file <= 'Z') || (symbol_file >= 'a' && symbol_file <= 'z') )
            {
                // если символ(первая буква слова) равен введенному пользователем символу
                if(symbol_file == symbol)
                    ++wordCount; // увеличить счетчик слов на еденицу
                // продолжает считывание символов из файла пока слово не закончится
                CONTINUE:
                symbol_file = (char)fgetc(file->file_source);
                while((symbol_file >= 'A' && symbol_file <= 'Z') || (symbol_file >= 'a' && symbol_file <= 'z'))
                    goto CONTINUE;
            }
            else
                continue;
        }
        // закрытие файла
        fclose(file->file_source);
    }
    // результативный файл
    else
    {
        // пока не конец файла
        while(!feof(file->file_result))
        {
            // считать символ из файла
            symbol_file = (char)fgetc(file->file_result);
            // если файл пустой завершить работу цикла
            if(symbol_file == EOF)
            {
                // установить указатель в начало файла
                fseek(file->file_result, 0, SEEK_SET);
                // закрыть файл
                fclose(file->file_result);
                // прервать работу цикла
                break;
            }
            // если считанный из файла символ равен букве
            if( (symbol_file >= 'A' && symbol_file <= 'Z') || (symbol_file >= 'a' && symbol_file <= 'z') )
            {
                // если символ(первая буква слова) равен введенному пользователем символу
                if(symbol_file == symbol)
                    ++wordCount; // увеличить счетчик слов на еденицу
                // продолжает считывание символов из файла пока слово не закончится
                _CONTINUE_:
                symbol_file = (char)fgetc(file->file_result);
                while((symbol_file >= 'A' && symbol_file <= 'Z') || (symbol_file >= 'a' && symbol_file <= 'z'))
                    goto _CONTINUE_;
            }
            else
                continue;
        }
        // закрытие файла
        fclose(file->file_result);
    }
    // возвращает количество слов начинающихся с символа введенного пользователем
    return wordCount;
}
// функция считает количество символов(буквы, цифры, знаки препинания) в файле
unsigned int numberCharactersFile(struct File* file, const int TYPE)
{
    char symbol_file = '\0';
    unsigned int characterCount = 0;
    // исходный файл
    if(TYPE)
    {
        // пока не конец файла
        while(!feof(file->file_source))
        {
            // считать символ из файла
            symbol_file = (char)fgetc(file->file_source);
            // если файл пустой завершить работу цикла
            if(symbol_file == EOF)
                break;
            // если считанный из файла символ равен цифре
            if(symbol_file >= '0' && symbol_file <= '9')
                ++characterCount; // увеличить счетчик символов на еденицу
            // если считанный из файла символ равен букве
            else if( (symbol_file >= 'A' && symbol_file <= 'Z') || (symbol_file >= 'a' && symbol_file <= 'z') )
                ++characterCount; // увеличить счетчик символов на еденицу
            // если считанный из файла символ равен знаку препинания
            else if( symbol_file == '.' || symbol_file == ',' || symbol_file == ':' || symbol_file == '-' || symbol_file == '!' || symbol_file == '?')
                ++characterCount; // увеличить счетчик символов на еденицу
            else
                continue;
        }
        fclose(file->file_source);
    }
    // результативный файл
    else
    {
        // пока не конец файла
        while(!feof(file->file_result))
        {
            // считать символ из файла
            symbol_file = (char)fgetc(file->file_result);
            // если файл пустой завершить работу цикла
            if(symbol_file == EOF)
                break;
            // если считанный из файла символ равен цифре
            if(symbol_file >= '0' && symbol_file <= '9')
                ++characterCount; // увеличить счетчик символов на еденицу
            // если считанный из файла символ равен букве
            else if( (symbol_file >= 'A' && symbol_file <= 'Z') || (symbol_file >= 'a' && symbol_file <= 'z') )
                ++characterCount; // увеличить счетчик символов на еденицу
            // если считанный из файла символ равен знаку препинания
            else if( symbol_file == '.' || symbol_file == ',' || symbol_file == ':' || symbol_file == '-' || symbol_file == '!' || symbol_file == '?' )
                ++characterCount; // увеличить счетчик символов на еденицу
            else
                continue;
        }
        fclose(file->file_result);
    }
    // возвращает количество символов в файле
    return characterCount;
}
// меню программы
void menu()
{
    const unsigned int length = 100;
    const unsigned int rows = 5;
    const unsigned int columns = 128;

    unsigned int characterCounter = 0;
    unsigned int index = 0;

    char symbol = '\0';
    char menuItems[5][128];

    strcpy_s(menuItems[0], columns, "1: counting the number of words in a file (starting with a character entered by the user)."); // подсчет количества слов в файле(начинающихся с символа введенного пользователем
    strcpy_s(menuItems[1], columns, "2: copying lines from one file to another (replacing the character 0 with 1 and vice versa)."); // копирование строк из одного файла в другой(с заменой символа 0 на 1 и наоборот
    strcpy_s(menuItems[2], columns, "3: copying strings from an array of strings to another file."); // копирпование строк из массива строк в другой файл
    strcpy_s(menuItems[3], columns, "4: counting the number of characters in a file."); // подсчет количества символов в файле
    strcpy_s(menuItems[4], columns, "5: counting the number of lines in a file."); // подсчет количества строк в файле

    // верхняя строка  меню
    printf_s("%c", '+');
    for(unsigned int i = 0; i < length; ++i)
        printf_s("%c", '-');
    printf_s("%c\n", '+');
    // середина верхней строки
    printf_s("%c", '|');
    for(unsigned int i = 0; i < (length - strlen("MENU")) / 2; ++i)
        printf_s("%c", ' ');
    printf_s("%s", "MENU");
    for(unsigned int i = 0; i < (length - strlen("MENU")) / 2; ++i)
        printf_s("%c", ' ');
    printf_s("%c\n", '|');
    // низ верхней строки
    printf_s("%c", '+');
    for(unsigned int i = 0; i < length; ++i)
        printf_s("%c", '-');
    printf_s("%c\n", '+');
    // пункты меню
    for(unsigned int i = 0; i < rows; ++i)
    {
        // вывод первого символа разделителя столбца
        printf_s("%c", '|');
        // вывод пункта меню
        printf_s("%s", menuItems[i]);

        index = 0;
        characterCounter = 0;
        symbol = 'X';
        // подсчет количества пробелов
        while (symbol != '.')
        {
            symbol = menuItems[i][index];
            ++characterCounter;
            ++index;
        }
        // вывод нужного количества пробелов до последнего символа разделителя столбца
        for(unsigned int j = characterCounter; j < length; ++j)
            printf_s("%c", ' ');
        // вывод последнего символа разделителя столбца
        printf_s("%c\n", '|');
        // низ строки пункта меню
        printf_s("%c", '+');
        for(unsigned int i = 0; i < length; ++i)
            printf_s("%c", '-');
        printf_s("%c\n", '+');
    }
    // нижняя строка  меню
    // середина нижней строки
    printf_s("%c", '|');
    printf_s("%s", "0: EXIT");
    for(unsigned int i = strlen("0: EXIT"); i < length; ++i)
        printf_s("%c", ' ');
    printf_s("%c\n", '|');
    // низ нижней строки
    printf_s("%c", '+');
    for(unsigned int i = 0; i < length; ++i)
        printf_s("%c", '-');
    printf_s("%c\n", '+');
}
