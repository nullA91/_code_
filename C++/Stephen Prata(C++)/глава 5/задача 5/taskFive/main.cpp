#include <array>
#include <iostream>

int main() {
    int sum = 0;
    short _monthly_sales;
    std::array<int, 12> _sales_amount;
    std::array<const char*, 12> months {
        "январь", "февраль", "март", "апрель", "май", "июнь",
        "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"
    };
    for(short i = 0; i < 12; i++) {
        std::cout << "введите количество проданных книг за " << months[i] << ": ";
        std::cin >> _monthly_sales;
        _sales_amount[i] = _monthly_sales;
        sum += _sales_amount[i];
    }
    std::cout << "общий объем продаж за год: " << sum << " книг(и)." << std::endl;
    return 0;
}
