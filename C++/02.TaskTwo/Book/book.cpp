#include "book.h"
// ввод данных
bool Book::input()
{
    const char emptyLine[] = " undefined";

    const size_t length = 512;
    const size_t alloweSize = 4;
    size_t size = 0;

    bool success = false;
    bool access = false;

    char string[length];
    // ввод автора
    std::cout << "enter book author: ";
    std::cin.getline(string, ' ');

    if(strlen(string))
    {
        size = strlen(string) + 1;
        author = new char[size];
        strcpy_s(author, size * sizeof(char), string);
    }
    else
    {
        size = strlen(emptyLine) + 1;
        author = new char[size];
        strcpy_s(author, size * sizeof (char), emptyLine);
    }
    // ввод названия книги
    std::cout << "enter book tittle: ";
    std::cin.getline(string, ' ');

    if(strlen(string))
    {
        size = strlen(string) + 1;
        tittle = new char[size];
        strcpy_s(tittle, size * sizeof(char), string);
    }
    else
    {
        size = strlen(emptyLine) + 1;
        tittle = new char[size];
        strcpy_s(tittle, size * sizeof (char), emptyLine);
    }
    // ввод издания
    std::cout << "enter the publishing house: ";
    std::cin.getline(string, ' ');

    if(strlen(string))
    {
        size = strlen(string) + 1;
        publisher = new char[size];
        strcpy_s(publisher, size * sizeof(char), string);
    }
    else
    {
        size = strlen(emptyLine) + 1;
        publisher = new char[size];
        strcpy_s(publisher, size * sizeof (char), emptyLine);
    }
    // ввод года выпуска книги
    INPUTYEAR:
    std::cout << "enter the year the book was published: ";
    std::cin.getline(string, ' ');
    if(strlen(string) == alloweSize)
    {
        for(size_t i = 0; i < alloweSize; ++i)
        {
            if(string[i] >= '0' && string[i] <= '9')
            {
                if(i == 0 && string[i] == '0')
                {
                    access = false;
                    break;
                }
                access = true;
            }
            else
            {
                access = false;
                break;
            }
        }
        if(access)
        {
            size = strlen(string) + 1;
            year = new char[size];
            strcpy_s(year, size * sizeof(char), string);
        }
        else
        {
            std::cout << "enter valid year value, *error*" << std::endl;
            goto INPUTYEAR;
        }
    } else goto INPUTYEAR;
    // ввод количества книг
    INPUTAMOUNT:
    std::cout << "enter the number of books in stock: ";
    std::cin.getline(string, ' ');

    for(size_t i = 0; i < strlen(string); ++i)
    {
        if(string[i] >= '0' && string[i] <= '9')
            access = true;
        else
        {
            access = false;
            break;
        }
    }

    if(access)
        amount = atoi(string);
    else
    {
        std::cout << "enter the correct values for the number of books, *error*" << std::endl;
        goto INPUTAMOUNT;
    }

    success = true;
    return success;
}
// вывод данных
void Book::output()
{
    //const char tittle[] = "Tittle:";
    const char author[] = "Author:";
    const char publisher[] = "Publisher:";
    const char year[] = "Release year:";
    const char amount[] = "Amount:";

    char digitCapacity[15];

    char charWrap = '*';
    const size_t length = 50;
    size_t spaceAmount = 0;

    //system("cls");
    std::cout << charWrap;
    for(size_t i = 0; i < length + 4; ++i)
        std::cout << charWrap;
    std::cout << charWrap << std::endl;
    /*
    std::cout << charWrap;
    for(size_t i = 0; i < length + 4; ++i)
        std::cout << ' ';
    std::cout << charWrap << std::endl;
    */
    // название книги
    std::cout << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << ' ' << charWrap << std::endl;

    spaceAmount = (length - strlen(this->tittle)) / 2;
    std::cout << charWrap << ' ' << '|';
    for(size_t i = 0;i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << this->tittle;
    if(strlen(this->tittle) % 2 != 0)
        ++spaceAmount;
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << ' ' << charWrap << std::endl;
    // автор
    std::cout << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << ' ' << charWrap << std::endl;

    std::cout << charWrap << ' ' << '|' << author;
    spaceAmount = length - (strlen(author) + strlen(this->author));
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << this->author << '|' << ' ' << charWrap << std::endl;
    // издательство
    std::cout << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << ' ' << charWrap << std::endl;

    std::cout << charWrap << ' ' << '|' << publisher;
    spaceAmount = length - (strlen(publisher) + strlen(this->publisher));
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << this->publisher << '|' << ' ' << charWrap << std::endl;
    // год выпуска книги
    std::cout << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << ' ' << charWrap << std::endl;

    std::cout << charWrap << ' ' << '|' << year;
    spaceAmount = length - (strlen(year) + strlen(this->year));
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << this->year << '|' << ' ' << charWrap << std::endl;
    // количество
    std::cout << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << ' ' << charWrap << std::endl;

    std::cout << charWrap << ' ' << '|' << amount;
    itoa(this->amount, digitCapacity, 10);
    spaceAmount = length - (strlen(amount) + strlen(digitCapacity));
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << this->amount << '|' << ' ' << charWrap << std::endl;

    std::cout << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << ' ' << charWrap << std::endl;
    /*
    std::cout << charWrap;
    for(size_t i = 0; i < length + 4; ++i)
        std::cout << ' ';
    std::cout << charWrap << std::endl;
    */
    std::cout << charWrap;
    for(size_t i = 0; i < length + 4; ++i)
        std::cout << charWrap;
    std::cout << charWrap << std::endl;
}
// запись данных в файл
std::ofstream& operator<<(std::ofstream& file, const Book& book)
{
    const char author[] = "Author:";
    const char publisher[] = "Publisher:";
    const char year[] = "Release year:";
    const char amount[] = "Amount:";

    char digitCapacity[15];

    char charWrap = '*';
    const size_t length = 50;
    size_t spaceAmount = 0;

    file << charWrap;
    for(size_t i = 0; i < length + 4; ++i)
        file << charWrap;
    file << charWrap << std::endl;

    // название книги
    file << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        file << '-';
    file << '+' << ' ' << charWrap << std::endl;

    spaceAmount = (length - strlen(book.tittle)) / 2;
    file << charWrap << ' ' << '|';
    for(size_t i = 0;i < spaceAmount; ++i)
        file << ' ';
    file << book.tittle;
    if(strlen(book.tittle) % 2 != 0)
        ++spaceAmount;
    for(size_t i = 0; i < spaceAmount; ++i)
        file << ' ';
    file << '|' << ' ' << charWrap << std::endl;
    // автор
    file << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        file << '-';
    file << '+' << ' ' << charWrap << std::endl;

    file << charWrap << ' ' << '|' << author;
    spaceAmount = length - (strlen(author) + strlen(book.author));
    for(size_t i = 0; i < spaceAmount; ++i)
        file << ' ';
    file << book.author << '|' << ' ' << charWrap << std::endl;
    // издательство
    file << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        file << '-';
    file << '+' << ' ' << charWrap << std::endl;

    file << charWrap << ' ' << '|' << publisher;
    spaceAmount = length - (strlen(publisher) + strlen(book.publisher));
    for(size_t i = 0; i < spaceAmount; ++i)
        file << ' ';
    file << book.publisher << '|' << ' ' << charWrap << std::endl;
    // год выпуска книги
    file << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        file << '-';
    file << '+' << ' ' << charWrap << std::endl;

    file << charWrap << ' ' << '|' << year;
    spaceAmount = length - (strlen(year) + strlen(book.year));
    for(size_t i = 0; i < spaceAmount; ++i)
        file << ' ';
    file << book.year << '|' << ' ' << charWrap << std::endl;
    // количество
    file << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        file << '-';
    file << '+' << ' ' << charWrap << std::endl;

    file << charWrap << ' ' << '|' << amount;
    itoa(book.amount, digitCapacity, 10);
    spaceAmount = length - (strlen(amount) + strlen(digitCapacity));
    for(size_t i = 0; i < spaceAmount; ++i)
        file << ' ';
    file << book.amount << '|' << ' ' << charWrap << std::endl;

    file << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        file << '-';
    file << '+' << ' ' << charWrap << std::endl;

    file << charWrap;
    for(size_t i = 0; i < length + 4; ++i)
        file << charWrap;
    file << charWrap << std::endl;

    return file;
}
// перегрузка операторы <<(вывода)
std::ostream& operator<<(std::ostream& output, const Book& book)
{
    const char author[] = "Author:";
    const char publisher[] = "Publisher:";
    const char year[] = "Release year:";
    const char amount[] = "Amount:";

    char digitCapacity[15];

    char charWrap = '*';
    const size_t length = 50;
    size_t spaceAmount = 0;

    output << charWrap;
    for(size_t i = 0; i < length + 4; ++i)
        output << charWrap;
    output << charWrap << std::endl;

    // название книги
    output << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        output << '-';
    output << '+' << ' ' << charWrap << std::endl;

    spaceAmount = (length - strlen(book.tittle)) / 2;
    output << charWrap << ' ' << '|';
    for(size_t i = 0;i < spaceAmount; ++i)
        output << ' ';
    output << book.tittle;
    if(strlen(book.tittle) % 2 != 0)
        ++spaceAmount;
    for(size_t i = 0; i < spaceAmount; ++i)
        output << ' ';
    output << '|' << ' ' << charWrap << std::endl;
    // автор
    output << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        output << '-';
    output << '+' << ' ' << charWrap << std::endl;

    output << charWrap << ' ' << '|' << author;
    spaceAmount = length - (strlen(author) + strlen(book.author));
    for(size_t i = 0; i < spaceAmount; ++i)
        output << ' ';
    output << book.author << '|' << ' ' << charWrap << std::endl;
    // издательство
    output << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        output << '-';
    output << '+' << ' ' << charWrap << std::endl;

    output << charWrap << ' ' << '|' << publisher;
    spaceAmount = length - (strlen(publisher) + strlen(book.publisher));
    for(size_t i = 0; i < spaceAmount; ++i)
        output << ' ';
    output << book.publisher << '|' << ' ' << charWrap << std::endl;
    // год выпуска книги
    output << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        output << '-';
    output << '+' << ' ' << charWrap << std::endl;

    output << charWrap << ' ' << '|' << year;
    spaceAmount = length - (strlen(year) + strlen(book.year));
    for(size_t i = 0; i < spaceAmount; ++i)
        output << ' ';
    output << book.year << '|' << ' ' << charWrap << std::endl;
    // количество
    output << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        output << '-';
    output << '+' << ' ' << charWrap << std::endl;

    output << charWrap << ' ' << '|' << amount;
    itoa(book.amount, digitCapacity, 10);
    spaceAmount = length - (strlen(amount) + strlen(digitCapacity));
    for(size_t i = 0; i < spaceAmount; ++i)
        output << ' ';
    output << book.amount << '|' << ' ' << charWrap << std::endl;

    output << charWrap << ' ' << '+';
    for(size_t i = 0; i < length; ++i)
        output << '-';
    output << '+' << ' ' << charWrap << std::endl;

    output << charWrap;
    for(size_t i = 0; i < length + 4; ++i)
        output << charWrap;
    output << charWrap << std::endl;

    return output;
}
