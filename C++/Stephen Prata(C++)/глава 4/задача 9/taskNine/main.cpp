#include <iostream>

struct CandyBar {
    std::string name;
    double weight;
    short calories;
};

int main() {
    CandyBar* snacks = new CandyBar[3]{{"Mocha Munch", 2.3, 350}, {"Roshen", 2.5, 450}, {"Raffaello", 2.7, 550}};
    std::cout << "название конфет: " << snacks[0].name << std::endl;
    std::cout << "вес конфет: " << snacks[0].weight << std::endl;
    std::cout << "количество калорий: " << snacks[0].calories << std::endl;
    std::cout << "название конфет: " << snacks[1].name << std::endl;
    std::cout << "вес конфет: " << snacks[1].weight << std::endl;
    std::cout << "количество калорий: " << snacks[1].calories << std::endl;
    std::cout << "название конфет: " << snacks[2].name << std::endl;
    std::cout << "вес конфет: " << snacks[2].weight << std::endl;
    std::cout << "количество калорий: " << snacks[2].calories << std::endl;
    delete [] snacks;
    return 0;
}
