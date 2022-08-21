#include <iostream>

int main() {
    short numbers;
    int sum = 0;
    do {
        std::cout << "введите число(для выхода из программы введите 0): ";
        std::cin >> numbers;
        sum += numbers;
        std::cout << "накопленная сумма введенных значений: " << sum << std::endl;
    } while(numbers != 0);
    return 0;
}
