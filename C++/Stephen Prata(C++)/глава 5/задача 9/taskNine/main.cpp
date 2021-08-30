#include <iostream>
#include <string>

int main() {
    std::string words;
    short amount = 0;
    std::cout << "вводите слова(для завершения введите слово done): ";
    std::cin >> words;
    while (words != "done") {
        std::cin >> words;
        amount++;
    }
    std::cout << "введено " << amount << " слов." << std::endl;
    std::cin.get();
    return 0;
}
