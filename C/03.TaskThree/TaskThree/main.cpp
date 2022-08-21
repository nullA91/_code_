#include <iomanip>
#include <iostream>

int main(int _arguments_counter, char* _arguments_value[])
{
	/*
	Задание 1. Создать приложение, которое выводит ин-
	формацию о книге, в следующем формате:
			Name : “The war and the peace”
			Avtor : L.N. Tolstoj
			Izdatelstvo: Piter
			Pages : 500.
	*/
	std::cout << std::setiosflags(std::ios::left) << std::setw(11) << "Name" << ": " << std::setw(23) << "\"The war and the peace\"" << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(11) << "Avtor" << ": " << std::setw(23) << "L.N. Tolstoj" << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(11) << "Izdatelstvo" << ": " << std::setw(23) << "Piter" << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(11) << "Pages" << ": " << std::setw(23) << "500." << std::endl;
	/*
	Задание 2. Создать приложение, которое выводит на консоль фразу:
					“U lukomor’a dub zelenij,
					Zlataya zep na dupe tom,
					I dnem i nochju kot uchenij
					vse hodit po cepi krugom”
	Сопроводить каждую новую строчку тройным звуковым сигналом.
	*/
	std::cout << "\n\"U lukomor\'a dub zelenij\n\a\a\a"
		<< "Zlataya zep na dupe tom,\n\a\a\a"
		<< "I dnem i nochju kot uchenij\n\a\a\a"
		<< "vse hodit po cepi krugom\"\n" << std::endl;
	/*
	Задание 3.	
	Создать приложение, которое выводит на экран следующую таблицу:
			╔════════════════════════════════════════════╗
			║                               Vremena goda ║
			╠═════════╦═══════════╦═══════════╦══════════╣
			║    Zima ║     Vesna ║      Leto ║     Osen ║    
			╚═════════╩═══════════╩═══════════╩══════════╝
	Подсказка:
	Рекомедуем выполнить следующий пример:
	cout<<"\n"<<(char)201<<(char)205<<(char)205<<(char)187;
	Необходимые символы находятся в дипазоне от 179 до 218.
	*/
	std::cout << static_cast<char>(201);
	for (size_t i = 0; i < 39; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(187) << std::endl;

	std::cout << '\n' << static_cast<char>(186) << std::setiosflags(std::ios::right) << std::setw(25) << "Vremena goda" << std::setiosflags(std::ios::right) << std::setw(15) << static_cast<char>(186) << std::endl;
	std::cout << '\n' << static_cast<char>(204);
	for (size_t i = 0; i < 39; ++i)
	{
		
		if(i == 10 || i == 20 || i == 30)
			std::cout << static_cast<char>(203);
		else
			std::cout << static_cast<char>(205);
	}
	std::cout << static_cast<char>(185) << '\n' << std::endl;

	std::cout << static_cast<char>(186) << std::setiosflags(std::ios::left) << std::setw(7) << "Zima" << std::setiosflags(std::ios::right) << std::setw(4) << static_cast<char>(186);
	std::cout << std::setiosflags(std::ios::left) << std::setw(7) << "Vesna" << std::setiosflags(std::ios::right) << std::setw(3) << static_cast<char>(186);
	std::cout << std::setiosflags(std::ios::left) << std::setw(7) << "Leto" << std::setiosflags(std::ios::right) << std::setw(3) << static_cast<char>(186);
	std::cout << std::setiosflags(std::ios::left) << std::setw(7) << "Osen" << std::setiosflags(std::ios::right) << std::setw(2) << static_cast<char>(186) << std::endl;

	std::cout << '\n' << static_cast<char>(200);
	for (size_t i = 0; i < 39; ++i)
		std::cout << static_cast<char>(205);
	std::cout << static_cast<char>(188) << std::endl;

	system("pause");

	return 0;
}

// std::cout << '\n' << (char)201 << ' ' << (char)205 << ' ' << (char)205 << ' ' << (char)187 << std::endl;