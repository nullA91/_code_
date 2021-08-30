#include <iostream>

void strcount(std::string string);

int main() {
    std::string string = "";
    std::cout << "Enter a line:" << std::endl;
    std::cin >> string;
    while(std::cin) {
        if(string != "") {
            strcount(string);
            std::cout << "Enter next line (empty line to quit):" << std::endl;
            std::cin.ignore();
            getline(std::cin, string);
        }
        else
            break;
    }
    std::cout << "Bye" << std::endl;
    return 0;
}

void strcount(std::string string) {
    static int total = 0;
    int i = 0;
    int count = 0;
    std::cout << "\"" << string << "\" contains ";
    while(string[i]) {
        count++;
        i++;
    }
    total += count;
    std::cout << count << " characters\n";
    std::cout << total << " characters total\n";
}
