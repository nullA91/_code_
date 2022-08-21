#include <iostream>

int main() {
    short growth;
    std::cout << "введите рост в дюймах: ___\b\b\b";
    std::cin >> growth;
    std::cout << "текущий рост: " << static_cast<int>(growth * 0.083) << " футов "
              << static_cast<double>(growth * 0.083) - static_cast<int>(growth * 0.083) << " дюймов."
              << std::endl;
    return 0;
}
