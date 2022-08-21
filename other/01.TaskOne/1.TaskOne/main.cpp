#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main(int _arguments_counter, char* _arguments_value[])
{
	const std::string _path_task = "C:\\Projects\\C++\\ItStep\\HomeWork\\1.TaskOne\\files\\HomeWorkOne.txt";
	const std::string _path_personal_data = "C:\\Projects\\C++\\ItStep\\HomeWork\\1.TaskOne\\files\\personal data.txt";

	bool flag = false;

	int choise = 0;

	char symbol = '\0';

	std::string string = "";
	std::string exercise = "";

	std::string name = "";
	std::string country = "";
	std::string city = "";
	std::string work = "";
	std::string position = "";

	std::fstream _personal_data, task;

RETRY:
	system("cls");

	std::cout << "\tmenu\n";
	std::cout << "1. personal data entry\n";
	std::cout << "2. output poem\n";
	std::cout << "0. exit\n";
	std::cout << "select operation: ";
	std::cin >> choise;
	std::cout << std::endl;
	// #####TaskOne#####
	if (choise == 1)
	{
		system("cls");

		task.open(_path_task, std::ios_base::in);

		if (!task.is_open())
		{
			std::cout << "file open error" << std::endl;
			return 1;
		}

		symbol = 50;
		exercise = "Exercise ";
		exercise += symbol;

		while (!task.eof())
		{
				getline(task, string);

				if (string != exercise) 
				{
					std::cout << string << std::endl;
				}
				else
				{
					break;
				}
		}

		task.close();

		_personal_data.open(_path_personal_data, std::ios_base::trunc | std::ios_base::out);

		if (!_personal_data.is_open())
		{
			std::cout << "file open error" << std::endl;
			return 1;
		}

		std::cin.ignore(32767, '\n');
		std::cout << "enter your name: ";
		getline(std::cin, name);
		std::cout << "what country do you live in: ";
		getline(std::cin, country);
		std::cout << "what town are you from: ";
		getline(std::cin, city);
		std::cout << "where do you work: ";
		getline(std::cin, work);
		std::cout << "what position do you occupy: ";
		getline(std::cin, position);

		_personal_data << "My name is " << name << ". " << "I am from " << country << ".\n"
					   << "I live in " << city << ". " << "I work at " << work << " as a\n"
			           << position << ".\n";

		_personal_data.close();

		_personal_data.open(_path_personal_data, std::ios_base::in);

		std::cout << std::endl;
		while (!_personal_data.eof())
		{
			getline(_personal_data, string);
			std::cout << string << std::endl;
		}

		_personal_data.close();
	}
	// #####TaskTwo#####
	else if (choise == 2)
	{
		system("cls");

		task.open(_path_task, std::ios_base::in);

		if (!task.is_open())
		{
			std::cout << "file open error" << std::endl;
			return 1;
		}

		symbol = 50;
		exercise = "Exercise ";
		exercise += symbol;

		while (!task.eof())
		{
			getline(task, string);

			if (string == exercise)
				flag = true;

			if(flag)
				std::cout << string << std::endl;
		}

		std::cout << std::endl;
		task.close();

		std::cout << "Jeus, Estrella, Esperanza, Mercy:\n\n"
			      << "\tSails flashing to the wind like weapons,\n"
			      << "\tsharks following the moans the fever and the dying;\n"
			      << "\thorror the corposant and compass rose.\n\n";

		std::cout << "Middle Passage:\n"
			      << "\tvoyage through death\n"
			      << "\t\tto life upon these shores.\n";

		std::cout << std::endl;
	}
	else if (choise == 0)
	{
		system("pause");
		exit(0);
	}
	else
	{
		std::cout << "choose the correct operation number" << std::endl;
		goto RETRY;
	}

	std::cout << "continue(1.yes/0.no): ";
	std::cin >> choise;

	if (choise) goto RETRY;

	system("pause");

	return 0;
}
