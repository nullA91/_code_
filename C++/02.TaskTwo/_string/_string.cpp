#include "_string.h"

// конструктор по умолчанию
_string::_string()
{
   size = length;
   string = new char[size]();
}
//конструктор с одним параметром
_string::_string(char* string)
{
    size = strlen(string) + 1;
    this->string = new char[size];

    for(size_t i = 0; i < size - 1; ++i)
    {
        this->string[i] = string[i];
    }

    this->string[size - 1] = '\0';
}
// ############################## //
_string::_string(const char* string)
{
    size = strlen(string) + 1;
    this->string = new char[size];

    for(size_t i = 0; i < size - 1; ++i)
    {
        this->string[i] = string[i];
    }

    this->string[size - 1] = '\0';
}
// конструктор копирования
_string::_string(const _string& object)
{
    if( (object.string != nullptr) && (object.size != 0) )
    {
        size = object.size + 1;
        string = new char[size];

        for(size_t i = 0; i < size - 1; ++i)
        {
            string[i] = object.string[i];
        }

        string[size - 1] = '\0';
    }
    else
    {
        std::cout << "copy error" << std::endl;
    }
}
// деструктор
_string::~_string()
{
    if(string != nullptr && size != 0)
        delete [] string;
}
// ввод строки
void _string::input()
{
    char string[1024];

    std::cout << "enter the string: ";
    //std::cin.ignore();
    std::cin.getline(string, 1023);

    size = strlen(string) + 1;
    strcpy_s(this->string, sizeof(char) * size, string);
    string[size - 1] = '\0';
}
// вывод строки
void _string::output()
{
   if(string != nullptr && size != 0)
        std::cout << this->string;
   else
        std::cout << "line output error" << std::endl;
}

