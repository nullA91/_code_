#include <iostream>

int main() {
    short _number_one, _number_two;
    short sum = 0;
    do {
        std::cout << "введите первое число: ";
        std::cin >> _number_one;
        std::cout << "введите второе число: ";
        std::cin >> _number_two;
    } while(_number_one > _number_two);
    for(short i = _number_one; i <= _number_two; i++)
        sum += i;
    std::cout << "сумма всех целых чисел от " << _number_one << " до " << _number_two
              << " равна " << sum << std::endl;
    return 0;
}
