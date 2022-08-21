#include "Functions.h"
// #################################### //
int file_open(FILE*& file, const char* path)
{
	file = nullptr;

	const size_t rows = 6;
	const size_t columns = 3;

	int choise = 0;

	const char mods[rows][columns] = { "r","w","a","r+","w+","a+" };

	system("cls");
	printf_s("%s", "\t\t\t\t\tfile open mode\n");
	while (choise < 1 || choise > 6)
	{
		choise = opening_mode();
		system("cls");
	}

	fopen_s(&file, path, mods[choise - 1]);

	if (file == nullptr)
	{
		return 0;
	}
	else
	{
		return choise;
	}
}

void file_writing(FILE*& file, const char* string)
{
	fputs(string, file);
	fputc('\n', file);
}

char* file_reading(FILE*& file)
{
	const size_t length = 256;

	char* string = nullptr;

	string = (char*)calloc(length, sizeof(char));
	
	fgets(string, length - 1, file);
	string[strlen(string)] = '\0';

	return string;
}

bool file_close(FILE*& file, int& mode)
{
	bool close = 0;

	if (fclose(file) == EOF)
	{
		close = 0;
	}
	else
	{
		mode = 0;
		close = 1;
	}

	return close;
}
// #################################### //
int opening_mode()
{
	const size_t size = 100;
	const size_t rows = 6;
	const size_t columns = 256;

	int choise = 0;

	char mods[rows][columns];

	strcpy_s(mods[0], "1. open a file for reading (the file must exist)");
	strcpy_s(mods[1], "2. open an empty file for writing (if the file exists, then its contents are lost)");
	strcpy_s(mods[2], "3. open the file for writing to the end for adding(file is created if it doesn't exist)");
	strcpy_s(mods[3], "4. open a file for reading and writing (the file must exist)");
	strcpy_s(mods[4], "5. open an empty file for reading and writing (if the file exists, then its contents are lost)");
	strcpy_s(mods[5], "6. open the file for reading and addition (if the file does not exist, then it is created)");

	for (size_t i = 0; i < rows; ++i)
	{
		printf_s("%c", 201);
		for (size_t j = 0; j < size; ++j)
			printf_s("%c", 205);
		printf_s("%c\n", 187);

		printf_s("%c", 186);
		printf_s("%s", mods[i]);
		for (size_t j = strlen(mods[i]); j < size; ++j)
			printf_s("%c", ' ');
		printf_s("%c\n", 186);

		printf_s("%c", 200);
		for (size_t j = 0; j < size; ++j)
			printf_s("%c", 205);
		printf_s("%c\n", 188);
	}

	printf_s("select menu item: ");
	scanf_s("%d", &choise);

	return choise;
}

void menu()
{
	const size_t size = 50;
	const size_t rows = 7;
	const size_t columns = 50;

	const char menu_items[rows][columns]
	{
		"1. open file",
		"2. writing data to a file",
		"3. reading data from a file",
		"4. comparing strings in files",
		"5. data counting ",
		"6. encrypting a file using the caesar cipher",
		"7. close file"
	};

	//system("cls");

	for (size_t i = 0; i < rows; ++i)
	{
		printf_s("%c", 201);
		for (size_t j = 0; j < size; ++j)
			printf_s("%c", 205);
		printf_s("%c\n", 187);

		printf_s("%c", 186);
		printf_s("%s", menu_items[i]);
		for (size_t j = strlen(menu_items[i]); j < size; ++j)
			printf_s("%c", ' ');
		printf_s("%c\n", 186);

		printf_s("%c", 200);
		for (size_t j = 0; j < size; ++j)
			printf_s("%c", 205);
		printf_s("%c\n", 188);
	}
}
// #################################### //
int characters(FILE*& file, const char* path)
{
	char symbol = '\0';
	int counter = 0;

	if (!fopen_s(&file, path, "r"))
	{
		while (!feof(file))
		{
			symbol = fgetc(file);

			if (escape_sequences(symbol))
			{
				continue;
			}
			else if (symbol == ' ')
			{
				continue;
			}
			else
			{
				++counter;
			}
		}
		--counter;
		rewind(file);
		fclose(file);
	}
	else
	{
		printf_s("%s", "file read error\n");
		return 0;
	}

	return counter;
}

int lines(FILE*& file, const char* path)
{
	char symbol = '\n';
	int counter = 0;

	if (!fopen_s(&file, path, "r"))
	{
		while (!feof(file))
		{
			symbol = fgetc(file);

			if (symbol == '.' || symbol == '?' || symbol == '!' || symbol == '\n')
			{
				++counter;
			}
		}
		rewind(file);
		fclose(file);
	}
	else
	{
		printf_s("%s", "file read error\n");
		return 0;
	}

	return counter;
}

int vowels(FILE*& file, const char* path)
{
	char symbol = '\0';
	int counter = 0;

	if (!fopen_s(&file, path, "r"))
	{
		while (!feof(file))
		{
			symbol = fgetc(file);

			if (letters(symbol) == 1)
			{
				++counter;
			}
		}
		rewind(file);
		fclose(file);
	}
	else
	{
		printf_s("%s", "file read error\n");
		return 0;
	}

	return counter;
}

int consonants(FILE*& file, const char* path)
{
	char symbol = '\0';
	int counter = 0;

	if (!fopen_s(&file, path, "r"))
	{
		while (!feof(file))
		{
			symbol = fgetc(file);

			if (letters(symbol) == -1)
			{
				++counter;
			}
		}
		rewind(file);
		fclose(file);
	}
	else
	{
		printf_s("%s", "file read error\n");
		return 0;
	}

	return counter;
}

int digits(FILE*& file, const char* path)
{
	char symbol = '\0';
	int counter = 0;

	if (!fopen_s(&file, path, "r"))
	{
		while (!feof(file))
		{
			symbol = fgetc(file);

			if (symbol >= '0' && symbol <= '9')
			{
				++counter;
				symbol = fgetc(file);
				while (symbol >= '0' && symbol <= '9')
				{
					symbol = fgetc(file);
				}
			}
		}
		rewind(file);
		fclose(file);
	}
	else
	{
		printf_s("%s", "file read error\n");
		return 0;
	}

	return counter;
}
// #################################### //
int letters(const char& symbol)
{
	int check = 0;;

	if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'))
	{
		check = -1;

		if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u' || symbol == 'y')
		{
			check = 1;
		}
		else if (symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U' || symbol == 'Y')
		{
			check = 1;
		}
	}

	return check;
}
// #################################### //
bool escape_sequences(const char& symbol)
{
	bool check = false;

	check = (symbol == '\a') ? true : (symbol == '\b') ? true : (symbol == '\f') ? true : (symbol == '\n') ? true : (symbol == '\r') ? true : (symbol == '\t') ? true : false;
	//check = (symbol == '\a') ? false : (symbol == '\b') ? false : (symbol == '\f') ? false : (symbol == '\n') ? false : (symbol == '\r') ? false : (symbol == '\t') ? false : (symbol == '\\') ? false : (symbol == '\'') ? false : (symbol == '\"') ? false : (symbol == '\xdd') ? false : true;
	
	return check;
}