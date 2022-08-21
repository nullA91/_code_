#include <iostream>

void timeDisplay(int, int);

int main() {
    short hours, minutes;
    std::cout << "введите значение времени в часах: ";
    std::cin >> hours;
    std::cout << "введите значение времени в минутах: ";
    std::cin >> minutes;
    timeDisplay(hours, minutes);
    return 0;
}

void timeDisplay(int hours, int minutes) {
    std::cout << "Время: " << hours << ':' << minutes << std::endl;
}
