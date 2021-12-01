#include <iostream>

#include "Functions.h"

int main(int arg_c, char* arg_v[])
{
	FILE* file = NULL;

	int mode = 0;
	int choise = 0;

	do
	{
		menu();
		std::cout << "select menu item: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			if (mode == NULL)
			{
				mode = file_open(file);

				if (mode)
				{
					std::cout << "successful file opening" << std::endl;
				}
				else
				{
					std::cout << "file open error" << std::endl;
				}
			}
			else
			{
				std::cout << "the file is already open, close the file" << std::endl;
			}
			break;

		case 2:
			if (file == NULL || mode < 2)
			{
				std::cout << "the file is not open for writing, open the file for writing" << std::endl;
			}
			else
			{
				file_writing(file);
			}
			break;

		case 3:
			if (file == NULL || mode == 2 || mode == 3)
			{
				std::cout << "the file is not open for reading, open the file for reading" << std::endl;
			}
			else
			{
				while (!feof(file))
				{
					std::cout << file_reading(file);
				}
			}
			break;

		case 4:
		{
			/*
			Two roads diverged in a yellow wood,
			And sorry I could not travel both
			And be one traveler, long I stood
			And looked down one as far as I could
			To where it bent in the undergrowth.

			Then took the other, as just as fair,
			And having perhaps the better claim,
			Because it was grassy and wanted wear;
			Though as for that the passing there
			Had worn them really about the same.
			*/

			// not matching string

			FILE* file_one = nullptr;
			FILE* file_two = nullptr;

			const size_t length = 127;

			size_t length_one = 0;
			size_t length_two = 0;

			const char path_one[] = "C:\\_test_\\file one.txt";
			const char path_two[] = "C:\\_test_\\file two.txt";

			char string[length];
			char string_one[length];
			char string_two[length];

			fopen_s(&file_one, path_one, "w");

			fputs("Two roads diverged in a yellow wood,\n", file_one);
			fputs("And sorry I could not travel both\n", file_one);
			fputs("And be one traveler, long I stood\n", file_one);
			fputs("And looked down one as far as I could\n", file_one);
			fputs("To where it bent in the undergrowth.\n", file_one);

			fclose(file_one);
			///////////////////////////////////////////////////////////////////////////////
			fopen_s(&file_two, path_two, "w");

			fputs("Two roads diverged in a yellow wood,\n", file_two);
			fputs("And sorry I could not travel both\n", file_two);
			fputs("Not matching string III\n", file_two);
			fputs("And looked down one as far as I could\n", file_two);
			fputs("To where it bent in the undergrowth.\n", file_two);

			fclose(file_two);
			////////////////////////////////////////////////////////////////////////////////
			fopen_s(&file_one, path_one, "r");
			fopen_s(&file_two, path_two, "r");


			while (!feof(file_one))
			{
				fgets(string_one, length, file_one);
				string_one[strlen(string_one)] = '\0';

				fgets(string_two, length, file_two);
				string_two[strlen(string_two)] = '\0';

				if (strcmp(string_one, string_two) != 0)
				{
					std::cout << string_one << std::endl;
				}
			}

			fclose(file_one);
			fclose(file_two);
			break;
		}
		case 5:
		{
			//const char path[] = "C:\\_code_\\test.txt";

			const size_t length = 1024;

			char path[length];
			/*
			long position = ftell(file);

			fseek(file, NULL, SEEK_SET);

			if (position > NULL)
			{
				// файл непустой.
				rewind(file);
			}
			else
			{
				std::cout << "file is empty, write data to file" << std::endl;
				break;
			}
			*/
			
			std::cout << "enter file path: ";
			std::cin.ignore();
			std::cin.getline(path, length - 1);

			if (mode != 0)
			{
				if (!file_close(file, mode))
				{
					file_close(file, mode);
				}
			}
			
			std::cout << "the number of characters in the file: " << characters(file, path) << std::endl;
			std::cout << "the number of lines in the file: " << lines(file, path) << std::endl;
			std::cout << "the number of vowels in the file: " << vowels(file, path) << std::endl;
			std::cout << "the number of consonants in the file: " << consonants(file, path) << std::endl;
			std::cout << "the number of digits in the file: " << digits(file, path) << std::endl;

			break;
		}
		case 6:
		{
			/*
			Eat some more of these soft
			rench rolls and some tea.
			*/

			const int key = 3;

			const size_t length = 1024;

			char symbol = '\0';

			char path[length];
			


			if (mode != 0)
			{
				if (!file_close(file, mode))
				{
					file_close(file, mode);
				}
			}

			std::cout << "enter file path: ";
			std::cin.ignore();
			std::cin.getline(path, length - 1);

			if (fopen_s(&file, path, "w"))
			{
				std::cout << "file open error" << std::endl;
			}
			else
			{
				fputs("Eat some more of these soft\n", file);
				fputs("rench rolls and some tea.\n", file);
				fclose(file);

				if (fopen_s(&file, path, "r"))
				{
					std::cout << "error opening file for reading" << std::endl;
				}
				else
				{
					std::cout << std::endl;

					while (!feof(file))
					{
						if (symbol != '\n' && symbol != ' ' && symbol != '.' && symbol != ',')
						{
							symbol = (fgetc(file) + key);
							std::cout << symbol;
						}
						else
						{
							symbol = fgetc(file);
							std::cout << symbol;
						}
					}
					std::cout << std::endl;
				}
			}

			break;
		}
		case 7:
			if (file == NULL)
			{
				std::cout << "the file is not open, open the file" << std::endl;
			}
			else
			{
				if (file_close(file, mode))
				{
					std::cout << "file closed successfully" << std::endl;
				}
				else
				{
					std::cout << "file closing error" << std::endl;
				}
			}
			break;
		default:
			std::cout << "select the correct menu item " << std::endl;
			break;
		}

		std::cout << "continue(1.yes/0.no): ";
		std::cin >> choise;
		system("cls");

		if (!choise)
		{
			if (mode != 0)
			{
				fclose(file);
				mode = 0;
			}
			std::cout << "goodbye" << std::endl;
		}
	} while (choise);

	system("pause");
	return 0;
}