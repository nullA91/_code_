#include <iostream>
#include <string>

struct car {
    char _name_manufacturer[256];
    short _year_manufacture;
};

int main() {
    short amount;
    std::cout << "сколько автомобилей поместить в каталог: ";
    std::cin >> amount;
    car* cars;
    cars = new car[amount];
    for(short i = 0; i < amount; i++) {
        std::cout << "автомобиль №" << i + 1 << ": " << std::endl;
        std::cout << "введите производителя: ";
        std::cin.ignore();
        std::cin.getline(cars[i]._name_manufacturer, 255, '\n');
        std::cout << "укажите год выпуска: ";
        std::cin >> cars[i]._year_manufacture;
    }
    std::cout << "вот ваша коллекция: " << std::endl;
    for(short i = 0; i < amount; i++)
        std::cout << cars[i]._year_manufacture << ' ' << cars[i]._name_manufacturer << std::endl;
    delete [] cars;
    return 0;
}
