#pragma once

#include "../Headers/Libraries.h"

class Triangle
{
	public:
		// ������������� �����������
		Triangle(const int& width = 0, const int& length = 0, const int height = 0) : a(width), b(length), c(height) { }
		// ����������� �����������
		Triangle(const Triangle& triangle)
			{ a = triangle.a; b = triangle.b; c = triangle.c; }
		// ���� ������
		void input();
		// ����� ������
		void output();
		// ****** ���������� ���������� ******
		// ���� ������
		friend std::istream& operator>>(std::istream& stream_input, Triangle triangle);
		// ����� ������
		friend std::ostream& operator<<(std::ostream& stream_output, const Triangle& triangle);
	private:
		int a;
		int b;
		int c;
};