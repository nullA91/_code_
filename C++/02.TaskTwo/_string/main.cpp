#include "_string.h"

int main(int arg_c, char* arg_v[])
{
    char str_test[] = "user entered string";
    const char str_new[] =  "new string";

    _string str_one;
    _string str_two("Hello World");
    _string str_three(str_test);
    _string str_four(str_two);
    _string str_five(str_new);

    str_one.output();
    std::cout << std::endl;
    str_two.output();
    std::cout << std::endl;
    str_three.output();
    std::cout << std::endl;
    str_four.output();
    std::cout << std::endl;
    str_one.input();
    str_one.output();
    std::cout << std::endl;
    str_five.output();
    std::cout << std::endl;

    system("pause");
    return 0;
}
