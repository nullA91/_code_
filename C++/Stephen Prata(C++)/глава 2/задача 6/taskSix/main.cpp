#include <iostream>

double astronomicalUnitsDistance(double);

int main() {
    double lightYear;
    std::cout << "введите значение расстояния в световых годах: ";
    std::cin >> lightYear;
    std::cout << lightYear << " световых лет = " << astronomicalUnitsDistance(lightYear) <<" астрономических едениц." << std::endl;
    return 0;
}

double astronomicalUnitsDistance(double lightYear) {
    return lightYear * 63240;
}
