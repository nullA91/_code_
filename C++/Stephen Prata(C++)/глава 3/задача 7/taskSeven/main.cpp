#include <iostream>

int main() {
    const double hundredKilometers = 62.14;
    const double oneGallon = 3.785;
    double fuelConsumption, milesGallon;
    std::cout << "введите расход топлива на 100 км в литрах: ";
    std::cin >> fuelConsumption;
    milesGallon = (hundredKilometers / fuelConsumption) * oneGallon;
    std::cout << "миль на галлон: " << milesGallon << std::endl;
    return 0;
}
