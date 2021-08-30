#include <iostream>

int main() {
    char name[] = "Артур";
    char surname[] = "Усеня";
    char middlename[] = "Завенович";
    char street[] = "Нестерова";
    short houseNumber = 84;
    short apartmentNumber = 71;

    std::cout << "+-----------+-----------+------------+" << std::endl;
    std::cout << "|  Фамилия  |    Имя    |  Отчество  |" << std::endl;
    std::cout << "+-----------+-----------+------------+" << std::endl;
    std::cout << "|   " << surname << "   |";
    std::cout << "   " << name << "   |";
    std::cout << "  " << middlename << " |" << std::endl;
    std::cout << "+-----------+-----------+------------+" << std::endl;
    std::cout << "|                                    |" << std::endl;
    std::cout << "+-----------+-----------+------------+" << std::endl;
    std::cout << "|   Улица   |   Дом №   | Квартира № |" << std::endl;
    std::cout << "+-----------+-----------+------------+" << std::endl;
    std::cout << "| " << street << " |";
    std::cout << "    " << houseNumber << "     |";
    std::cout << "     " << apartmentNumber << "     |" << std::endl;
    std::cout << "+-----------+-----------+------------+" << std::endl;
    return 0;
}
