#include "../Headers/libraries.h"
#include "../Headers/Functions/washing_machine.h"

int main(int arg_c, char* arg_v[])
{
    struct WashingMachine washingMachine;

    const size_t length = 1024;

    char path[1024];

    strcpy_s(path, length - 1, arg_v[0]);
    path[length - 1] = '\0';
    for(size_t i = 0; i < strlen(path); ++i)
    {
        if(path[i] == '\\')
            path[i] = '/';
    }
    strcat_s(path, length - 1, "/../../../Files/washing machines.txt");

    product_data_entry(&washingMachine);
    product_data_output(&washingMachine);
    writing_data_file(path, &washingMachine);
    destruct_struct(&washingMachine);

    return 0;
}
