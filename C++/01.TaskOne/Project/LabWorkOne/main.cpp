#include "../../Headers/student.h"

int main(int, char* arg_v[])
{

    Student s;
    s.input();
    s.output();
    std::string path = arg_v[0];
    for(unsigned int i = 0; i < path.length(); ++i)
    {
        if(path[i] == '\\')
            path[i] = '/';
    }
    path.append("/../../../../Files/student_data.txt");
    std::cout << path << std::endl;
    s.write_data_file(path);

    return 0;
}
