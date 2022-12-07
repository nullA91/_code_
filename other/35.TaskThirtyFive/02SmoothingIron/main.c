#include "../Headers/libraries.h"
#include "../Headers/Functions/smoothing_iron.h"

int main(int arg_c, char* arg_v[])
{
    struct SmoothingIron smoothingIron;

    const size_t length = 1024;

    char path[1024];

    strcpy_s(path, length - 1, arg_v[0]);
    path[length - 1] = '\0';
    for(size_t i = 0; i < strlen(path); ++i)
    {
        if(path[i] == '\\')
            path[i] = '/';
    }
    strcat_s(path, length - 1, "/../../../Files/smoothing irons.txt");

    product_data_entry(&smoothingIron);
    product_data_output(&smoothingIron);
    writing_data_file(path, &smoothingIron);
    destruct_struct(&smoothingIron);

    return 0;
}
