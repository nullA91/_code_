#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <iomanip>
#include "functions.h"

const std::string _path_exercises = "C:\\Projects\\C++\\ItStep\\HomeWork\\2.TaskTwo\\recources\\exercises.txt";
const std::string _path_calculation_results = "C:\\Projects\\C++\\ItStep\\HomeWork\\2.TaskTwo\\recources\\calculation results.txt";

int main(int _arguments_counter, char* _arguments_value[])
{
	bool _empty_file = true;

	const double PI = 3.14;
	const int _amount_number = 10;

	char converter[256]{ 0 };

	int choise = 0;
	std::string string = "";
	std::string _string_data = "";

	std::fstream _file_exercises;
	std::fstream _file_calculation_results;

	_file_calculation_results.open(_path_calculation_results, std::ios_base::in);

	if (!_file_calculation_results.is_open())
	{
		std::cout << "file open error" << std::endl;
		exit(1);
	}

	while (!_file_calculation_results.eof())
	{
		getline(_file_calculation_results, string);
		if (!string.empty())
		{
			_empty_file = false;
		}
	}

	_file_calculation_results.close();

	if (_empty_file)
	{
		_file_calculation_results.open(_path_calculation_results, std::ios_base::app);

		if (!_file_calculation_results.is_open())
		{
			std::cout << "file open error" << std::endl;
			exit(1);
		}

		_file_calculation_results << "+-------------------------------------------------------------------------------+" << std::endl;
		_file_calculation_results << "|1. | calculating the area and perimeter of a rectangle.                        |" << std::endl;
		_file_calculation_results << "+-------------------------------------------------------------------------------+" << std::endl;
		_file_calculation_results << "|2. | calculating the area of a circle and the length of its circumference.     |" << std::endl;
		_file_calculation_results << "+-------------------------------------------------------------------------------+" << std::endl;
		_file_calculation_results << "|3. | currency converter.                                                       |" << std::endl;
		_file_calculation_results << "+-------------------------------------------------------------------------------+" << std::endl;
		_file_calculation_results << "|4. | calculating the number of seconds left until the new year.                |" << std::endl;
		_file_calculation_results << "+-------------------------------------------------------------------------------+" << std::endl;
		_file_calculation_results << "|5. | separate output of integer and fractional parts of a number.              |" << std::endl;
		_file_calculation_results << "+-------------------------------------------------------------------------------+" << std::endl;
		_file_calculation_results << "|6. | ########## end of file ##########                                         |" << std::endl;
		_file_calculation_results << "+-------------------------------------------------------------------------------+" << std::endl;
	
		_file_calculation_results.close();
	}

	do {
		system("cls");

		std::cout << "+-------------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                                     menu                                      |" << std::endl;
		std::cout << "+-------------------------------------------------------------------------------+" << std::endl;
		std::cout << "|1. | calculating the area and perimeter of a rectangle.                        |" << std::endl;
		std::cout << "|2. | calculating the area of a circle and the length of its circumference.     |" << std::endl;
		std::cout << "|3. | currency converter.                                                       |" << std::endl;
		std::cout << "|4. | calculating the number of seconds left until the new year.                |" << std::endl;
		std::cout << "|5. | separate output of integer and fractional parts of a number.              |" << std::endl;
		std::cout << "|6. | calculation output.                                                       |" << std::endl;
		std::cout << "|0. | exit.                                                                     |" << std::endl;
		std::cout << "+-------------------------------------------------------------------------------+" << std::endl;
		std::cout << "select operation: ";
		std::cin >> choise;

		switch (choise)
		{
			case 1:
			{
				double length = 0.0;
				double width = 0.0;

				double square = 0.0;
				double perimeter = 0.0;
				
				_reading_exercise_file(_file_exercises, _path_exercises, choise);

				std::cout << "enter the length of the rectangle: ";
				std::cin >> length;

				std::cout << "enter the width of the rectangle: ";
				std::cin >> width;

				perimeter = (length + width) * 2;
				square = length * width;
				////////////
				_string_data = "length is ";
				_string_data += _gcvt(length, _amount_number, converter);
			    _string_data += " cm.\twidth is ";
			    _string_data += _gcvt(width, _amount_number, converter);
				_string_data += " cm.\n";
				////////////
				_string_data += "the perimeter of the rectangle is ";
				_string_data += _gcvt(perimeter, _amount_number, converter);
				_string_data += " cm.\n";
				///////////
				_string_data += "the area of the rectangle is ";
				_string_data += _gcvt(square, _amount_number, converter);
				_string_data += " cm.\n";
				
				_writing_data_file(_file_calculation_results, _path_calculation_results, _string_data, choise);

				break;
			}
			case 2:
			{
				double diameter = 0.0;

				double area = 0.0;
				double circumference = 0.0;

				_reading_exercise_file(_file_exercises, _path_exercises, choise);

				std::cout << "enter the size of the diameter of the circle: ";
				std::cin >> diameter;

				area = (diameter * diameter) / 4 * PI;
				circumference = diameter * PI;
				/////////////
				_string_data = "diameter is: ";
				_string_data += _gcvt(diameter, _amount_number, converter);
				_string_data += " cm.\n";
				////////////
				_string_data += "the area of the circle is: ";
				_string_data += _gcvt(area, _amount_number, converter);
				_string_data += " cm.\n";
				///////////
				_string_data += "the circumference is: ";
				_string_data += _gcvt(circumference, _amount_number, converter);
				_string_data += " cm.\n";

				_writing_data_file(_file_calculation_results, _path_calculation_results, _string_data, choise);

				break;
			}
			case 3:
			{
				double sum = 0.0;
				double _sum_dollar = 0.0;
				double _sum_euro = 0.0;
				double _dollar_selling_rate = 0.0;
				double _euro_selling_rate = 0.0;

				_reading_exercise_file(_file_exercises, _path_exercises, choise);

				std::cout << "enter the amount in UAH: ";
				std::cin >> sum;
				std::cout << "enter dollar selling rate: ";
				std::cin >> _dollar_selling_rate;
				std::cout << "enter the euro selling rate: ";
				std::cin >> _euro_selling_rate;

				_sum_dollar = sum / _dollar_selling_rate;
				_sum_euro = sum / _euro_selling_rate;
				/////////////
				_string_data = "entered amount: ";
				_string_data += _gcvt(sum, _amount_number, converter);
				_string_data += " UAH.\n";
				////////////
				_string_data += "for ";
				_string_data += _gcvt(sum, _amount_number, converter);
				_string_data += " UAH you will get: ";
				_string_data += _gcvt(_sum_dollar, _amount_number, converter);
				_string_data += " $.\n";
				///////////
				_string_data += "for ";
				_string_data += _gcvt(sum, _amount_number, converter);
				_string_data += " UAH you will get: ";
				_string_data += _gcvt(_sum_euro, _amount_number, converter);
				_string_data += " euro.\n";

				_writing_data_file(_file_calculation_results, _path_calculation_results, _string_data, choise);
				
				break;
			}
			case 4:
			{
				const std::string months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

				int month = 0;
				int seconds = 0;

				_reading_exercise_file(_file_exercises, _path_exercises, choise);

				for (size_t i = 0, j = 4, k = 8; i < 4; ++i, ++j, ++k)
				{
					std::cout << std::setiosflags(std::ios::left) << i + 1 << ". " << std::setw(15) << months[i] << j + 1 << ". " << std::setw(15) << months[j] << k + 1 << ". " << std::setw(15) << months[k] << '\n';
				}

				std::cout << "select month: ";
				std::cin >> month;

				seconds = ((12 - month + 1) * 30) * 24 * 60 * 60;

				_itoa(seconds, converter, 10);
            	/////////////
				_string_data = "starting from ";
				_string_data += months[month - 1];
				_string_data += " ";
				_string_data += converter;
				_string_data += " seconds left until the new year\n";
				
				_writing_data_file(_file_calculation_results, _path_calculation_results, _string_data, choise);

				break;
			}
			case 5:
			{
				double number = 0.0;
				int _whole_part = 0;
				int _fractional_part = 0;

				_reading_exercise_file(_file_exercises, _path_exercises, choise);

				std::cout << "enter a real number: ";
				std::cin >> number;

				_whole_part = static_cast<int>(number);
				_fractional_part = (number - static_cast<int>(number)) * 100;

				_string_data = "entered number: ";
				_string_data += _gcvt(number, _amount_number, converter);;
				_string_data += "\n";
				_string_data += "the integer part of number: ";
				_itoa(_whole_part, converter, 10);
				_string_data += converter;
				_string_data += "\n";
				_string_data += "real part of number: ";
				_itoa(_fractional_part, converter, 10);
				_string_data += converter;
				_string_data += "\n";

				_writing_data_file(_file_calculation_results, _path_calculation_results, _string_data, choise);

				break;
			}
			case 6:
				system("cls");
				_reading_data_file(_file_calculation_results, _path_calculation_results);
				system("pause");
				break;
			case 0:
				std::cout << "goodbye" << std::endl;
				break;

			default:
				std::cout << "select the correct menu item" << std::endl;
				system("pause");
				break;
		}

	} while (choise);

	system("pause");

	return 0;
}