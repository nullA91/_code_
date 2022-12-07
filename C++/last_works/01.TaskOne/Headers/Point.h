#pragma once

#include "ComplexNumber.h"
#include "Libraries.h"

/*
���������� ����� �������.���������� ������� ���������� x, y, z � ���������� - ������ ������.
���������� ������� - ����� ������ ��� ����� ������, ������ ������, ���������� ��������� ��� 
������� � ���������� - ������, ���������� ���������� � ���� � �������� ������ �� �����.
*/

class Point : public Complex
{
	public:
		// ***** ������������ ***** //
		// ������������� �����������
		Point() : x(NULL), y(NULL), z(NULL) { }
		// ����������� �����������
		Point(const Point& point) : x(point.x), y(point.y) 
			{ z.setRez(x); z.setImz(y); }
		// ***** ������ ***** //
		// ���� ������
		bool input();
		// ����� ������
		bool output();
		// ***** ��������� ***** //
		// �������� �������� x
		int getX() { return x; }
		// �������� �������� y
		int getY() { return y; }
		// �������� �������� z
		Complex getZ() { return z; }
		// ***** �������� *****
		// ���������� �������� x
		void setX(const int& value) { x = value; }
		// ���������� �������� y
		void setY(const int& value) { y = value; }
		// ���������� �������� z
		void setZ(Complex& value)
		{
			x = value.getRez();
			y = value.getImz();
			z.setRez(value.getRez());
			z.setImz(value.getImz());
		}
		// ********************
		// ������ ������ � ����
		void write_data_file(std::ofstream& file, const std::string& path);
	private:
		int x;
		int y;
		Complex z;
};