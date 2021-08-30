/* вариант 'A'
#include <iostream>

const size_t SIZE = 4;

void _fill(double* array, size_t size);
void _show(double* array, size_t size);

const char seasons[SIZE][255] {"Весна", "Лето", "Осень", "Зима"};

int main() {
    double expenses[SIZE];
    _fill(expenses, SIZE);
    _show(expenses, SIZE);
    return 0;
}

void _fill(double* array, size_t size) {
    std::cout << "\t\"ввод стоимости расходов\"" << std::endl;
    for(size_t i = 0; i < size; i++) {
        std::cout << seasons[i] << ": ";
        std::cin >> array[i];
    }
}

void _show(double* array, size_t size) {
    std::cout << "\t\"стоимость расходов\"" << std::endl;
    for(size_t i = 0; i < size; i++)
        std::cout << seasons[i] << ": " << array[i] << std::endl;
}
*/

/* вариант 'B'
#include <iostream>

const size_t SIZE = 4;

struct expenses {
  double _expenses[SIZE];
};

void _fill(expenses& _struct, size_t size);
void _show(expenses _struct, size_t size);

const char seasons[SIZE][255] {"Весна", "Лето", "Осень", "Зима"};

int main() {
    expenses _expenses;
    _fill(_expenses, SIZE);
    _show(_expenses, SIZE);
    return 0;
}

void _fill(expenses& _struct, size_t size) {
    std::cout << "\t\"ввод стоимости расходов\"" << std::endl;
    for(size_t i = 0; i < size; i++) {
        std::cout << seasons[i] << ": ";
        std::cin >> _struct._expenses[i];
    }
}

void _show(expenses _struct, size_t size) {
    std::cout << "\t\"стоимость расходов\"" << std::endl;
    for(size_t i = 0; i < size; i++)
        std::cout << seasons[i] << ": " << _struct._expenses[i] << std::endl;
}
*/
