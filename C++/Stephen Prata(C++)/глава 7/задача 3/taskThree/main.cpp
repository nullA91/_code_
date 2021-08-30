#include <cstring>
#include <iostream>

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void _input(box& _struct);
void _output(box _struct);

int main() {
    box _box;
    _input(_box);
    _output(_box);
    return 0;
}

void _input(box& _struct) {
    std::cin.get();
    std::cout << "введите название производителя: ";
    std::cin.getline(_struct.maker, 39);
    std::cin.clear();
    std::cout << "введите вес: ";
    std::cin >> _struct.height;
    std::cout << "введите ширину: ";
    std::cin >> _struct.width;
    std::cout << "введите длину: ";
    std::cin >> _struct.length;
    _struct.volume = _struct.height * _struct.width * _struct.length;
}

void _output(box _struct) {
    std::cout << "\t\"члены структуры\"" << std::endl;
    std::cout << "производитель: " << _struct.maker << std::endl;
    std::cout << "вес: " << _struct.height << std::endl;
    std::cout << "ширина: " << _struct.width << std::endl;
    std::cout << "длина: " << _struct.length << std::endl;
    std::cout << "объем: " << _struct.volume << std::endl;
}
