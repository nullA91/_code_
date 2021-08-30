#include <iostream>

double _harmonic_mean(short _number_one, short _number_two);

int main() {
    double result;
    short _number_one, _number_two;
    std::cout << "\tвведите числа (для выхода введите \'0\')" << std::endl;
    std::cout << "введите первое число: ";
    std::cin >> _number_one;
    std::cout << "введите второе число: ";
    std::cin >> _number_two;
    while(_number_one && _number_two) {
        result = _harmonic_mean(_number_one, _number_two);
        std::cout << "среднее гармоническое введенных чисел: " << result << std::endl;
        std::cout << "\tвведите числа (для выхода введите \'0\')" << std::endl;
        std::cout << "введите первое число: ";
        std::cin >> _number_one;
        std::cout << "введите второе число: ";
        std::cin >> _number_two;
    }
    return 0;
}

double _harmonic_mean(short _number_one, short _number_two) {
    return 2.0 * _number_one * _number_two / (_number_one + _number_two);
}
