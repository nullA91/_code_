#include <iostream>

int main() {
    long long populationsWorld, populationsUs;
    double percentageRatio;
    std::cout << "введите мировую численность населения: ";
    std::cin >> populationsWorld;
    std::cout << "введите численность населения США: ";
    std::cin >> populationsUs;
    percentageRatio = (double)populationsUs * 100 / populationsWorld;
    std::cout << "численность населения США это " << percentageRatio
              << "% от мировой численности населения." << std::endl;
    return 0;
}
