#pragma once

/*
���������� ����� ��������. ���������� ������� � ����������-������ ������: ���, ���� ��������, ���������� �������, 
�����, ������, �������� �������� ���������, ����� � ������ (��� ��������� ������� ���������),  ����� ������. 
���������� �������-����� ������ ��� ����� ������, ������ ������, ���������� ��������� ��� ������� � ��������� ����������-������.
*/

#include "Libraries.h"

class Student
{
private:
	char* name;
	char* surname;
	char* patronymic;
	char* birth_date;
	char* phone_number;
	char* country;
	char* city;
	char* institution_name;
	char* institution_country;
	char* institution_city;
	char* group_number;
public:
	// ����������� ��� ����������
	Student();
	// ����������� �����������
	Student(const Student&);
	// ����������
	~Student();
	// **************************** //
	// ********** ������ ********** //
	// **************************** //
	// ���� ������
	void input();
	// ����� ������
	void output();
	// ������ ������ � ����
	void write_data_file(const std::string& path);
	// **************************** //
	// ********* ��������� ******** //
	// **************************** //
	// ��� ��������
	inline const std::string getName() const { return name; }
	// ������� ��������
	inline const std::string getSurname() const { return surname; }
	// �������� ��������
	inline const std::string getPatronymic() const { return patronymic; }
	// ���� �������� ��������
	inline const std::string getDateBirth() const { return birth_date; }
	// ���������� ����� ��������
	inline const std::string getPhone() const { return phone_number; }
	// ������ �������� ��������
	inline const std::string getCountry() const { return country; }
	// ����� �������� ��������
	inline const std::string getCity() const { return city; }
	// �������� �������� ���������
	inline const std::string getInstitutName() const { return institution_name; }
	// ������ ������������ �������� ���������
	inline const std::string getInstitutCountry() const { return institution_country; }
	// ����� ������������ �������� ���������
	inline const std::string getInstitutCity() const { return institution_city; }
	// ����� ������
	inline const std::string getGroupNumber() const { return group_number; }
	// ***************************** //
	// *** ���������� ���������� *** //
	// ***************************** //
	friend std::ostream& operator<< (std::ostream& output, const Student& student);
};