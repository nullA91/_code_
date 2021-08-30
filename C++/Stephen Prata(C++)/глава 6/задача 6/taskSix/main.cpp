#include <iostream>

struct patron {
    char name[256];
    double donation;
};

int main() {
    bool flag = false;
    short count;
    patron *patrons;
    std::cout << "введите количество миценатов: ";
    std::cin >> count;
    patrons = new patron[count];
    for(short i = 0; i < count; i++) {
        std::cout << "введите имя мецената: ";
        std::cin.ignore();
        std::cin.getline(patrons[i].name, 29, '\n');
        std::cout << "введите сумму пожертвования мецената: ";
        std::cin >> patrons[i].donation;
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
    delete[]patrons;
    return 0;
}
