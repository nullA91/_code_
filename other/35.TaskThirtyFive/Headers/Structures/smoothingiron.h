#ifndef SMOOTHINGIRON_H
#define SMOOTHINGIRON_H

/*
Задание 2. Реализовать структуру «Утюг» (фирма, модель,
цвет, минимальная температура, максимальная температура,
подача пара да/нет, мощность). Создайте экземпляр
структуры и проиллюстрируйте работу с ним.
*/

struct SmoothingIron
{
    char* company;
    char* model;
    char* color;
    unsigned int temp_min;
    unsigned int temp_max;
    unsigned int steam_supply;
    unsigned int power;
};

#endif // SMOOTHINGIRON_H
