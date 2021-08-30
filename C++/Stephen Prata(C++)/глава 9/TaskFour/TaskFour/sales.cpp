#include "sales.h"
#include <iostream>

using namespace SALES; 

void setSales(Sales& s, const double ar[], int n = 4) {
    s.average = 0;
    s.max = 0;
    s.min = 0;
    for(int i = 0; i < QUATERS; ++i)
        s.sales[i] = 0;
    // вычисление минимального значения
    for(int i = 0; i < n; ++i)
        if(s.min > ar[i])
            s.min = ar[i];
    s.sales[0] = s.min;
    // вычисление среднего арифметического
    for (int i = 0; i < n; ++i)
        s.average += ar[i];
    s.average /= n;
    s.sales[1] = s.average;
    // вычисление максимального значения
    for (int i = 0; i < n; ++i)
        if(s.max < ar[i])
            s.max = ar[i];
    s.sales[2] = s.max;
}

void SetSales(Sales& s) {
    s.average = 0;
    s.max = 0;
    s.min = 0;
    double sum = 0;
    for (int i = 0; i < QUATERS; ++i)
        sum += s.sales[i];
    // вычисление минимального значения
    for(int i = 0; i < QUATERS; ++i)
        if(s.min > s.sales[i])
            s.min = s.sales[i];
    // вычисление среднего арифметического
    for (int i = 0; i < QUATERS; ++i)
        s.average += s.sales[i];
    s.average /= QUATERS;
    // вычисление максимального значения
    for (int i = 0; i < QUATERS; ++i)
        if(s.max < s.sales[i])
            s.max = s.sales[i];
    s.sales[0] = sum;
    s.sales[1] = s.min;
    s.sales[2] = s.max;
    s.sales[3] = s.average;
}

void showSales(const Sales& s) {
    for(int i = 0; i < QUATERS; ++i)
        std::cout << "i QUATERS: " << s.sales[i] << std::endl;
    std::cout << "max: " << s.max << std::endl;
    std::cout << "min: " << s.min << std::endl;
    std::cout << "average: " << s.average << std::endl;
}
