#include <array>
#include <iostream>

int main() {
    int sum;
    short _monthly_sales;
    int _sales_amount[3][12];
    std::array<const char*, 12> months {
        "январь", "февраль", "март", "апрель", "май", "июнь",
        "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"
    };
    for(short i = 0; i < 3; i++) {
        sum = 0;
        for(short j = 0; j < 12; j++) {
            std::cout << "введите количество проданных книг за " << i + 1
                      << " год в месяц "<< months[j] << ": ";
            std::cin >> _monthly_sales;
            _sales_amount[i][j] = _monthly_sales;
            sum += _sales_amount[i][j];
        }
        std::cout << "\nобщий объем продаж за " << i + 1 << " год: " << sum << " книг(и).\n" << std::endl;
    }
    return 0;
}
