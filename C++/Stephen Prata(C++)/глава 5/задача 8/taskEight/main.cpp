#include <cstring>
#include <iostream>

int main() {
    char words[256];
    short amount = 0;
    std::cout << "вводите слова(для завершения введите слово done): ";
    std::cin >> words;
    while (strcmp(words, "done")) {
        std::cin >> words;
        amount++;
    }
    std::cout << "введено " << amount << " слов." << std::endl;
    std::cin.get();
    return 0;
}
