#include <iostream>

struct CandyBar {
    std::string name;
    double weight;
    short calories;
};

int main(){
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    std::cout << "название конфет: " << snack.name << std::endl;
    std::cout << "вес конфет: " << snack.weight << std::endl;
    std::cout << "количество калорий: " << snack.calories << std::endl;
    return 0;
}
