#include <iostream>

typedef unsigned int _u_int;

long double probability(_u_int numbers, _u_int picks, _u_int _mega_number);

int main() {
    _u_int _mega_number;
    double range, numbers;
    std::cout << "введите диапазон значений, количество номеров для угадывания и меганомер: ";
    while((std::cin >> range >> numbers >> _mega_number) && numbers <= range) {
        std::cout << "вероятность выигрыша: " << probability(range, numbers, _mega_number) << std::endl;
        std::cout << "введите следующих три номера (или (q для выхода)): ";
    }
    std::cout << "до свидания." << std::endl;
    return 0;
}

long double probability(_u_int numbers, _u_int picks, _u_int _mega_number) {
    long double result = 1.0;
    long double number;
    unsigned int pick;
    for(number = numbers, pick = picks; pick > 0; number--, pick--)
        result = result * number / pick;
    return result * _mega_number;
}
