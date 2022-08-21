#include <iostream>

struct pizza {
    std::string name;
    short diameter;
    short weight;
};

int main() {
    pizza _pizza;
    std::cout << "введите название пиццерии: ";
    getline(std::cin, _pizza.name);
    std::cout << "введите диаметр пиццы: ";
    std::cin >> _pizza.diameter;
    std::cout << "введите вес пиццы: ";
    std::cin >> _pizza.weight;
    std::cout << "наименование компании: " << _pizza.name << ';' << std::endl;
    std::cout << "диаметр пиццы: " << _pizza.diameter << ';' << std::endl;
    std::cout << "вес пиццы: " << _pizza.weight << ';' << std::endl;
    return 0;
}
