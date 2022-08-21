/*
Структура CandyBar содержит три члена. Первый член хранит название коробки
конфет. Второй — ее вес (который может иметь дробную часть), а третий —
количество калорий (целое значение). Напишите программу, использующую
функцию, которая принимает в качестве аргументов ссылку на CandyBar, указатель
на char, значение double и значение int. Функция использует три последних
значения для установки соответствующих членов структуры. Три последних
аргумента должны иметь значения по умолчанию: "Millennium Munch", 2.85 и 350.
Кроме того, программа должна использовать функцию, которая принимает в
качестве аргумента ссылку на CandyBar и отображает содержимое этой структуры.
Где необходимо, используйте const.
*/

#include <iostream>

struct CandyBar {
    const char* _candy_name;
    double weight;
    int calories;
};

void _candy_characteristics(
        CandyBar& _struct,
        const char* _candy_name = "Millenium Munch",
        double weight = 2.85,
        int calories = 350
);

void _candy_characteristics_output(const CandyBar& _struct);

int main() {
    CandyBar candy;

    _candy_characteristics(candy);
    _candy_characteristics_output(candy);
    _candy_characteristics(candy, "Roshen", 1.35, 270);
    _candy_characteristics_output(candy);

    return 0;
}


void _candy_characteristics(
        CandyBar& _struct,
        const char* _candy_name,
        double weight,
        int calories
) {
    _struct._candy_name = _candy_name;
    _struct.weight = weight;
    _struct.calories = calories;
}

void _candy_characteristics_output(const CandyBar& _struct) {
    std::cout << "\tхарактеристики конфеты:" << std::endl;
    std::cout << "название конфеты: " << _struct._candy_name << std::endl;
    std::cout << "вес конфеты: " << _struct.weight << std::endl;
    std::cout << "количество калорий в конфете: " << _struct.calories << std::endl;
}
