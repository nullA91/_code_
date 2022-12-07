 #pragma once

#include "Libraries.h"

/*
�������� ����� ������������ ����� - Complex.
����� ������ ��������� ��������� �������������.
����� ������ ����� ����������� ������� � �������� 
����������� ����� ����������� ������������� �������� >> � << .
����������� �������� +, -, !=, ==, ().
����������� ������� � ������������� ����������.
*/

class Complex
{
	public:
		// ������������� �����������
		Complex(const int& A = 0, const int& B = 0) : Rez(A), Imz(B) { object_counter++; }
		// ����������� �����������
		Complex(const Complex& complex_number) : Rez(complex_number.Rez), Imz(complex_number.Imz) { object_counter++; }
		// ����������
		~Complex() { object_counter--; }

		// ���������� ��������� ��������
		static int getObjectCount() { return object_counter; }

		// ���������� ��������� +
		Complex operator+(const Complex& second_value);
		// ���������� ��������� -
		Complex operator-(const Complex& second_value);
		// �������� �������� �������������� �����
		int getRez() { return Rez; }
		// �������� �������� ������ �����
		int getImz() { return Imz; }
		// ������� �������� �������������� �����
		void setRez(const int& value) { Rez = value; }
		// ������� �������� ������ �����
		void setImz(const int& value) { Imz = value; }
		// ���������� ��������� ==
		bool operator==(const Complex& second_value);
		// ���������� ��������� !=
		bool operator!=(const Complex& second_value);
		// ���������� ��������� >>
		friend std::istream& operator>>(std::istream& input_stream, Complex& complex_number);
		// ���������� ��������� <<
		friend std::ostream& operator<<(std::ostream& output_stream, const Complex& complex_number);
		// ������ ������ � ����
		friend std::ofstream& operator<<(std::ofstream& file, const Complex& complex_number);
	protected:
		static int object_counter;

		int Rez;
		int Imz;
};