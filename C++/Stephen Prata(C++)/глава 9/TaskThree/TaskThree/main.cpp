#include <cstring>
#include <iostream>
#include <new>

struct chaff {
    char dross[20];
    int slag;
};

void _input_chaff(chaff& _struct);
void _output_chaff(const chaff& _struct);

char buffer[256];

int main() {
    chaff* _pointer_struct_one, * _pointer_struct_two;
    _pointer_struct_one = new (buffer) chaff[2];
    _pointer_struct_two = new chaff[2];
    for(std::size_t i = 0; i < 2; ++i) {
        _input_chaff(_pointer_struct_one[i]);
        _input_chaff(_pointer_struct_two[i]);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(std::size_t i = 0; i < 2; ++i) {
        std::cout << "struct one:" << std::endl;
        _output_chaff(_pointer_struct_one[i]);
        std::cout << "struct two:" << std::endl;
        _output_chaff(_pointer_struct_two[i]);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

void _input_chaff(chaff& _struct) {
    std::string string;
    std::cout << "input dross: ";
    std::cin.ignore();
    getline(std::cin, string);
    strcpy(_struct.dross, string.c_str());
    std::cout << "input slag: ";
    std::cin >> _struct.slag;
}

void _output_chaff(const chaff& _struct) {
    std::cout << "dross: " << _struct.dross << std::endl;
    std::cout << "slag: " << _struct.slag << std::endl;
}

/*
Напишите программу, которая использует операцию new с размещением, чтобы
поместить массив из двух таких структур в буфер. Затем программа присваивает
значения членам структуры (не забудьте воспользоваться функцией s t rcpy ( }
для массива c h a r ) и отображает ее содержимое с помощью цикла. Вариант 1Модели памяти и пространства имен
4 81
предусматривает применение в качестве буфера памяти статического массива,
как было показано в листинге 9 . 1 О. Вариант 2 состоит в использовании обычной
операции new для выделения памяти под буфер
*/
