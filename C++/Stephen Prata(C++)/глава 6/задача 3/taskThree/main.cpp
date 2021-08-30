#include <iostream>

int main() {
    char symbol = 'c';
    do {
        std::cout << "\tmenu" << std::endl;
        std::cout << "c) carnivore\tp) pianist)" << std::endl;
        std::cout << "t) tree\t\tg) game" << std::endl;
        std::cout << "пожалуйста введите букву c, g, p, или t: ";
        std::cin >> symbol;
        switch(symbol) {
            case 'c' :
                case 'C' :
                    std::cout << "a maple is a carnivore." << std::endl;
            break;
            case 'g' :
                case 'G' :
                    std::cout << "a maple is a game." << std::endl;
            break;
            case 'p' :
                case 'P' :
                    std::cout << "a maple is a pianist." << std::endl;
            break;
            case 't' :
                case 'T' :
                    std::cout << "a maple is a tree." << std::endl;
            break;
        }
    } while(symbol != 'C' && symbol != 'c' && symbol != 'G' && symbol != 'g' && symbol != 'P' && symbol != 'p' && symbol != 'T' && symbol != 't');
    return 0;
}
