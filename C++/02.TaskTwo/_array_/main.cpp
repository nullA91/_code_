#include "array.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    _array_<double> array_one;
    _array_<char, 50> array_two;
    _array_<int> array_three(10);

    array_one.create();
    array_one.infill();
    array_one.show();

    array_two.infill();
    array_two.show();

    array_three.create();
    array_three.infill();
    array_three.show();

    std::cout << "EXIT" << std::endl;
    return 0;
}

/*
_array_<int> arrayINT;
_array_<float> arrayFLOAT;
_array_<double> arrayDOUBLE;
_array_<char> arrayCHAR;

arrayINT.create();
arrayINT.infill();
arrayINT.show();

arrayFLOAT.create();
arrayFLOAT.infill();
arrayFLOAT.show();

arrayDOUBLE.create();
arrayDOUBLE.infill();
arrayDOUBLE.show();

arrayCHAR.create();
arrayCHAR.infill();
arrayCHAR.show();


arrayINT.create();
arrayINT.infill();
arrayINT.show();
arrayINT.sorting();
arrayINT.show();

arrayFLOAT.create();
arrayFLOAT.infill();
arrayFLOAT.show();
arrayFLOAT.sorting();
arrayFLOAT.show();

arrayCHAR.create();
arrayCHAR.infill();
arrayCHAR.show();
arrayCHAR.sorting();
arrayCHAR.show();
*/


/*
std::cout << array_one.getSize() << std::endl;
std::cout << array_two.getSize() << std::endl;
std::cout << array_three.getSize() << std::endl;

std::string str;
str = std::to_string(1234567);
std::cout << str.length() << std::endl;
*/

/*
array_one.create();
array_one.infill();
array_one.show();

array_two.infill();
array_two.show();

array_three.create();
array_three.infill();
array_three.show();
*/
