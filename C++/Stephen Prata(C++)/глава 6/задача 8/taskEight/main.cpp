#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    char symbol;
    int count = 0;
    std::ifstream fin;
    fin.open("test.txt");
    if(!fin.is_open()) {
      std::cout << "ошибка открытия файла." << std::endl;
      exit(EXIT_FAILURE);
    }
    fin >> symbol;
    while(!fin.eof()) {
        ++count;
        fin >> symbol;
    }
    std::cout << "количество символов в файле: " << count << std::endl;
    fin.close();
    return 0;
}
