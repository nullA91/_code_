#ifndef BOILER_H
#define BOILER_H

/*
Задание 3. Реализовать структуру «Бойлер» (фирма, цвет,
мощность, объем, температура нагрева).
Создайте экземпляр структуры и проиллюстрируйте работу с ним.
*/

struct Boiler
{
    char* company;
    char* color;
    unsigned int power;
    unsigned int volume;
    unsigned int heating_temperature;
};

#endif // BOILER_H
