#include <iostream>

const short SIZE = 10;

short _input(short* array, short size);
void _output(short* array, short size);
double _average(short* array, short size);

int main() {
    short _actual_size;
    short array[SIZE];
    _actual_size = _input(array, SIZE);
    _output(array, _actual_size);
    std::cout << "среднее значение всех результатов: "
              << _average(array, _actual_size)
              << std::endl;
    return 0;
}

short _input(short* array, short size) {
    short _input_size = 0;
    std::cout << "\t\"ввод результатов игры (для выхода введите \'q\')\"" << std::endl;
    for(short i = 0; i < size; i++) {
        std::cout << "введите" << ' ' << i + 1 << ' ' << "результат игры: ";
        if(std::cin >> *array++)
            ++_input_size;
        else {
            std::cin.get();
            break;
        }
    }
    return _input_size;
}

void _output(short* array, short size) {
    if(size) {
        std::cout << "резылтаты игры: ";
        for(short i = 0; i < size; i++)
            std::cout << *array++ << ' ';
        std::cout << std::endl;
    }
    else
        std::cout << "в списке отсутствуют результаты игр!" << std::endl;
}

double _average(short* array, short size) {
    double average = 0.0;
    if(size) {
        for(short i = 0; i < size; i++)
            average += *array++;
        average /= size;
    }
    return average;
}
