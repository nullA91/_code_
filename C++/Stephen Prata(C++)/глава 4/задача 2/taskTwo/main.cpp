#include <iostream>

int main() {
    std::string name;
    std::string dessert;
    std::cout << "введите ваше имя: ";
    getline(std::cin, name);
    std::cout << "введите название вашего любимого десерта: ";
    getline(std::cin, dessert);
    std::cout << "у меня есть вкусный: " << dessert << " для " << name << '.' << std::endl;
    return 0;
}
