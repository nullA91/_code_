#ifndef LIST_H
#define LIST_H

#include "book.h"
// список
class list
{
    private:
        int amount;
        Book element;
        list* ptrNextElem;
    public:
        // ******************** //
        // *** конструкторы *** //
        // ******************** //
        // конструктор без параметров
        list() : amount(0), element(), ptrNextElem(nullptr) {}
        // конструктор копирования
        list(const list& _list)
        {
            this->amount = _list.amount;
            this->element = _list.element;
            this->ptrNextElem = _list.ptrNextElem;
        }
        // ******************** //
        // ****** методы ****** //
        // ******************** //
        // инициализация списка
        list* initialization()
        {
            list* newList = new list[sizeof (list)];

            newList->amount = 1;
            newList->element.input();
            newList->ptrNextElem = nullptr;

            return newList;
        }
        // перегруженная функция инициализации списка принимающая один параметр
        list* initialization(const Book& book)
        {
            list* newList = new list[sizeof (list)];

            newList->amount = 1;
            newList->element = book;
            newList->ptrNextElem = nullptr;

            return newList;
        }
        // добавление элемента в начало списка
        list* addElemHead(const Book& book)
        {
            list* newElement = new list[sizeof (list)];

            newElement->amount = ++amount;
            newElement->element = book;
            newElement->ptrNextElem = this;

            return newElement;
        }
        // добавление элемента в конец списка
        list* addElemTail(const Book& book)
        {
            list* ptrRootList = this;
            list* newElement = new list[sizeof (list)];

            newElement->amount = ++amount;
            newElement->element = book;

            if(this->ptrNextElem == nullptr)
            {
                this->ptrNextElem = newElement;
                newElement->ptrNextElem = nullptr;
            }
            else
            {
                while(ptrRootList->ptrNextElem != nullptr)
                    ptrRootList = ptrRootList->ptrNextElem;

                ptrRootList->ptrNextElem = newElement;
                newElement->ptrNextElem = nullptr;
            }

            return this;
        }
        // поиск элемента в списке по заданному автору
        list* searchElementAuthor(const char* value)
        {
            bool initialization = true;

            list* listAuthor = nullptr;
            list* ptrRootList = this;

            char * author = nullptr;

            do
            {
                author = ptrRootList->element.getAuthor();
                if(!strcmp(author, value))
                {
                    if(initialization)
                    {
                        listAuthor = listAuthor->initialization(ptrRootList->element);
                        initialization = false;
                    }
                    else
                        listAuthor = listAuthor->addElemHead(ptrRootList->element);
                }
                ptrRootList = ptrRootList->ptrNextElem;
            }while(ptrRootList != nullptr);

            return listAuthor;
        }
        // поиск элемента по заданному издательству
        list* searchElementPublisher(const char* value)
        {
            bool initialization = true;

            list* listPublisher = nullptr;
            list* ptrRootList = this;

            char * publisher = nullptr;

            do
            {
                publisher = ptrRootList->element.getPublisher();
                if(!strcmp(publisher, value))
                {
                    if(initialization)
                    {
                        listPublisher = listPublisher->initialization(ptrRootList->element);
                        initialization = false;
                    }
                    else
                        listPublisher = listPublisher->addElemHead(ptrRootList->element);
                }
                ptrRootList = ptrRootList->ptrNextElem;
            }while(ptrRootList != nullptr);

            return listPublisher;
        }
        // поиск элемента по заданному году
        list* searchElementYear(const char* value)
        {
            bool initialization = true;

            list* listYear = nullptr;
            list* ptrRootList = this;

            char * year = nullptr;
            int yearNext = 0;
            int yearCurr = 0;

            yearNext = atoi(value);
            ++yearNext;

            do
            {
                year = ptrRootList->element.getYear();
                yearCurr = atoi(year);
                if(yearNext >= yearCurr)
                {
                    if(initialization)
                    {
                        listYear = listYear->initialization(ptrRootList->element);
                        initialization = false;
                    }
                    else
                        listYear = listYear->addElemHead(ptrRootList->element);
                }
                ptrRootList = ptrRootList->ptrNextElem;
            }while(ptrRootList != nullptr);

            return listYear;
        }
        // вывод списка
        void show()
        {
            list* pointerRootList;

            pointerRootList = this;

            do
            {
                pointerRootList->element.output();
                pointerRootList = pointerRootList->ptrNextElem;
            } while (pointerRootList != nullptr);
        }
        // ********************* //
        // ***** аксессоры ***** //
        // ********************* //
        // получить поле с данными(книгу) из узла списка
        Book* getBookInfo() { return &element; }
        // получить количество элементов списка
        int getAmount() { return amount; }
};

#endif // LIST_H
