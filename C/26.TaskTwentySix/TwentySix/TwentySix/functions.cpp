#include "functions.h"

void create_menu(const char* string)
{
	#include <cstring>

	const size_t two = 2;
	const size_t length = 100;

	static unsigned int counter = 1;

	if (!strcmp(string, "menu"))
	{
		// верх пункта меню
		std::cout << static_cast<char>(201);
		for(size_t i = 0; i < length; ++i)
		{
			std::cout << static_cast<char>(205);
		}
		std::cout << static_cast<char>(187) << "\n\n";
		// середина пункта меню
		std::cout << static_cast<char>(186);
		for (size_t i = 0; i < length / two; ++i)
		{
			std::cout << ' ';
		}
		std::cout << string;
		for (size_t i = 0; i < length / two - two * two; ++i)
		{
			std::cout << ' ';
		}
		std::cout << static_cast<char>(186) << "\n\n";
		// низ пункта меню
		std::cout << static_cast<char>(200);
		for (size_t i = 0; i < length; ++i)
		{
			std::cout << static_cast<char>(205);
		}
		std::cout << static_cast<char>(188) << '\n';
	}
	else
	{
		// верх пункта меню
		std::cout << static_cast<char>(201);
		for (size_t i = 0; i < length; ++i)
		{
			std::cout << static_cast<char>(205);
		}
		std::cout << static_cast<char>(187) << "\n\n";
		// середина пункта меню
		std::cout << static_cast<char>(186) << counter << '.' << string;
		for (size_t i = 0; i < (length - strlen(string) - two); ++i)
		{
			std::cout << ' ';
		}
		std::cout << static_cast<char>(186) << "\n\n";
		// низ пункта меню
		std::cout << static_cast<char>(200);
		for (size_t i = 0; i < length; ++i)
		{
			std::cout << static_cast<char>(205);
		}
		std::cout << static_cast<char>(188) << '\n';

		if (counter < 7)
			++counter;
		else
			counter = 1;
	}
}
