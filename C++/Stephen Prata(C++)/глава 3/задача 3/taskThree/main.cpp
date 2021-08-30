#include <iostream>

int main() {
    double degrees, minutes, seconds;
    std::cout << "введите широту в градусах, минутах и секундах:" << std::endl;
    std::cout << "вначале, введите градусы: ";
    std::cin >> degrees;
    std::cout << "затем, введите угловые минуты: ";
    std::cin >> minutes;
    std::cout << "и наконец, введите угловые секунды: ";
    std::cin >> seconds;
    std::cout << degrees << " градус(а, ов), " << minutes << " минут(а, ы), " << seconds << " секунд(а, ы) = "
              << degrees + ((seconds / 60 + minutes) / 60) << " градусам." << std::endl;
    return 0;
}
