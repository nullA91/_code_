#include <cstring>
#include <iostream>

int main() {
    char name[256];
    char surname[256];
    std::cout << "введите ваше имя: ";
    std::cin >> name;
    std::cout << "введите вашу фамилию: ";
    std::cin >> surname;
    std::cout << "введенная информация в одной строке: " << strcat(strcat(surname, ", "), name) << std::endl;
    return 0;
}
