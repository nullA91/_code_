#include "GLOBAL.h"

void func()
{
	char x;

	std::cout << "cin>>:";
	std::cin >> x;

	std::cout << static_cast<int>(x) << std::endl;


}