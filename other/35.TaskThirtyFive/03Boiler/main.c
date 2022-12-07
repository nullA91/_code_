#include "../Headers/libraries.h"
#include "../Headers/Functions/boiler_f.h"

int main(int arg_c, char* arg_v[])
{
    struct Boiler boiler;

    const size_t length = 1024;

    char path[1024];

    strcpy_s(path, length - 1, arg_v[0]);
    path[length - 1] = '\0';
    for(size_t i = 0; i < strlen(path); ++i)
    {
        if(path[i] == '\\')
            path[i] = '/';
    }
    strcat_s(path, length - 1, "/../../../Files/boilers.txt");

    product_data_entry(&boiler);
    product_data_output(&boiler);
    writing_data_file(path, &boiler);
    destruct_struct(&boiler);

    return 0;
}
