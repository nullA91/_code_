#include <iostream>

int main() {
    std::string name;
    std::string surname;
    char grade;
    short age;
    std::cout << "введите ваше имя: ";
    getline(std::cin, name);
    std::cout << "введите вашу фамилию: ";
    std::cin >> surname;
    std::cout << "введите букву своего класса: ";
    std::cin >> grade;
    grade++;
    std::cout << "введите ваш возраст: ";
    std::cin >> age;
    std::cout << "Имя: " << surname << ", " << name << std::endl;
    std::cout << "класс: " << grade << std::endl;
    std::cout << "возраст: " << age << std::endl;
    return 0;
}
