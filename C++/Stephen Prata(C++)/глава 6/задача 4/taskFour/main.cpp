#include <iostream>

void show_menu();

struct bop {
  char full_name[30];
  char title[30];
  char bop_name[30];
  int preference;
};

int main() {
    char symbol;
    bop members[3];
    for(int i = 0; i < 3; i++) {
        std::cout << "\t\"данные " << i + 1 << " члена БОП\"" << std::endl;
        std::cout << "введите имя члена БОП: ";
        std::cin.getline(members[i].full_name, 29);
        std::cout << "введите должность члена БОП: ";
        std::cin.getline(members[i].title, 29);
        std::cout << "введите _БОП_ИМЯ члена БОП: ";
        std::cin.getline(members[i].bop_name, 29);
    }
    do {
        show_menu();
        std::cout << "сделайте выбор: ";
        std::cin >> symbol;
        switch(symbol) {
            case 'a':case 'A':
                for(int i = 0; i < 3; i++)
                    std::cout << members[i].full_name << std::endl;
                break;
            case 'b':case 'B':
                for(int i = 0; i < 3; i++)
                    std::cout << members[i].title << std::endl;
                break;
            case 'c':case 'C':
                for(int i = 0; i < 3; i++)
                    std::cout << members[i].bop_name << std::endl;
                break;
            case 'd':case 'D':
                std::cin >> members[0].preference;
                members[2].preference = members[1].preference = members[0].preference;
                for(int i = 0; i < 3; i++) {
                    if(members[0].preference == 0)
                        std::cout << members[i].full_name << std::endl;
                    else if(members[0].preference == 1)
                        std::cout << members[i].title << std::endl;
                    else if(members[0].preference == 2)
                        std::cout << members[i].bop_name << std::endl;
                    else
                        std::cout << "в меню нет пункта под введенным номером." << std::endl;
                }
                break;
             case 'q':case 'Q':
                std::cout << "выход." << std::endl;
                break;
            default:
                std::cout << "в меню нет выбраного пункта." << std::endl;
        }
    } while (symbol != 'q' && symbol != 'Q');
    return 0;
}

void show_menu() {
    std::cout << "\t\'menu\'" << std::endl;
    std::cout << "a. отобразить по имени         b. отобразить по должности" << std::endl;
    std::cout << "c. отобразить по _БОП_ИМЕНИ    d. отобразить по свойству" << std::endl;
    std::cout << "q. выход" << std::endl;
}
