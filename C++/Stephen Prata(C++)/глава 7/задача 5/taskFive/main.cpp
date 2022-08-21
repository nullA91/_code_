#include <iostream>

long double _factorial(short number);

int main() {
    short number;
    std::cout << "введите число для вычисления его факториала: ";
    std::cin >> number;
    std::cout << "факториал введенного числа: " << _factorial(number) << std::endl;
    while(number) {
        std::cout << "введите число для вычисления его факториала (для выхода введите \'0\'): ";
        std::cin >> number;
        std::cout << "факториал введенного числа: " << _factorial(number) << std::endl;
    }
    return 0;
}

long double _factorial(short number) {
    if(number < 0)
        return 0;
    if(number == 0)
        return 1;
    else
        return number * _factorial(number - 1);
}
