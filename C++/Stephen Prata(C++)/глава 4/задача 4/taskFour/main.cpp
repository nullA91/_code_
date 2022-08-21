#include <iostream>

int main() {
    std::string name;
    std::string surname;
    std::cout << "введите ваше имя: ";
    std::cin >> name;
    std::cout << "введите вашу фамилию: ";
    std::cin >> surname;
    std::cout << "введенная информация в одной строке: " << surname + ", " + name + '.' << std::endl;
    return 0;
}
