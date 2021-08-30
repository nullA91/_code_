#include <iostream>
#include <cmath>

int main() {
    double growth;
    double weight;
    double BMI;
    std::cout << "введите рост в футах и дюймах: ";
    std::cin >> growth;
    growth *= 12 * 0.0254;
    std::cout << "введите вес в фунтах: ";
    std::cin >> weight;
    weight /= 2.2;
    BMI = weight / sqrt(growth);
    std::cout << "индекс массы тела = " << BMI << std::endl;
    return 0;
}
