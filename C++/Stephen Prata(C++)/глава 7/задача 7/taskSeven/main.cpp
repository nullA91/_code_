#include <iostream>

const size_t SIZE = 10;

int* _fill_array(int* begin, int* end);
void _show_array(int* begin, int* end);
void _revalue(int* begin, int* end, int value);

int main() {
    short value;
    int* _a_sz_ptr;
    int array[SIZE];
    _a_sz_ptr = _fill_array(array, array + SIZE);
    _show_array(array, _a_sz_ptr);
    std::cout << "введите значение для на которое будут перемножены элементы массива: ";
    std::cin >> value;
    _revalue(array, _a_sz_ptr, value);
    _show_array(array, _a_sz_ptr);
    return 0;
}

int* _fill_array(int* begin, int* end) {
    int* pointer;
    for(pointer = begin; pointer != end; pointer++) {
        std::cout << "введите значение массива:" << ' ' << "(для выхода введите \'q\'):" << ' ';
        if(!(std::cin >> *pointer)) {
            std::cin.clear();
            std::cin.get();
            break;
        }
    }
    return pointer;
}

void _show_array(int* begin, int* end) {
    std::cout << "массив: |";
    for(int* pointer = begin; pointer != end; pointer++)
        std::cout << *pointer << '|';
    std::cout << std::endl;
}

void _revalue(int* begin, int* end, int value) {
    for(int* pointer = begin; pointer != end; pointer++)
        *pointer *= value;
}
