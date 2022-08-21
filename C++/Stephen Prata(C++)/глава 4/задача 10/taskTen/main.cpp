#include <array>
#include <iostream>

int main() {
    std::array<short, 3> array;
    std::cout << "введите первое время забега на 40м.: ";
    std::cin >> array[0];
    std::cout << "введите второе время забега на 40м.: ";
    std::cin >> array[1];
    std::cout << "введите третье время забега на 40м.: ";
    std::cin >> array[2];
    std::cout << "первое время забега: " << array[0] << " секунд." << '\n'
              << "второе время забега: " << array[1] << " секунд." << '\n'
              << "третье время забега: " << array[2] << " секунд." << '\n'
              << "среднее значение забега: "
              << (array[0] + array[1] + array[2]) / 3 << " секунд." << std::endl;
    return 0;
}
