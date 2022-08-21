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
			// open file
			case 1:
			{
				const size_t length = 1024;

				char path[length];

				std::cout << "enter file path: ";
				std::cin.ignore();
				std::cin.getline(path, length - 2);
				path[strlen(path)] = '\0';

				if (mode == NULL)
				{
				mode = file_open(file, path);

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
			}
			// writing data to an empty file
			case 2:
			{
				const size_t length = 1024;

				char string[length];
					
				bool exit = false;

				if (file == NULL || mode < 2)
				{
					std::cout << "the file is not open for writing, open the file for writing" << std::endl;
				}
				else
				{
					exit = true;

					while (exit)
					{
						system("cls");
						std::cout << "enter the string(enter zero to exit): ";
						std::cin.ignore();
						std::cin.getline(string, length - 2);
						string[strlen(string)] = '\0';
	
						file_writing(file, string);

						std::cout << "enter 0 to exit: ";
						std::cin >> exit;
						if (exit == 0) break;
					}
				}
				break;
			}
			// reading data from a file
			case 3:
				if (file == NULL || mode == 2 || mode == 3)
				{
					std::cout << "the file is not open for reading, open the file for reading" << std::endl;
				}
				else
				{
					rewind(file);

					while (!feof(file))
					{
						std::cout << file_reading(file);
					}
				}
				break;
			// comparing strings in two files
			case 4:
			{
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
			// counting data in a file
			case 5:
			{
				const size_t length = 1024;

				char path[length];

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
			// file encryption (Caesar cipher used)
			case 6:
			{
				bool exit = false;

				const int key = 3;

				const size_t length = 1024;

				char symbol = '\0';

				char string[length];
				char path[length];

				FILE* file_source = nullptr;
				FILE* file_encrypted = nullptr;

				/*
				if (mode != 0)
				{
					if (!file_close(file, mode))
					{
						file_close(file, mode);
					}
				}
				*/

				std::cout << "enter path for source file: ";
				std::cin.ignore();
				std::cin.getline(path, length - 1);

				if (fopen_s(&file_source, path, "w"))
				{
					std::cout << "file open error" << std::endl;
				}
				else
				{
					exit = true;

					while (exit)
					{
						system("cls");
						std::cout << "enter the line you want to add to the file: ";
						std::cin.ignore();
						std::cin.getline(string, length - 2);
						string[strlen(string)] = '\0';
						fputs(string, file_source);
						fputc('\n', file_source);

						std::cout << "continue(1.yes/0.no): ";
						std::cin >> exit;
					}
					fclose(file_source);

					if (fopen_s(&file_source, path, "r"))
					{
						std::cout << "error opening file for reading" << std::endl;
						
					}
					else
					{
						std::cout << "enter the path for the encrypted file: ";
						std::cin.ignore();
						std::cin.getline(path, length - 1);

						if (fopen_s(&file_encrypted, path, "w"))
						{
							std::cout << "error opening file for writing" << std::endl;
						}
						else
						{
							while (!feof(file_source))
							{
								symbol = fgetc(file_source);

								if (symbol == '\n')
								{
									fputc(symbol, file_encrypted);
								}
								else
								{
									symbol += key;
									fputc(symbol, file_encrypted);
								}
							}

							fclose(file_source);
							fclose(file_encrypted);
						}

						/*
						std::cout << std::endl;

						while (!feof(file_source))
						{
							symbol = fgetc(file_source);

							if (symbol == '\n' || symbol == ' ' || symbol == '.' || symbol == ',')
							{	
								std::cout << symbol;	
							}
							else
							{
								symbol += key;
								std::cout << symbol;
							}
						}
						std::cout << std::endl;
						*/
					}
				}

				break;
			}
			// closing the file
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
			// incorrectly entered menu item
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