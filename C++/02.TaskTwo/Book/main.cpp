#include "list.h"

/*
Создайте класс Book
Необходимо хранить данные: Автор, Название, Издательство,
Год, Количество, страниц.
Создать односвязный линейный список объектов. Вывести:
■ список книг заданного автора;
■ список книг, выпущенных заданным издательством;
■ список книг, выпущенных после заданного года.
Используйте explicit конструктор и константные функции - члены (например, для отображения данных о книге и т.д.)
*/

void menu();

int main(int, char**)
{
    const char pathFile[] = "C:/Projects/C++/ItStep/PracticeWork/02.TaskTwo/Book/list of books.txt";

    Book book;

    std::ofstream file;

    list* listBooksAll = nullptr;
    list* listBooksAuthor = nullptr;
    list* listBooksPublisher = nullptr;
    list* listBooksYear = nullptr;

    int choice = 0;

    do
    {
        system("cls");
        menu();
        std::cout << "select menu item: ";
        std::cin >> choice;
        switch(choice)
        {
            // заполнение главного списка(список со всеми книгами)
            case 1:
            {
                int selection = 0;

                std::cin.ignore();
                file.open(pathFile, std::ios::app);
                if(!file)
                    std::cout << "*error* opening file" << std::endl;
                system("cls");
                listBooksAll = listBooksAll->initialization();
                if(file.is_open())
                    file << *(listBooksAll->getBookInfo());

                std::cout << "continue(1.yes/0.no): ";
                std::cin >> selection;
                while(selection)
                {
                    std::cin.ignore();
                    system("cls");
                    book.input();
                    if(file.is_open())
                        file << book;
                    listBooksAll = listBooksAll->addElemTail(book);
                    std::cout << "continue(1.yes/0.no): ";
                    std::cin >> selection;
                }

                file.close();
                break;
            }
            // список книг заданного автора
            case 2:
            {
                char author[256];

                std::cin.ignore();
                std::cout << "enter the author of the book: ";
                std::cin.getline(author, ' ');

                listBooksAuthor = listBooksAll->searchElementAuthor(author);

                system("cls");
                if(listBooksAuthor != nullptr)
                    listBooksAuthor->show();
                else
                    std::cout << "There are no books by this author in the list" << std::endl;

                break;
            }
            // список книг, выпущенных заданным издательством
            case 3:
            {
                char publisher[256];

                std::cin.ignore();
                std::cout << "enter publisher of the book: ";
                std::cin.getline(publisher, ' ');

                listBooksPublisher = listBooksAll->searchElementPublisher(publisher);

                system("cls");
                if(listBooksPublisher != nullptr)
                    listBooksPublisher->show();
                else
                    std::cout << "There are no books with this publisher in the list" << std::endl;

                break;
            }
            // список книг выпущенных после заданного года
            case 4:
            {
                char year[256];

                std::cin.ignore();
                std::cout << "enter the year the book was published: ";
                std::cin.getline(year, ' ');

                listBooksYear = listBooksAll->searchElementYear(year);

                system("cls");
                if(listBooksYear != nullptr)
                    listBooksYear->show();
                else
                    std::cout << "There are no books published after the given year in the list" << std::endl;

                break;
            }
            // вывод всех элементов списка
            case 5:
            {
                system("cls");
                listBooksAll->show();
                std::cout << "number of elements in the list: " << listBooksAll->getAmount() << std::endl;
                break;
            }
            case 0:
                break;
            default:
                std::cout << "select the correct menu item" << std::endl;
                break;
        }
        if(choice)
        {
            std::cout << "complete the program(0.yes/1.no): ";
            std::cin >> choice;
        }
    }while(choice);

    std::cout << "end of program" << std::endl;
    return 0;
}

void menu()
{
    const size_t length = 50;
    size_t spaceAmount = 0;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = (length - strlen("menu")) / 2;
    std::cout << '|';
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << "menu";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = length - strlen("1. create book list");
    std::cout << '|' << "1. create book list";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = length - strlen("2. list of books by a given author");
    std::cout << '|' << "2. list of books by a given author";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = length - strlen("3. list of books released by a given publisher");
    std::cout << '|' << "3. list of books released by a given publisher";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = length - strlen("4. list of books released after a given year");
    std::cout << '|' << "4. list of books released after a given year";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = length - strlen("5. listing all books");
    std::cout << '|' << "5. listing all books";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = length - strlen("0. exit");
    std::cout << '|' << "0. exit";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;
}

/*
list* foundElementAddress = nullptr;
list* pointerRootList = this;

char* author = nullptr;

do
{
    author = pointerRootList->element.getAuthor();
    if(!strcmp(author, value))
    {
        foundElementAddress = pointerRootList;
        return foundElementAddress;
    }
    pointerRootList = pointerRootList->ptrNextElem;
}while(pointerRootList != nullptr);

return foundElementAddress;
*/

/*
// узел(элемент) списка
struct node
{
        Book element;
        node* pointer;
        node() : pointer(nullptr){} // конструктор без параметров
        node(const Book& book) : element(book), pointer(nullptr) {} // конструктор с одним параметром
};
*/

// добавление элемента в список
//list* addElem(list* nodeAfterAdd, const Book& book)
//{
//    list *newNode, *ptrNodeAfterCurr
//}
//list* delElem(node* nodeDel, node* rootList);

/*
    spaceAmount = length - strlen("5. listing books by a specific author");
    std::cout << '|' << "5. listing books by a specific author";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = length - strlen("6. list of books released by a given publisher");
    std::cout << '|' << "6. list of books released by a given publisher";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;

    spaceAmount = length - strlen("7. a list of books published after a given year");
    std::cout << '|' << "7. a list of books published after a given year";
    for(size_t i = 0; i < spaceAmount; ++i)
        std::cout << ' ';
    std::cout << '|' << std::endl;

    std::cout << '+';
    for(size_t i = 0; i < length; ++i)
        std::cout << '-';
    std::cout << '+' << std::endl;
*/
