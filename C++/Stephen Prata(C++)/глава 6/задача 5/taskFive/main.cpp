#include <iostream>

int main() {
    int money;
    std::cout << "введите сумму дохода: ";
    while (std::cin >> money && money >= 0) {
        std::cout << "начисленый налог от введенной суммы: ";
        if(money < 10000)
            std::cout << '0' << std::endl;
        else if(money >= 10000 && money < 20000)
            std::cout << 10000 * 0.10 << std::endl;
        else if(money >= 20000 && money < 35000)
            std::cout << 10000 * 0.10 + 20000 * 0.15 << std::endl;
        else
            std::cout << 10000 * 0.10 + 20000 * 0.15 + (money - 35000) * 0.20 << std::endl;
        std::cout << "введите сумму дохода: ";
    }
    return 0;
}
