/*
Завершите программу, создав соответствующие функции и прототипы. Обратите
внимание, что в программе должны быть две функции show(), и каждая из
них использует аргументы по умолчанию. Где необходимо, используйте const.
Функция set() должна использовать операцию new для выделения достаточного
пространства памяти под хранение заданной строки. Используемые здесь
методы аналогичны методам, применяемым при проектировании и реализации
классов. (В зависимости от используемого компилятора, может понадобиться
изменить имена заголовочных файлов и удалить директиву using.)
*/

#include <cstring>
#include <iostream>
#include <string.h>

using namespace std;

struct stringy {
    char* _string;
    int length;
};

void set(stringy& _struct, char* _string);
void show(const stringy& _struct, size_t _number_of_pins = 1);
void show(const char* _string, size_t _number_of_pins = 1);

int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing); // первым аргументом является ссылка, выделяет пространство для хранения копии testing,
                         // использует элемент типа _string структуры beany как указатель на новый блок, копирует
                         // testing в новый блок и создает элемент length структуры beany
    show(beany); // выводит строковый член структуры один раз
    show(beany, 2); // выводит строковый член структуры два раза
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing); // выводит строку testing один раз
    show(testing, 3); // выводит строку testing три раза
    show("Done!");

    return 0;
}

void set(stringy& _struct, char* _string) {
    _struct._string = new char[strlen(_string) + 1];
    strcpy(_struct._string, _string);
    _struct.length = strlen(_string) - 1;
}
void show(const stringy& _struct, size_t _number_of_pins) {
    for(size_t i = 0; i < _number_of_pins; i++)
        std::cout << _struct._string << std::endl;
}
void show(const char* _string, size_t _number_of_pins) {
    for(size_t i = 0; i < _number_of_pins; i++)
        std::cout << _string << std::endl;
}
