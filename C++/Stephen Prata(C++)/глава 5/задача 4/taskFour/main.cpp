#include <iostream>

int main() {
    double _Dafna_balance = 100;
    double _Cleo_balance = 100;
    _Dafna_balance += 100 * 0.10;
    _Cleo_balance += _Cleo_balance * 0.05;
    short years = 1;
    while(_Cleo_balance < _Dafna_balance) {
        _Dafna_balance += 100 * 0.10;
        _Cleo_balance += _Cleo_balance * 0.05;
        std::cout << "баланс Дафны: " << _Dafna_balance << std::endl;
        std::cout << "баланс Клео: " << _Cleo_balance << std::endl;
        years++;
    }
    std::cout << "количество прошедших лет, когда баланс Клео превысил баланс Дафны: "
              << years << std::endl;
    return 0;
}
