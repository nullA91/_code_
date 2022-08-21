#include <iostream>

int main() {
    short days, hours, minutes;
    long long seconds;
    std::cout << "введите значение времени в секундах: ";
    std::cin >> seconds;
    days = seconds / 60 / 60 / 24;
    hours = seconds / 60 / 60 - days * 24;
    minutes = ((seconds - hours * 60 * 60) - days * 24 * 60 * 60) / 60;
    std::cout << seconds << " секунд = " << days << " дней, " << hours << " часов, "
              << minutes << " минут, " << seconds - minutes * 60 - hours * 60 * 60 - days * 24 * 60 * 60 << " секунд." << std::endl;
    return 0;
}
