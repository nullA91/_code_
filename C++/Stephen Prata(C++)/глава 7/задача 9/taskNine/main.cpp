#include <cstring>
#include <iomanip>
#include <iostream>

const size_t LENGTH = 30;

struct student {
    char _full_name[LENGTH];
    char hobby[LENGTH];
    int _oop_level;
};

short _get_info(student array[], size_t size);
void _display_one(student _struct);
void _display_two(const student* _struct);
void _display_three(const student array[], size_t size);

int main() {
    student* students;
    size_t size;
    short _actual_size = 0;
    std::cout << "введите количество студентов: ";
    std::cin >> size;
    students = new student[size];
    _actual_size = _get_info(students, size);
    for(size_t i = 0; i < _actual_size; i++) {
        _display_one(students[i]);
        _display_two(students + i);
    }
    std::cout << std::endl;
    _display_three(students, _actual_size);
    delete []students;
    return 0;
}

short _get_info(student array[], size_t size) {
    short _actual_size = 0;
    for(size_t i = 0; i < size; i++) {
        std::cin.ignore(30,'\n');
        std::cout << "введите фамилию и инициалы студента: ";
        std::cin.getline(array[i]._full_name, 29);
        std::cout << "введите специальность студента: ";
        std::cin.getline(array[i].hobby, 29);
        std::cout << "введите уровень успеваемости студента (от 1 до 10): ";
        std::cin >> array[i]._oop_level;
        _actual_size++;
    }
    return _actual_size;
}

void _display_one(student _struct) {
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "|        \'данные студента\'          |" << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "|фамилия: " << std::setw(26) << _struct._full_name << '|' << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "|специальность: " << std::setw(20) << _struct.hobby << '|' << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "|уровень ООП: " << std::setw(22) << _struct._oop_level << '|' << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
}

void _display_two(const student* _struct) {
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "|        \'данные студента\'          |" << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "|фамилия: " << std::setw(26) << _struct->_full_name << '|' << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "|специальность: " << std::setw(20) << _struct->hobby << '|' << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "|уровень ООП: " << std::setw(22) << _struct->_oop_level << '|' << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
}

void _display_three(const student array[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        std::cout << "+-----------------------------------+" << std::endl;
        std::cout << "|        \'данные студента\'          |" << std::endl;
        std::cout << "+-----------------------------------+" << std::endl;
        std::cout << "|фамилия: " << std::setw(26) << array[i]._full_name << '|' << std::endl;
        std::cout << "+-----------------------------------+" << std::endl;
        std::cout << "|специальность: " << std::setw(20) << array[i].hobby << '|' << std::endl;
        std::cout << "+-----------------------------------+" << std::endl;
        std::cout << "|уровень ООП: " << std::setw(22) << array[i]._oop_level << '|' << std::endl;
        std::cout << "+-----------------------------------+" << std::endl;

    }
}
