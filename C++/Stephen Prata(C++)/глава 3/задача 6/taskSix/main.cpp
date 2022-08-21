#include <iostream>

int main() {
    const double mile_meters = 1.609;
    const double gallon_liters = 3.785;
    double fuelConsumption, milesGallon;
    short distanceKilometers;
    short volumeGasoline;
    std::cout << "введите пройденное расстояние в км: ";
    std::cin >> distanceKilometers;
    std::cout << "введите количество израсходованого бензина: ";
    std::cin >> volumeGasoline;
    fuelConsumption = volumeGasoline * 100 / distanceKilometers;
    std::cout << fuelConsumption << " литр(а, ов) на 100 км." << std::endl;
    milesGallon = (distanceKilometers * gallon_liters) / (volumeGasoline * mile_meters);
    std::cout << "количество миль на галлон: " << milesGallon << std::endl;
    return 0;
}
