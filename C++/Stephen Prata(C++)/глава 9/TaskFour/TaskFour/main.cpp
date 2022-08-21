//#include <iostream>
#include "sales.h"

int main() {
    double array[8] = {1, 13, 3, 24, 137, 8, 11, 33};
    SALES::Sales _test_struct;
    SALES::setSales(_test_struct, array, SALES::QUATERS);
    SALES::showSales(_test_struct);
    SALES::SetSales(_test_struct);
    SALES::showSales(_test_struct);
    return 0;
}
