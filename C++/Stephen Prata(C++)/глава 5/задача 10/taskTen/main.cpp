#include <iostream>

int main() {
    short amount;
    short count = 1;
    std::cout << "введите количество строк: ";
    std::cin >> amount;
    for(short i = 0; i < amount; i++) {
        for(short j = 0; j < amount - count; j++)
            std::cout << '.';
        for(short k = 0; k < count; k++)
            std::cout << '*';
        std::cout << std::endl;
        count++;
    }
    return 0;
}
