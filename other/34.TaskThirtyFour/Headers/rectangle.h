#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <conio.h>
#include <stdio.h>

/*
Задание 1.
Создать структуру, описывающую прямоугольник.
Написать функции для работы с этой структурой:
перемещение прямоугольника, изменение размера
прямоугольника, печать прямоугольника.
*/

struct Rectangle
{
    int length;
    int width;
};

void create_rectangle(struct Rectangle* rectangle);
void output_rectangle(const struct Rectangle* rectangle, unsigned int* Y, unsigned int* X);
int moving_rectangle(const struct Rectangle* rectangle, unsigned int* Y, unsigned int* X);
int resizing_rectangle(struct Rectangle* rectangle, unsigned int Y, unsigned int X);
void menu_rectangle(struct Rectangle* rectangle);

#endif // RECTANGLE_H
