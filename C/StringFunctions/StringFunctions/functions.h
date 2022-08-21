#pragma once
int _length_string(char* _transmitted_string); // прототип функции определения длинны строки
int _length_string(const char* _transmitted_string); // прототип функции определения длинны константной строки
bool _string_matching(char* _current_string, char* _transmitted_string); // прототип функции проверки совпадения строк
char* _reverse_string(char* _transmitted_string); // прототип функции для переворота (инверсии) строки
bool _balance_brackets(char* _transmitted_string); // прототип функции проверки баланса парных скобок
int _occurence_substring(char* _current_string, char* _transmitted_string); // прототип функции поиска первого вхождения подстроки в строку, функция должна возвращать позицию первого вхождения подстроки
char* _insert_n_string(char* _current_string, char* _transmitted_string, int position); // прототип функции вставки строки во вторую строку с указанной позиции
char* _сut_string (char* _transmitted_string, int length, int position); // прототип функции извлечения k символов входной строки, начиная с позиции N