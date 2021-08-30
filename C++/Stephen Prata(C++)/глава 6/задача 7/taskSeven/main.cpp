#include <cctype>
#include <iostream>
#include <string>

bool vowels_func(char);

int main() {
    short vowels = 0, consonants = 0, other_symbols = 0;
    std::string words;
    std::cout << "вводите слова (для выхода введите q): ";
    while(std::cin >> words && words != "q")
        isalpha(words[0]) ? vowels_func(words[0]) ? vowels++ : consonants++ : other_symbols++;
    std::cout << vowels << " слов(а, о) начинается с гласной." << std::endl;
    std::cout << consonants << " слов(а, о) начинается с согласной." << std::endl;
    std::cout << other_symbols << " слов(а, о) начинается с других символов." << std::endl;
    return 0;
}

bool vowels_func(char symbol) {
    bool flag = false;
    char vowels[] = "AaEeIiOoUuYy";
    for(short i = 0; i < 12; i++) {
        if(vowels[i] == symbol) {
            flag = true;
            break;
        }
    }
    return flag;
}

/*
if(isalpha(words[0])) {
    if(vowels_func(words[0]))
        vowels++;
    else
        consonants++;
}
else
    others++;
*/
