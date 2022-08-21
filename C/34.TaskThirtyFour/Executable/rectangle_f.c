#include "../../Headers/rectangle.h"
#include "../../Headers/functions.h"

// создание прямоугольника
void create_rectangle(struct Rectangle* rectangle)
{
    LENGTH:
    printf_s("%s", "enter length of rectangle: ");
    scanf("%i", &rectangle->length);
    if(rectangle->length < 0) goto LENGTH;
    WIDTH:
    printf_s("%s", "enter width of rectangle: ");
    scanf("%i", &rectangle->width);
    if(rectangle->width < 0) goto WIDTH;
}
// вывод прямоугольника
void output_rectangle(const struct Rectangle* rectangle, unsigned int* Y, unsigned int* X)
{
    unsigned int y = *Y;

    Sleep(50);
    system("cls");

    for(size_t i = 0; i < (size_t)rectangle->width; ++i)
    {
        set_console_cursor(y, *X);
        for(size_t j = 0; j < (size_t)rectangle->length * 2; ++j)
        {
            if(i == 0 || i == (size_t)rectangle->width - 1)
            {
                if(j == 0 || j == (size_t)rectangle->length * 2 - 1)
                    printf_s("%c", '+');
                else
                    printf_s("%c", '-');
            }
            else if(i > 0 && i < (size_t)rectangle->width - 1)
            {
                if(j == 0 || j == (size_t)rectangle->length * 2 - 1)
                    printf_s("%c", '|');
                else
                    printf_s("%c", ' ');
            }
        }
        printf_s("%c", '\n');
        ++y;
    }
}
// перемещение прямоугольника
int moving_rectangle(const struct Rectangle* rectangle, unsigned int* Y, unsigned int* X)
{
    int symbol;

    symbol = _getch();

    if(symbol == 224)
    {
        symbol = _getch();
        if(symbol == 72)
        {
            if(*Y > 0)
                --*Y;
        }
        else if (symbol == 80)
        {
            if(*Y < 25)
                ++*Y;
        }
        else if(symbol == 75)
        {
            if(*X > 0)
                --*X;
        }
        else if(symbol == 77)
        {
            if(*X < 110)
                ++*X;
        }
    }
    else if(symbol == 32)
        return 0;

    output_rectangle(rectangle, Y, X);
    return 1;
}
// изменение размера прямоугольника
int resizing_rectangle(struct Rectangle* rectangle, unsigned int Y, unsigned int X)
{
    int symbol;

    symbol = _getch();

    if(symbol == 224)
    {
        symbol = _getch();
        if(symbol == 72)
        {
            if(rectangle->width > 3)
                rectangle->width--;

        }
        else if (symbol == 80)
        {
            rectangle->width++;
        }
        else if(symbol == 75)
        {
            if(rectangle->length > 2)
                rectangle->length -= 2;
        }
        else if(symbol == 77)
        {
            if(rectangle->length < 50)
                rectangle->length += 2;
        }
    }
    else if(symbol == 32)
        return 0;

    output_rectangle(rectangle, &Y, &X);
    return 1;
}
// меню выбора функций прямоугольника
void menu_rectangle(struct Rectangle* rectangle)
{
    int Y = 0;
    int X = 0;

    unsigned int choise = 0;

    do
    {
        system("cls");
        printf_s("\t%s\n", "menu");
        printf_s("%s\n", "1. Enter the length and width of the rectangle");
        printf_s("%s\n", "2. Output rectangle");
        printf_s("%s\n", "3. Move the rectangle");
        printf_s("%s\n", "4. Resizing the rectangle");
        printf_s("%s\n", "0. EXIT");
        printf_s("%s\n", "select menu item: ");
        printf_s("select menu item: ");
        scanf("%u", &choise);

        system("cls");
        switch(choise)
        {
            case 1:
            {
                create_rectangle(rectangle);
                break;
            }
            case 2:
            {
                Y:
                printf_s("enter Y-coordinate: ");
                scanf("%i", &Y);
                if(Y < 0)
                    goto Y;
                X:
                printf_s("enter X-coordinate: ");
                scanf("%i", &X);
                if(Y < 0)
                    goto X;

                output_rectangle(rectangle, &Y, &X);
                break;
            }
            case 3:
            {
                output_rectangle(rectangle, &Y, &X);
                while(moving_rectangle(rectangle, &Y, &X))
                {
                    printf_s("%s\n", "press space to exit");
                }
                break;
            }
            case 4:
            {
                output_rectangle(rectangle, &Y, &X);
                while(resizing_rectangle(rectangle, Y, X))
                {
                    printf_s("%s\n", "press space to exit");
                }
                break;
            }
            default:
                if(choise != 0)
                    printf_s("%s\n", "select the correct menu item");
                break;
        }
        if(choise)
        {
            printf_s("%s", "continue(1.yes/0.no): ");
            scanf("%u", &choise);
        }
    }while(choise);
}
// ####################### //
// *** координаты мыши *** //
// ####################### //

/*
// левый верхний угол
const unsigned int top_left_corner_Y = Y;
const unsigned int top_left_corner_X = X;
// правый верхний угол
const unsigned int top_right_corner_Y = Y;
const unsigned int top_right_corner_X = (unsigned int)rectangle->length * 2 + X - 1;
// левый нижний угол
const unsigned int bottom_left_corner_Y = Y + (unsigned int)rectangle->width - 1;
const unsigned int bottom_left_corner_X = X;
// правый нижний угол
const unsigned int bottom_right_corner_Y = Y + (unsigned int)rectangle->width - 1;
const unsigned int bottom_right_corner_X = (unsigned int)rectangle->length * 2 + X - 1;

HWND console;
POINT mouse_cursor_coord;

int y = 0;
int x = 0;

console = GetConsoleWindow();

GetCursorPos (&mouse_cursor_coord);
ScreenToClient(console, &mouse_cursor_coord);

y = mouse_cursor_coord.y / 16;
x = mouse_cursor_coord.x / 8;

if(top_left_corner_Y == (unsigned int)y && top_left_corner_X == (unsigned int)x)
    printf_s("%s", "TLC");
else if(top_right_corner_Y == (unsigned int)y && top_right_corner_X == (unsigned int)x)
    printf_s("%s", "TRC");
else if(bottom_left_corner_Y == (unsigned int)y && bottom_left_corner_X == (unsigned int)x)
    printf_s("%s", "BLC");
else if(bottom_right_corner_Y == (unsigned int)y && bottom_right_corner_X == (unsigned int)x)
    printf_s("%s", "BRC");
*/


//printf_s("%s%i\n", "mouse Y: ", y/*mouse_cursor_coord.y / 16*/);
//printf_s("%s%i\n", "mouse X: ", x/*mouse_cursor_coord.x / 8*/);

//printf_s("%s%i\n","TLCY:", top_left_corner_Y);
//printf_s("%s%i\n","TLCX:", top_left_corner_X);

//printf_s("%s%i\n","TRCY:", top_right_corner_Y);
//printf_s("%s%i\n","TLCX:", top_right_corner_X);

//printf_s("%s%i\n","BLCY:", bottom_left_corner_Y);
//printf_s("%s%i\n","BLCX:", bottom_left_corner_X);

//printf_s("%s%i\n","BRCY:", bottom_right_corner_Y);
//printf_s("%s%i\n","BRCX:", bottom_right_corner_X);
