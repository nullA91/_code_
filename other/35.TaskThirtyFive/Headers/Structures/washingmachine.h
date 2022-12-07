#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

/*
Задание 1. Реализовать структуру «Стиральная машинка»
(фирма, цвет, ширина, длина, высота, мощность, скорость
отжима, температура нагрева). Создайте экземпляр структуры
и проиллюстрируйте работу с ним.
*/

struct WashingMachine
{
    char* company;
    char* color;
    float width;
    float length;
    float height;
    float power;
    unsigned int spin_speed;
    unsigned int temperature;
};

#endif // WASHINGMACHINE_H
