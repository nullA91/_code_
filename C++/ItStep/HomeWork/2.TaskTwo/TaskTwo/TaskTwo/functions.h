#pragma once

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

const std::string _converting_double_to_string(const double& number);

void _reading_exercise_file(std::fstream& _file_data, const std::string path, const int _menu_item);
void _writing_data_file(std::fstream& _file_data, const std::string path, const std::string _string_data, const int _menu_item);
