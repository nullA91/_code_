#include <iostream>

int main() {
    short furlongs;
    std::cout << "введите расстояние в фарлонгах: ";
    std::cin >> furlongs;
    std::cout << "введенное растояние в ярдах: " << furlongs * 220 << " ярд(а, ов)." << std::endl;
    std::cout << "введенное растояние в метрах: " << furlongs * 201168 << " метр(а, ов)." << std::endl;
    return 0;
}
