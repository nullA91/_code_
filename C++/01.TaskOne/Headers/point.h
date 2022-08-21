#ifndef POINT_H
#define POINT_H

#include "../../Headers/libraries.h"

class Point
{
    private:
        double Y;
        double X;
        double Z;

        std::string* view;
    public:
        // конструктор без параметров
        Point();
        // конструктор копирования
        Point(const Point& point);
        // деструктор
        ~Point();
        void create_point();
        void output_point();
        int distance_between_points(const Point& pointB);
        void menu_point();
        void destroy_point();
};

#endif // POINT_H
