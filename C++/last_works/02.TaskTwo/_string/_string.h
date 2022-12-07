#ifndef _STRING_H
#define _STRING_H

#include "libraries.h"

#define length 80

class _string
{
private:
    unsigned int size;
    char* string;
public:
    // конструкторы
    _string();
    _string(char*);
    _string(const char*);
    _string(const _string& object);
    // деструктор
    ~_string();
    // методы
    void input();
    void output();
};

#endif // _STRING_H
