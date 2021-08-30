#include <iostream>

int degreesFahrenheit(int);

int main() {
    short Celsius;
    std::cout << "введите значение в градусах по цельсию: ";
    std::cin >> Celsius;
    std::cout << Celsius << " градусов по Цельсию это " << degreesFahrenheit(Celsius) << " градус(а, ов) по Фаренгейту." << std::endl;
    return 0;
}

int degreesFahrenheit(int Celsius) {
    return 1.8 * Celsius + 32;
}
