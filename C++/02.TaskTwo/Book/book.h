#ifndef BOOK_H
#define BOOK_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <typeinfo>

/*
Создайте класс Book
Необходимо хранить данные: Автор, Название, Издательство,
Год, Количество страниц.
Создать односвязный линейный список объектов. Вывести:
■ список книг заданного автора;
■ список книг, выпущенных заданным издательством;
■ список книг, выпущенных после заданного года.
Используйте explicit конструктор и константные функции - члены (например, для отображения данных о книге и т.д.)
*/

class Book
{
    private:
        char* author;
        char* tittle;
        char* publisher;
        char* year;
        int amount;
    public:
        // ******************** //
        // *** конструкторы *** //
        // ******************** //
        // конструктор без параметров
        explicit Book() : author(nullptr), tittle(nullptr), publisher(nullptr), year(nullptr), amount(0) {}
        //  конструктор с параметрами
        explicit Book(const char* author, const char* tittle, const char* publisher, const char* year, const int &amount)
        {
            size_t length = 0;
            // автор
            if(strlen(author))
            {
                length = strlen(author) + 1;
                this->author = new char[length];
                strcpy_s(this->author, length * sizeof (char), author);
            }
            else
            {
                length = 10;
                this->author = new char[length];
                strcpy_s(this->author, length * sizeof (char), "undefined");
            }
            // название
            if(strlen(tittle))
            {
                length = strlen(author) + 1;
                this->tittle = new char[length];
                strcpy_s(this->tittle, length * sizeof (char), tittle);
            }
            else
            {
                length = 10;
                this->tittle = new char[length];
                strcpy_s(this->tittle, length * sizeof (char), "undefined");
            }
            // издательство
            if(strlen(author))
            {
                length = strlen(publisher) + 1;
                this->publisher = new char[length];
                strcpy_s(this->publisher, length * sizeof (char), publisher);
            }
            else
            {
                length = 10;
                this->publisher = new char[length];
                strcpy_s(this->publisher, length * sizeof (char), "undefined");
            }
            // год
            if(strlen(year))
            {
                length = strlen(year) + 1;
                this->year = new char[length];
                strcpy_s(this->year, length * sizeof (char), year);
            }
            else
            {
                length = 10;
                this->year = new char[length];
                strcpy_s(this->year, length * sizeof (char), "undefined");
            }
            // количество
            this->amount = amount;
        }
        // конструктор копирования
        explicit Book(const Book& book)
        {
            (book.author == nullptr) ? author = nullptr : author = book.author;
            (book.tittle == nullptr) ? tittle = nullptr : tittle = book.tittle;
            (book.publisher == nullptr) ? publisher = nullptr : publisher = book.publisher;
            (book.year == nullptr) ? year = nullptr : year = book.year;
            amount = book.amount;
        }
        // деструктор
        ~Book()
        {
            if(author != nullptr) delete [] author;
            if(tittle != nullptr) delete [] tittle;
            if(publisher != nullptr) delete [] publisher;
            if(year != nullptr) delete [] year;
        }
        // ******************** //
        // ****** методы ****** //
        // ******************** //
        // ввод информации о книге
        bool input();
        // вывод информации о книге
        void output();
        // ********************************* //
        // ***** перегрузка операторов ***** //
        // ********************************* //
        // запись данных в файл
        friend std::ofstream& operator<<(std::ofstream& file, const Book& book);
        // перегрузка оператора <<(вывода)
        friend std::ostream& operator<<(std::ostream& output, const Book& book);
        // ********************* //
        // ***** аксессоры ***** //
        // ********************* //
        // получить поле данных объекта книга(автор)
        char* getAuthor() { return author; }
        // получить поле данных объекта книга(издательство)
        char* getPublisher() { return publisher; }
        // получить поле данных объекта книга(год)
        char* getYear() { return year; }
};

#endif // BOOK_H
