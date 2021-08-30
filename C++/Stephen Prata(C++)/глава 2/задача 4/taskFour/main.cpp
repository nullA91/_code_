#include <iostream>

int main() {
    short age;
    std::cout << "введите свой возраст: ";
    std::cin >> age;
    std::cout << "ваш возраст в месяцах: " << age * 12 << std::endl;
    return 0;
}
