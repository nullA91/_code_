#include <array>
#include <iostream>

int main() {
    bool flag = false;
    int counter = 0, average = 0;
    std::array<double, 10> donations;
    for(int i = 0; i < 10; i++) {
        std::cout << "введите " << i + 1 << " значение: ";
        if (!(std::cin >> donations[i]))
            break;
        counter++;
        average += donations[i];
    }
    std::cout << "среднее значение полученных чисел: " << static_cast<double>(static_cast<double>(average)/static_cast<double>(counter)) << '.' << std::endl;
    for(int i = 0 ; i < counter; i++) {
        if(donations[i] > average/counter) {
            flag = true;
            break;
        }
    }
    int new_count = 0;
    if(flag) {
        std::cout << "числа превышающие средние значения в массиве: ";
        for(int i = 0; i < counter; i++) {
            if(donations[i] > average/counter) {
                std::cout << donations[i] << ' ';
                new_count++;
            }
        }
        std::cout << std::endl;
    }
    else
        std::cout << "в массиве отсутствуют числа превышающие средние значения." << std::endl;
    std::cout << "количество чисел в массиве превышающих среднее значение: " << new_count << '.' << std::endl;
    return 0;
}

/*
while(std::cin >> donations[i]) {
    i++;
    while(std::cin.get() != '\n')
        continue;
    std::cout << "пожалуйста введите значение в цифрах: ";
}

*/
