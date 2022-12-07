#include "../Headers/point.h"

// ввод координат точки
void create_point(struct Point* point)
{
    const int additional_value = 10;

    int rows = 0;
    int columns = 0;
    int y = 0;
    int x = 0;

    printf_s("%s", "enter the Y-coordinate: ");
    scanf("%i", &point->Y);
    printf_s("%s", "enter the X-coordinate: ");
    scanf("%i", &point->X);

    y = (point->Y < 0) ?  -(point->Y) : point->Y;
    x = (point->X < 0) ?  -(point->X) : point->X;

    rows = y * 2 + additional_value;
    columns = (x * 2 + additional_value) * 2;
    // выделение памяти
    point->view = (char**)malloc((unsigned int)rows * sizeof (char*));
    for(size_t i = 0; i < (size_t)rows; ++i)
    {
        point->view[i] = (char*)malloc(((unsigned int)columns + 1) * sizeof (char));
    }
    // ******************************************************* //
    // ******* заполнение вида кооординатной плоскости ******* //
    // ******************************************************* //

    // стрелка показывающая вверх
    for(int i = 0; i < columns; ++i)
    {
        if(i == columns / 2)
            point->view[0][i] = (char)30;
        else
            point->view[0][i] = ' ';
    }
    point->view[0][columns] = '\0';
    // ось Y
    for(int i = 1; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            if(j == columns / 2)
            {
                point->view[i][j] = (char)197;
            }
            else
                point->view[i][j] = ' ';
        }
        point->view[i][columns] = '\0';
    }
    // ось X
    int vert_sl = 0;

    for(int i = 0; i < columns; ++i)
    {
        if(i != columns / 2)
            point->view[rows / 2][i] = (char)196;
        else
            point->view[rows / 2][i] = (char)197;
        if(i == vert_sl)
        {
            point->view[rows / 2][i] = (char)179;
            vert_sl += 2;
        }
    }
    point->view[rows / 2][columns - 1] = (char)16;
    point->view[rows / 2][columns] = '\0';
    // *************** начало(13:00) *************** //
    // ***************** ДОРАБОТКА ***************** //
    // ********************************************* //
    int* positive_index_r = (int*)malloc((unsigned int)(rows / 2 - 1) * sizeof (int));
    int* negative_index_r = (int*)malloc((unsigned int)(rows / 2 - 1) * sizeof (int));

    int value = 0;

    value = rows / 2 - 1;
    for(int i = 0; i < rows / 2 - 1; ++i)
    {
        positive_index_r[i] = value;
        --value;
    }
    value = rows / 2 + 1;
    for(int i = 0; i < rows / 2 - 1; ++i)
    {
        negative_index_r[i] = value;
        ++value;
    }

    int* positive_index_c = (int*)malloc((unsigned int)(columns / 4 - 1) * sizeof (int));
    int* negative_index_c = (int*)malloc((unsigned int)(columns / 4) * sizeof (int));

    value = columns / 2;
    for(int i = 0; i < columns / 4 - 1; ++i)
    {
        positive_index_c[i] = value;
        value += 2;
    }
    value = columns / 2 - 2;
    for(int i = 0; i < columns / 4; ++i)
    {
        negative_index_c[i] = value;
        value -= 2;
    }

    int Y = 0;
    int X = 0;

    // координата Y
    if(point->Y > 0)
    {
        Y = positive_index_r[point->Y - 1];
    }
    else
    {
        value = -(point->Y);
        Y = negative_index_r[value - 1];
    }
    // координата X
    if(point->X > 0)
    {
        X = positive_index_c[point->X];
    }
    else
    {
        value = -(point->X);
        X = negative_index_c[value - 1];
    }

    point->view[Y][X] = (char)254;

    free(positive_index_r);
    free(negative_index_r);
    free(positive_index_c);
    free(negative_index_c);
}
// вывод точки на координатной плоскости
void output_point(struct Point* point)
{
    system("cls");

    const int additional_value = 10;

    int rows = 0;
    int columns = 0;
    int y = 0;
    int x = 0;

    y = (point->Y < 0) ?  -(point->Y) : point->Y;
    x = (point->X < 0) ?  -(point->X) : point->X;

    rows = y * 2 + additional_value;
    columns = (x * 2 + additional_value) * 2;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
            printf_s("%c", point->view[i][j]);
        printf_s("%c", '\n');
    }
}
// расстояние между двумя точками
int distance_between_points(const struct Point* pointA, const struct Point* pointB)
{
    int Y = 0;
    int X = 0;
    int root = 0;

    int distance = 0;

    Y = pow(pointB->Y - pointA->Y, 2);
    X = pow(pointB->X - pointA->X, 2);
    root = X + Y;

    distance = sqrt(root);

    return distance;
}
// меню выбора функций структуры(точка)
void menu_point(struct Point* point)
{
    unsigned int choise = 0;

    do
    {
        system("cls");
        printf_s("\t%s\n", "menu");
        printf_s("%s\n", "1. entering coordinates");
        printf_s("%s\n", "2. output of a point on a coordinate plane");
        printf_s("%s\n", "3. distance between points");
        printf_s("%s\n", "0. EXIT");
        printf_s("select menu item: ");
        scanf("%u", &choise);

        system("cls");
        switch (choise)
        {
            case 1:
                create_point(point);
                break;
            case 2:
                output_point(point);
                break;
            case 3:
            {
                struct Point A;
                struct Point B;

                int counter = 0;
                int distance = 0;

                printf_s("%s%c%i\n", "Point", ' ', ++counter);
                create_point(&A);
                system("cls");
                printf_s("%s%c%i\n", "Point", ' ', ++counter);
                create_point(&B);

                distance = distance_between_points(&A, &B);

                system("cls");
                printf_s("%s%i\n", "approximate distance between points: ", distance);
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
// освобождение памяти
void destroy_point(struct Point* point)
{
    const int additional_value = 10;

    int y = (point->Y < 0) ?  -(point->Y) : point->Y;
    int rows = y * 2 + additional_value;

    for(int i = 0; i < rows; ++i)
        free(point->view[i]);
    free(point->view);
}
