#pragma once

#include "../Headers/Libraries.h"

class Triangle
{
	public:
		// универсальный конструктор
		Triangle(const int& width = 0, const int& length = 0, const int height = 0) : a(width), b(length), c(height) { }
		// конструктор копирования
		Triangle(const Triangle& triangle)
			{ a = triangle.a; b = triangle.b; c = triangle.c; }
		// ввод данных
		void input();
		// вывод данных
		void output();
		// ****** перегрузка операторов ******
		// ввод данных
		friend std::istream& operator>>(std::istream& stream_input, Triangle triangle);
		// вывод данных
		friend std::ostream& operator<<(std::ostream& stream_output, const Triangle& triangle);
	private:
		int a;
		int b;
		int c;
};