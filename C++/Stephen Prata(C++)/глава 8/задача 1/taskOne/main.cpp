/*
Напишите функцию, которая обычно принимает один аргумент — адрес строки
и выводит эту строку один раз. Однако если задан второй аргумент типа int,
не равный нулю, то эта функция выводит строку столько раз, сколько было
осуществлено вызовов этой функции к моменту ее данного вызова. (Обратите
внимание, что количество выводимых строк не равно значению второго аргумента,
оно равно числу вызовов функции к моменту последнего вызова.) Действительно,
это не слишком полезная функция, но она заставит применить некоторые из
методов, рассмотренных в данной главе. Напишите простую программу для
демонстрации этой функции.
*/

#include <iostream>
#include <string>

int _string_output(std::string* _string);
void _string_output(std::string* _string, int _second_argument);

int _number_of_lines = 0;

int main() {
    std::string phrase = "Hello World!";

    while(_number_of_lines < 14)
        _number_of_lines += _string_output(&phrase);
    _string_output(&phrase, 10);

    return 0;
}

int _string_output(std::string* _string) {
    std::cout << *_string << std::endl;
    return 1;
}

void _string_output(std::string* _string, int _second_argument) {
    if(_second_argument != 0)
        while(_number_of_lines < 0)
            _number_of_lines -= _string_output(_string);
}
