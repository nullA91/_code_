#ifndef POINT_H
#define POINT_H
/*
Задание 2. Создайте структуру, описывающую точку
в двумерной системе координат (x, y). С помощью этой
структуры задайте две точки. Напишите функцию, которая
вычисляет расстояние между этими двумя точками?
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int Y;
    int X;

    char** view;
};

void create_point(struct Point* point);
void output_point(struct Point* point);
int distance_between_points(const struct Point* pointA, const struct Point* pointB);
void menu_point(struct Point* point);
void destroy_point(struct Point* point);

#endif // POINT_H
