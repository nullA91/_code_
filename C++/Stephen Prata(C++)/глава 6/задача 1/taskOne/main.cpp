#include <cctype>
#include <iostream>

int main() {
    char symbol;
    std::cout << "вводите текст(для завершения ввода введите символ \'@\'): ";
    while(std::cin.get(symbol) && symbol != '@') {
        if(isgraph(symbol) && !isdigit(symbol)) {
            if(islower(symbol))
                std::cout << static_cast<char>(toupper(symbol));
            else if(isupper(symbol))
                std::cout << static_cast<char>(tolower(symbol));
            else
                std::cout << symbol;
        }
        else if(isspace(symbol))
            std::cout << symbol;
    }
    return 0;
}
