#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void _reading_exercise_file(std::fstream& _file_data, const std::string path, const int _menu_item);
void _reading_data_file(std::fstream& _file_data, const std::string path);
void _writing_data_file(std::fstream& _file_data, const std::string path, const std::string _string_data, const int _menu_item);
