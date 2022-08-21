/*
Напишите шаблонную функцию max5(), которая принимает в качестве
аргумента массив из пяти элементов типа T и возвращает наибольший элемент в
массиве. (Поскольку размер массива фиксирован, его можно жестко закодировать в
цикле, а не передавать в виде аргумента.) Протестируйте функцию в
программе с использованием массива из пяти значений int и массива из пяти значений
double.
*/

#include <iostream>

template<typename T>
void max5(T* _array);

int main() {
    int _array[5] = {3, 7, 5, 8, 4};
    double array[5] = {3.3, 3.4, 3.8, 3.5, 3.7};

    max5(_array);
    max5(array);

    return 0;
}

template<typename T>
void max5(T* _array) {
    T max = 0;
    for(int i = 0; i < 5; i++)
        if(_array[i] > max)
            max = _array[i];
    std::cout << max << std::endl;
}
