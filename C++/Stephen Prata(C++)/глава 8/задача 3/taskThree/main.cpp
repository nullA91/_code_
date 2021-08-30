/*
Напишите функцию, которая принимает ссылку на объект string в качестве
параметра и преобразует содержимое string в символы верхнего регистра.
Используйте функцию toupper (), описанную в табл. 6.4 (см. главу 6). Напишите
программу, использующую цикл, которая позволяет проверить работу функции
для разного ввода. Пример вывода может выглядеть следующим образом:
Enter a string (q to quit): go away
GO AWAY
Next string (q to quit): good grief!
GOOD GRIEF!
Next string (q to quit): q
Bye.
*/

#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

void _convert_small_letters_to_large(std::string& _string);

int main() {
    std::string _string;

    std::cout << "введите строку(введите q для выхода): ";
    while(true) {
        getline(std::cin, _string);
        if(_string != "q") {
            _convert_small_letters_to_large(_string);
            std::cout << _string << std::endl;
            std::cout << "введите следующую строку(введите q для выхода): ";
        }
        else {
            std::cout << "выход ..." << std::endl;
            break;
        }
    }

    return 0;
}

void _convert_small_letters_to_large(std::string& _string) {
    char* _new_string = new char[_string.length() + 1];
    strcpy(_new_string, _string.c_str());
    for(int i = 0; i < _string.length(); i++) {
        _new_string[i] = toupper(_new_string[i]);
        _string[i] = _new_string[i];
    }
    delete[] _new_string;
}
