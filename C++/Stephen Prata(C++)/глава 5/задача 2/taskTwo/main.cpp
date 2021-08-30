#include <array>
#include <iostream>

int main() {
    const short _factorial_size = 101;
    std::array<long double, _factorial_size> factorials;
    factorials[1] = factorials[0] = 1;
    for(short i = 2; i < _factorial_size; i++)
        factorials[i] = i * factorials[i - 1];
    for(short i = 0; i < _factorial_size; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    return 0;
}
