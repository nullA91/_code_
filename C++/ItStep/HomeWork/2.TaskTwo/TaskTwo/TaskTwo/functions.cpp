#include "functions.h"

// exercise file reading function
void _reading_exercise_file(std::fstream& _file_data, const std::string path, const int _menu_item)
{
	std::string exercise = "";
	std::string string = "";

	bool flag = false;

	char symbol = '\0';

	// opening a file for reading
	_file_data.open(path, std::ios_base::in);

	if (!_file_data.is_open())
	{
		std::cout << "error opening file for reading" << std::endl;
		exit(1);
	}

	symbol = _menu_item + 48;
	exercise = "exercise ";
	exercise += symbol;
	// loop for outputting the condition of the problem
	
	while (!_file_data.eof())
	{
		getline(_file_data, string);

		if (string == exercise)
		{
			flag = true;
		}

		if (flag)
		{
			std::cout << string << std::endl;
			if (string.empty())
			{
				flag = false;
				break;
			}
		}
	}

	_file_data.close(); // closing the task file
}

// function for reading data from a file
void _reading_data_file(std::fstream& _file_data, const std::string path)
{
	std::string string = "";

	_file_data.open(path, std::ios_base::in);

	if (!_file_data.is_open())
	{
		std::cout << "error opening file for reading" << std::endl;
		exit(1);
	}

	while (!_file_data.eof())
	{
		getline(_file_data, string);

		std::cout << string << std::endl;
	}

	_file_data.close();
}

// function of writing data to a file
void _writing_data_file(std::fstream& _file_data, const std::string path, const std::string _string_data, const int _menu_item)
{
	std::vector<std::string> _array_data;

	std::string string = "";
	// opening a file for reading to get its data
	_file_data.open(path, std::ios_base::in);

	if (!_file_data.is_open())
	{
		std::cout << "error opening file for reading" << std::endl;
		exit(1);
	}
	// writing data from a file to a string array with the addition of a new data line
	while (!_file_data.eof())
	{
		getline(_file_data, string);

		if (string.size() > 2)
		{
			if (string[1] == static_cast<char>(_menu_item + 49))
			{
				_array_data.push_back(_string_data);
				_array_data.push_back("+-------------------------------------------------------------------------------+\n");
			}
		}
		
		_array_data.push_back(string);
		_array_data.push_back("\n");
	}

	_file_data.close();
	// opening a file to write data from a string array to it
	_file_data.open(path, std::ios_base::out | std::ios_base::trunc);

	if (!_file_data.is_open())
	{
		std::cout << "error opening file for writing" << std::endl;
		exit(1);
	}

	for (auto const& element : _array_data)
	{
		_file_data << element;
	}

	_file_data.close();

	_array_data.clear(); // clearing a string array
}