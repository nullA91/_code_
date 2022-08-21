#include "../Headers/Functions/animal_f.h"

int main(int arg_c, char* arg_v[])
{
    struct Animal animal;

    const size_t length = 1024;

    char path[1024];

    strcpy_s(path, length - 1, arg_v[0]);
    path[length - 1] = '\0';
    for(size_t i = 0; i < strlen(path); ++i)
    {
        if(path[i] == '\\')
            path[i] = '/';
    }
    strcat_s(path, length - 1, "/../../../Files/animals.txt");

    product_data_entry(&animal);
    product_data_output(&animal);
    writing_data_file(path, &animal);

    wchar_t vote[1024];

    strcpy_s((char*)vote, length - 1, arg_v[0]);
    vote[strlen((char*)vote)] = L'\0';
    for(size_t i = 0; i < strlen((char*)vote); ++i)
    {
        if((char)vote[i] == '\\')
            vote[i] = '/';
    }
    strcat_s((char*)vote, length - 1, "/../../../Resources/sounds/");

    cast_vote(&animal, vote);

    destruct_struct(&animal);

    return 0;
}
