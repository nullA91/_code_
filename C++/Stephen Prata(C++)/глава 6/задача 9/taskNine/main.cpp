#include <cstdlib>
#include <fstream>
#include <iostream>

struct patron {
    char name[256];
    double donation;
};

int main() {
    std::ifstream fin;
    fin.open("patrons.txt");
    if(!fin.is_open()) {
      std::cout << "ошибка открытия файла." << std::endl;
      exit(EXIT_FAILURE);
    }
    int index = 0;
    bool flag = false;
    short count;
    patron *patrons;
    fin >> count;
    patrons = new patron[count];
    while(!fin.eof()) {
        fin.ignore();
        fin.getline(patrons[index].name, 255);
        fin >> patrons[index].donation;
        index++;
    }
    std::cout << "\t\"Grand Patrons\"" << std::endl;
    for(short i = 0; i < count; i++) {
        if(patrons[i].donation >= 10000) {
            std::cout << patrons[i].name << std::endl;
            flag = true;
        }
    }
    if(!flag)
        std::cout << "none" << std::endl;
    flag = false;
    std::cout << "\t\"Patrons\"" << std::endl;
    for(short i = 0; i < count; i++) {
        if(patrons[i].donation < 10000) {
            std::cout << patrons[i].name << std::endl;
            flag = true;
        }
    }
    if(!flag)
        std::cout << "none" << std::endl;
    delete [] patrons;
    return 0;
}
