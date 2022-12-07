 #pragma once

#include "Libraries.h"

/*
—оздайте класс Ђ омплексное числої - Complex.
 ласс должен содержать несколько конструкторов.
 ласс должен иметь возможность вводить и выводить 
комплексные числа посредством перегруженных операций >> и << .
ѕерегрузите операции +, -, !=, ==, ().
»спользуйте обычную и дружественную перегрузку.
*/

class Complex
{
	public:
		// универсальный конструктор
		Complex(const int& A = 0, const int& B = 0) : Rez(A), Imz(B) { object_counter++; }
		// конструктор копировани€
		Complex(const Complex& complex_number) : Rez(complex_number.Rez), Imz(complex_number.Imz) { object_counter++; }
		// деструктор
		~Complex() { object_counter--; }

		// количество созданных объектов
		static int getObjectCount() { return object_counter; }

		// перегрузка оператора +
		Complex operator+(const Complex& second_value);
		// перегрузка оператора -
		Complex operator-(const Complex& second_value);
		// получить значение действительной части
		int getRez() { return Rez; }
		// получить значение мнимой части
		int getImz() { return Imz; }
		// задани€ значени€ действительной части
		void setRez(const int& value) { Rez = value; }
		// задани€ значени€ мнимой части
		void setImz(const int& value) { Imz = value; }
		// перегрузка оператора ==
		bool operator==(const Complex& second_value);
		// перегрузка оператора !=
		bool operator!=(const Complex& second_value);
		// перегрузка оператора >>
		friend std::istream& operator>>(std::istream& input_stream, Complex& complex_number);
		// перегрузка оператора <<
		friend std::ostream& operator<<(std::ostream& output_stream, const Complex& complex_number);
		// запись данных в файл
		friend std::ofstream& operator<<(std::ofstream& file, const Complex& complex_number);
	protected:
		static int object_counter;

		int Rez;
		int Imz;
};