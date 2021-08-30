#include <iostream>

void outputOne();
void outputTwo();

int main() {
    outputOne();
    outputOne();
    outputTwo();
    outputTwo();
    return 0;
}

void outputOne() {
    std::cout << "Three blind mice." << std::endl;
}
void outputTwo() {
    std::cout << "See how they run." << std::endl;
}
