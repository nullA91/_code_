#pragma once

#include "ComplexNumber.h"
#include "Libraries.h"

/*
Реализуйте класс “Точка”.Необходимо хранить координаты x, y, z в переменных - членах класса.
Реализуйте функции - члены класса для ввода данных, вывода данных, реализуйте аксессоры для 
доступа к переменным - членам, реализуйте сохранение в файл и загрузку данных из файла.
*/

class Point : public Complex
{
	public:
		// ***** конструкторы ***** //
		// универсальный конструктор
		Point() : x(NULL), y(NULL), z(NULL) { }
		// конструктор копирования
		Point(const Point& point) : x(point.x), y(point.y) 
			{ z.setRez(x); z.setImz(y); }
		// ***** методы ***** //
		// ввод данных
		bool input();
		// вывод данных
		bool output();
		// ***** аксессоры ***** //
		// получить значение x
		int getX() { return x; }
		// получить значение y
		int getY() { return y; }
		// получить значение z
		Complex getZ() { return z; }
		// ***** мутаторы *****
		// установить значение x
		void setX(const int& value) { x = value; }
		// установить значение y
		void setY(const int& value) { y = value; }
		// установить значение z
		void setZ(Complex& value)
		{
			x = value.getRez();
			y = value.getImz();
			z.setRez(value.getRez());
			z.setImz(value.getImz());
		}
		// ********************
		// запись данных в файл
		void write_data_file(std::ofstream& file, const std::string& path);
	private:
		int x;
		int y;
		Complex z;
};