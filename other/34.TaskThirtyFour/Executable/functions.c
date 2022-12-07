#include "../../Headers/functions.h"

#include "../../Headers/fraction.h"
#include "../../Headers/point.h"
#include "../../Headers/rectangle.h"

// установка позиции курсора в консоли
void set_console_cursor(const unsigned int Y, const unsigned int X)
{
    HANDLE console;
    COORD coordinates;

    console = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.Y = (short)Y;
    coordinates.X = (short)X;

    SetConsoleCursorPosition(console, coordinates);
}
// меню консоли
void menu_console()
{
    unsigned int choise = 0;

    do
    {
        system("cls");
        printf_s("\t%s\n", "menu");
        printf_s("%s\n", "1. Rectangle");
        printf_s("%s\n", "2. Point on the coordinate plane");
        printf_s("%s\n", "3. Fraction");
        printf_s("%s\n", "0. EXIT");
        printf_s("select menu item: ");
        scanf("%u", &choise);

        system("cls");
        switch (choise)
        {
            case 1:
            {
                struct Rectangle rectangle;
                menu_rectangle(&rectangle);
                break;
            }
            case 2:
            {
                struct Point point;
                menu_point(&point);
                break;
            }
            case 3:
            {
                struct Fraction fraction;
                menu_fraction(&fraction);
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



/*
void set_console_cursor(const unsigned int Y, const unsigned int X)
{
    static unsigned int y;
    static unsigned int x;

    static unsigned int startY = 0;
    unsigned int startX = 0;

    y = Y; x = X;

    for(; startY < y; ++startY)
        printf_s("%c", '\n');
    for(; startX < x; ++startX)
        printf_s("%c", ' ');
    ++y;
}
*/
