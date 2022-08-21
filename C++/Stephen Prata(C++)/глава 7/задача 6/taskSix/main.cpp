#include <iostream>

const size_t SIZE = 10;

short Fill_array(double* array, size_t size);
void Show_array(double* array, size_t size);
void Reverse_array(double* array, size_t size);

int main() {
    short _actual_size;
    double array[SIZE];
    _actual_size = Fill_array(array, SIZE);
    Show_array(array, _actual_size);
    Reverse_array(array, _actual_size);
    Show_array(array, _actual_size);
    return 0;
}

short Fill_array(double* array, size_t size) {
    short _input_size = 0;
    for(size_t i = 0; i < size; i++) {
        std::cout << "введите" << ' ' << i + 1 << ' ' << "значение массива" << ' '
                  << "(для выхода введите \'q\'):" << ' ';
        if(std::cin >> *array++)
            ++_input_size;
        else {
            std::cin.get();
            break;
        }
    }
    return _input_size;
}

void Show_array(double* array, size_t size) {
    std::cout << "массив: |";
    for(size_t i = 0; i < size; i++)
        std::cout << *array++ << '|';
    std::cout << std::endl;
}

void Reverse_array(double* array, size_t size) {
    double temp;
    for(size_t i = 1, j = size - 2; i < size / 2; i++, j--) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
