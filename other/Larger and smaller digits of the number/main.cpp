#include <fstream>
#include <iostream>

int main(int _arguments_counter, char* _arguments_value[])
{
    
    std::fstream _test_file;
    std::string path = "/home/null/Downloads/cppstudio/easy/Larger and smaller digits of the number/_test_output.txt";
    unsigned int number;
    
    _test_file.open(path, std::ios::app);
    
    std::cout << "enter a number no more than nineghtynine: ";
    std::cin >> number;
    
    if(number > 9 && number < 99)
    {
        int _temp_number_one, _temp_number_two;
        
        _temp_number_one = number % 10;
        _temp_number_two = number / 10;
        
        if(_temp_number_one > _temp_number_two) {
            _test_file << _temp_number_one << " - large number\n" << _temp_number_two << " - smaller number\n";
            _test_file << "---------------------\n";
        }
        else if(_temp_number_one < _temp_number_two) {
            _test_file << _temp_number_two << " - large number\n" << _temp_number_one << " - smaller number\n";
            _test_file << "---------------------\n";
        }
        else
            _test_file << "the numbers are equal\n" << "---------------------\n"; 
    }
    else
        std::cout << "you entered an invalid number\n";
    
    _test_file.close();
    
    return 0;

}

//std::cout << _temp_number_one << '\t' << _temp_number_two << std::endl;
//(_temp_number_one > _temp_number_two) ? _test_file << _temp_number_one << " - large number\n" << _temp_number_two << " - smaller number\n" : _test_file << _temp_number_two << " - large number\n" << _temp_number_one << " - smaller number\n" << "---------------\n";
