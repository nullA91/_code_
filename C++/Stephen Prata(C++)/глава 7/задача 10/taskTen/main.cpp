#include <iostream>

double _addition(double _number_one, double _number_two);
double _subtraction(double _number_one, double _number_two);
double _multiple(double _number_one, double _number_two);
double _division(double _number_one, double _number_two);
double _calculate(double _number_one, double _number_two, double (*_pointer_func)(double, double));

int main() {
    char symbol;
    short choise;
    double _number_one, _number_two;
    double(*_pointer_func[4])(double, double) = {_addition, _subtraction, _multiple, _division};
    do {
        std::cout << "введите первое число: ";
        std::cin >> _number_one;
        std::cout << "введите второе число: ";
        std::cin >> _number_two;
        std::cout << "\t\'выберите пункт меню\'" << std::endl;
        std::cout << "1. сложение чисел\n"
                  << "2. вычитание чисел\n"
                  << "3. умножение чисел\n"
                  << "4. деление чисел" << std::endl;
        std::cin >> choise;
        if(choise > 0 && choise < 5)
            std::cout << "результат: " << _calculate(_number_one, _number_two, (*_pointer_func[choise - 1])) << std::endl;
        else
            std::cout << "в меню нет выбраного пункта, выберите другой пункт." << std::endl;
        std::cout << "повторить операцию (y/n)? ";
        std::cin >> symbol;
    } while(symbol != 'n' && symbol != 'N');
    return 0;
}

double _addition(double _number_one, double _number_two) {
    return _number_one + _number_two;
}
double _subtraction(double _number_one, double _number_two) {
    return _number_one - _number_two;
}
double _multiple(double _number_one, double _number_two) {
    return _number_one * _number_two;
}
double _division(double _number_one, double _number_two) {
    if(_number_two)
        return _number_one / _number_two;
    else {
        std::cout << "на ноль делить нельзя, введите другое число." << std::endl;
        return 0;
    }
}

double _calculate(double _number_one, double _number_two, double (*_pointer_func)(double, double)) {
    return (*_pointer_func)(_number_one, _number_two);
}
