#include "../Headers/Student.h"

// конструктор без параметров
Student::Student()
{
	name = nullptr;
	surname = nullptr;
	patronymic = nullptr;
	birth_date = nullptr;
	phone_number = nullptr;
	country = nullptr;
	city = nullptr;
	institution_name = nullptr;
	institution_country = nullptr;
	institution_city = nullptr;
	group_number = nullptr;
}
// конструктор копирования
Student::Student(const Student& student)
{
	name = new char[strlen(student.name) + 1];
	surname = new char[strlen(student.surname) + 1];
	patronymic = new char[strlen(student.patronymic) + 1];
	birth_date = new char[strlen(student.birth_date) + 1];
	phone_number = new char[strlen(student.phone_number) + 1];
	country = new char[strlen(student.country) + 1];
	city = new char[strlen(student.city) + 1];
	institution_name = new char[strlen(student.institution_name) + 1];
	institution_country = new char[strlen(student.institution_country) + 1];
	institution_city = new char[strlen(student.institution_city) + 1];
	group_number = new char[strlen(student.group_number) + 1];

	strcpy_s(name, strlen(name), student.name);
	strcpy_s(surname, strlen(surname), student.surname);
	strcpy_s(patronymic, strlen(patronymic), student.patronymic);
	strcpy_s(birth_date, strlen(birth_date), student.birth_date);
	strcpy_s(phone_number, strlen(phone_number), student.phone_number);
	strcpy_s(country, strlen(country), student.country);
	strcpy_s(city, strlen(city), student.city);
	strcpy_s(institution_name, strlen(institution_name), student.institution_name);
	strcpy_s(institution_country, strlen(institution_country), student.institution_country);
	strcpy_s(institution_city, strlen(institution_city), student.institution_city);
	strcpy_s(group_number, strlen(group_number), student.group_number);
}
// деструктор
Student::~Student()
{
	if (name != nullptr) delete[] name;
	if (surname != nullptr) delete[] surname;
	if (patronymic != nullptr) delete[] patronymic;
	if (birth_date != nullptr) delete[] birth_date;
	if (phone_number != nullptr) delete[] phone_number;
	if (country != nullptr) delete[] country;
	if (city != nullptr) delete[] city;
	if (institution_name != nullptr) delete[] institution_name;
	if (institution_country != nullptr) delete[] institution_country;
	if (institution_city != nullptr) delete[] institution_city;
	if (group_number != nullptr) delete[] group_number;
}
// ввод данных о студенте
void Student::input()
{
	bool date = true;
	bool phone = true;

	const unsigned int length = 1024;

	char value[length];
	// имя
	std::cout << "enter student name: ";
	std::cin.getline(value, length - 1);
	
	if (name != nullptr) delete[] name;
	name = new char[strlen(value) + 1];
	strcpy_s(name, strlen(value) + 1, value);
	// фамилия
	std::cout << "enter student surname: ";
	std::cin.getline(value, length - 1);

	if (surname != nullptr) delete[] surname;
	surname = new char[strlen(value) + 1];
	strcpy_s(surname, strlen(value) + 1, value);
	// отчество
	std::cout << "enter student patronymic: ";
	std::cin.getline(value, length - 1);

	if (patronymic != nullptr) delete[] patronymic;
	patronymic = new char[strlen(value) + 1];
	strcpy_s(patronymic, strlen(value) + 1, value);
	// дата рождения
BIRTHDATE:
	std::cout << "enter your date of birth in the format dd.mm.year: ";
	std::cin.getline(value, length - 1);
	// проверка на правильность ввода
	if (strlen(value) != 10) goto BIRTHDATE;

	for (unsigned int i = 0; i < strlen(value); ++i)
	{
		if (i == 2 || i == 5)
			date = (value[i] == '.') ? true : false; //if(value[i] != '.') date = false;
		else
			date = (value[i] >= '0' && value[i] <= '9') ? true : false; //if(!(value[i] >= '0' && value[i] <= '9')) date = false;
	}
	//////////////////////////////////
	if (date)
	{
		if (birth_date != nullptr) delete[] birth_date;
		birth_date = new char[strlen(value) + 1];
		strcpy_s(birth_date, strlen(value) + 1, value);
	}
	else goto BIRTHDATE;
	// номер телефона
PHONENUMBER:
	std::cout << "enter the phone number in the format +380(XX)-XXX-XX-XX: ";
	std::cin.getline(value, length - 1);
	// проверка на правильность ввода
	if (strlen(value) != 18) goto PHONENUMBER;

	for (unsigned int i = 0; i < strlen(value); ++i)
	{
		if (i == 0) phone = (value[i] == '+') ? true : false;
		else if (i == 4) phone = (value[i] == '(') ? true : false;
		else if (i == 7) phone = (value[i] == ')') ? true : false;
		else if (i == 8 || i == 12 || i == 15) phone = (value[i] = '-') ? true : false;
		else phone = (value[i] >= '0' && value[i] <= '9') ? true : false;
	}
	//////////////////////////////////
	if (phone)
	{
		if (phone_number != nullptr) delete[] phone_number;
		phone_number = new char[strlen(value) + 1];
		strcpy_s(phone_number, strlen(value) + 1, value);
	}
	else goto PHONENUMBER;
	// страна проживания
	std::cout << "enter the student's country of residence: ";
	std::cin.getline(value, length - 1);

	if (country != nullptr) delete[] country;
	country = new char[strlen(value) + 1];
	strcpy_s(country, strlen(value) + 1, value);
	// город проживания
	std::cout << "enter student's city of residence: ";
	std::cin.getline(value, length - 1);

	if (city != nullptr) delete[] city;
	city = new char[strlen(value) + 1];
	strcpy_s(city, strlen(value) + 1, value);
	// название института
	std::cout << "enter institute name: ";
	std::cin.getline(value, length - 1);

	if (institution_name != nullptr) delete[] institution_name;
	institution_name = new char[strlen(value) + 1];
	strcpy_s(institution_name, strlen(value) + 1, value);
	// страна где располагается институт
	std::cout << "enter the country where the institute is located: ";
	std::cin.getline(value, length - 1);

	if (institution_country != nullptr) delete[] institution_country;
	institution_country = new char[strlen(value) + 1];
	strcpy_s(institution_country, strlen(value) + 1, value);
	// город где располагается институт
	std::cout << "enter the city where the institute is located: ";
	std::cin.getline(value, length - 1);

	if (institution_city != nullptr) delete[] institution_city;
	institution_city = new char[strlen(value) + 1];
	strcpy_s(institution_city, strlen(value) + 1, value);
	// номер группы
	std::cout << "enter group number: ";
	std::cin.getline(value, length - 1);

	if (group_number != nullptr) delete[] group_number;
	group_number = new char[strlen(value) + 1];
	strcpy_s(group_number, strlen(value) + 1, value);
}
// вывод данных о студенте
void Student::output()
{
	// alt символы верхних углов
	const unsigned char top_left_corner = 201; // alt символ верхнего левого угла
	const unsigned char top_right_corner = 187; // alt символ верхнего правого угла
												// alt символы нижних углов
	const unsigned char bottom_left_corner = 200; // alt символ нижнего левого угла
	const unsigned char bottom_right_corner = 188; // alt символ нижнего правого угла
												   // alt символ верхней и нижней границы
	const unsigned char horizontal_border = 205;
	// alt символ левой и правой границы
	const unsigned char vertical_border = 186;

	// символ пробела
	const unsigned char space = 32;

	const unsigned int length = 50;
	const unsigned int size_data = 12;

	std::string data;
	std::string temp;

	data = "Student";
	temp = " ";

	temp.push_back(name[0]);
	temp.push_back('.');
	temp.push_back(surname[0]);

	for (unsigned int i = 0; i < size_data; ++i)
	{
		data = (i == 0) ? data.append(temp) : (i == 1) ? this->name : (i == 2) ? this->surname : (i == 3) ? this->patronymic : \
			(i == 4) ? this->birth_date : (i == 5) ? this->phone_number : (i == 6) ? this->country : (i == 7) ? this->city : \
			(i == 8) ? this->institution_name : (i == 9) ? this->institution_country : (i == 10) ? this->institution_city : this->group_number;
		// верхняя часть строки
		std::cout << top_left_corner;
		for (unsigned int j = 0; j < length; ++j)
			std::cout << horizontal_border;
		std::cout << top_right_corner << std::endl;
		// середина строки
		std::cout << vertical_border;
		for (unsigned int j = 0; j < (length - (data.length() + 2)) / 2; ++j)
			std::cout << space;
		std::cout << data;
		for (unsigned int j = (length - (data.length() + 2)) / 2 + data.length(); j < length; ++j)
			std::cout << space;
		std::cout << vertical_border << std::endl;
		// нижняя часть строки
		std::cout << bottom_left_corner;
		for (unsigned int j = 0; j < length; ++j)
			std::cout << horizontal_border;
		std::cout << bottom_right_corner << std::endl;
	}
}
// запись данных в файл
void Student::write_data_file(const std::string& path)
{
	// символы верхних углов
	const unsigned char top_left_corner = '+'; // символ верхнего левого угла
	const unsigned char top_right_corner = '+'; // символ верхнего правого угла
												// символы нижних углов
	const unsigned char bottom_left_corner = '+'; // символ нижнего левого угла
	const unsigned char bottom_right_corner = '+'; // символ нижнего правого угла
												   // символ верхней и нижней границы
	const unsigned char horizontal_border = '-';
	// символ левой и правой границы
	const unsigned char vertical_border = '|';

	// символ пробела
	const unsigned char space = 32;

	const unsigned int length = 90;

	std::ofstream fout;

	fout.open(path, std::ios_base::app);

	/* ########################### */
	/*        первая строка        */
	/* ########################### */
	fout << top_left_corner;
	for (unsigned int i = 0; i < length - 1; ++i)
	{
		if (i != 30 && i != 60)
			fout << horizontal_border;
		else
			fout << '+';
	}
	fout << top_right_corner << std::endl;
	// имя
	fout << vertical_border;
	fout << "name:";
	for (unsigned int i = strlen("name:"); i < (length / 3 - strlen(name)); ++i)
	{
		fout << space;
	}
	fout << name;
	fout << vertical_border;
	// фамилия
	fout << "surname:";
	for (unsigned int i = strlen("surname:"); i < (length / 3 - (strlen(surname) + 1)); ++i)
	{
		fout << space;
	}
	fout << surname;
	fout << vertical_border;
	// отчество
	fout << "patronymic:";
	for (unsigned int i = strlen("patronymic:"); i < (length / 3 - (strlen(patronymic) + 2)); ++i)
	{
		fout << space;
	}
	fout << patronymic;
	fout << vertical_border << std::endl;
	/* ########################### */
	/*        вторая строка        */
	/* ########################### */
	fout << bottom_left_corner;
	for (unsigned int i = 0; i < length - 1; ++i)
	{
		if (i != 30 && i != 60)
			fout << horizontal_border;
		else
			fout << '+';
	}
	fout << bottom_right_corner << std::endl;
	// телефон
	fout << vertical_border;
	fout << "phone:";
	for (unsigned int i = strlen("phone:"); i < (length / 3 - strlen(phone_number)); ++i)
	{
		fout << space;
	}
	fout << phone_number;
	fout << vertical_border;
	// дата рождения
	fout << "date of birth:";
	for (unsigned int i = strlen("date of birth:"); i < (length / 3 - (strlen(birth_date) + 1)); ++i)
	{
		fout << space;
	}
	fout << birth_date;
	fout << vertical_border;
	// номер группы
	fout << "group name:";
	for (unsigned int i = strlen("group name:"); i < (length / 3 - (strlen(group_number) + 2)); ++i)
	{
		fout << space;
	}
	fout << group_number;
	fout << vertical_border << std::endl;
	/* ########################### */
	/*        третья строка        */
	/* ########################### */
	fout << bottom_left_corner;
	for (unsigned int i = 0; i < length - 1; ++i)
	{
		if (i == 45)
			fout << '+';
		else if (i == 30 || i == 60)
			fout << '+';
		else
			fout << horizontal_border;
	}
	fout << bottom_right_corner << std::endl;
	// страна
	fout << vertical_border;
	fout << "country:";
	for (unsigned int i = strlen("country:"); i < (length / 2 - strlen(country)); ++i)
	{
		fout << space;
	}
	fout << country;
	fout << vertical_border;
	// город
	fout << "city:";
	for (unsigned int i = strlen("city:"); i < (length / 2 - (strlen(city) + 2)); ++i)
	{
		fout << space;
	}
	fout << city;
	fout << vertical_border << std::endl;
	/* ########################### */
	/*       четвертая строка     */
	/* ######################### */
	fout << bottom_left_corner;
	for (unsigned int i = 0; i < length - 1; ++i)
	{
		if (i == 45)
			fout << '+';
		else if (i == 30 || i == 60)
			fout << '+';
		else
			fout << horizontal_border;
	}
	fout << bottom_right_corner << std::endl;
	// название института
	fout << vertical_border;
	fout << "institute name:";
	for (unsigned int i = strlen("institute name:"); i < (length / 3 - strlen(institution_name)); ++i)
	{
		fout << space;
	}
	fout << institution_name;
	fout << vertical_border;
	// место расположения института(страна)
	fout << "country location:";
	for (unsigned int i = strlen("country location:"); i < (length / 3 - (strlen(institution_country) + 1)); ++i)
	{
		fout << space;
	}
	fout << institution_country;
	fout << vertical_border;
	// место расположения института(город)
	fout << "city location:";
	for (unsigned int i = strlen("city location:"); i < (length / 3 - (strlen(institution_city) + 2)); ++i)
	{
		fout << space;
	}
	fout << institution_city;
	fout << vertical_border << std::endl;
	/* ########################### */
	/*            конец           */
	/* ######################### */
	fout << '+';
	for (unsigned int i = 0; i < length - 1; ++i)
	{
		if (i != 30 && i != 60)
			fout << horizontal_border;
		else
			fout << '+';
	}
	fout << '+' << std::endl;

	fout << std::endl;
	for (unsigned int i = 0; i <= length; ++i)
	{
		fout << '#';
	}
	fout << '\n' << std::endl;

	fout.close();
}
// оператор <<(вывод данных о студенте)
std::ostream & operator<<(std::ostream& output, const Student& student)
{
	// символ угла
	const unsigned char corner = '+';								
	// символ верхней и нижней границы
	const unsigned char horizontal_border = '-';
	// символ левой и правой границы
	const unsigned char vertical_border = '|';
	// символ пробела
	const unsigned char space = 32;
	// количество столбцов
	const unsigned int columns = 50;
	// количество строк
	const unsigned int rows = 30;
	// значение
	char value[35];
	// вид студента
	char human[rows][columns];

	int index_key = 0;
	int index_value = 0;

	system("cls");
	for (unsigned int i = 0; i < rows; ++i)
	{
		for (unsigned int j = 0; j < columns; ++j)
		{
			// волосы
			if (i == 0)
			{
				if (j == (columns / 2 - 2))
					human[i][j] = '\\';
				else if (j == (columns / 2 - 1) || j == (columns / 2) || j == (columns / 2 + 1))
					human[i][j] = '|';
				else if (j == (columns / 2 + 2))
					human[i][j] = '/';
				else
					human[i][j] = space;
			}
			// голова
			else if (i == 1)
			{
				if (j == (columns / 2 - 2))
					human[i][j] = '(';
				else if (j == (columns / 2 - 1) || j == (columns / 2 + 1))
					human[i][j] = 'o';
				else if (j == (columns / 2 + 2))
					human[i][j] = ')';
				else
					human[i][j] = space;
			}
			else if (i == 2)
			{
				
				if (j == 0 || j == columns - 1)
					human[i][j] = corner;
				// пальцы
				else if (j == (columns / 2 - 6) || j == (columns / 2 - 5))
					human[i][j] = 'o';
				else if (j == (columns / 2 - 4))
					human[i][j] = 'O';
				// лицо
				else if (j == (columns / 2 - 1))
					human[i][j] = '(';
				else if (j == (columns / 2))
					human[i][j] = '_';
				else if (j == (columns / 2 + 1))
					human[i][j] = ')';
				// дефис
				else
					human[i][j] = horizontal_border;
			}
			// таблица
			else if (i > 2 && i < 24)
			{
				if (i % 2 == 0)
				{
					if (j == 0 || j == columns - 1)
						human[i][j] = corner;
					else
						human[i][j] = horizontal_border;
				}
				// имя
				if (i == 3)
				{
					if (j == 0 || j == columns - 1)
						human[i][j] = vertical_border;
					else
					{
						if (j > 0 && j < (strlen("name:") + 1))
						{
							strcpy_s(value, "NAME:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("name:") && j < (columns - student.getName().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getName().length() - 1))
						{
							strcpy_s(value, student.name);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// фамилия
				else if (i == 5)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("surname:") + 1))
						{
							strcpy_s(value, "SURNAME:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("surname:") && j < (columns - student.getSurname().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getSurname().length() - 1))
						{
							strcpy_s(value, student.surname);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// отчество
				else if (i == 7)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("patronymic:") + 1))
						{
							strcpy_s(value, "PATRONYMIC:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("patronymic:") && j < (columns - student.getPatronymic().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getPatronymic().length() - 1))
						{
							strcpy_s(value, student.patronymic);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// дата рождения
				else if (i == 9)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("date of birth:") + 1))
						{
							strcpy_s(value, "DATE OF BIRTH:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("date of birth:") && j < (columns - student.getDateBirth().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getDateBirth().length() - 1))
						{
							strcpy_s(value, student.birth_date);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// страна
				else if (i == 11)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("country:") + 1))
						{
							strcpy_s(value, "COUNTRY:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("country:") && j < (columns - student.getCountry().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getCountry().length() - 1))
						{
							strcpy_s(value, student.country);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// город
				else if (i == 13)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("city:") + 1))
						{
							strcpy_s(value, "CITY:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("city:") && j < (columns - student.getCity().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getCity().length() - 1))
						{
							strcpy_s(value, student.city);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// телефон
				else if (i == 15)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("phone number:") + 1))
						{
							strcpy_s(value, "PHONE NUMBER:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("phone number:") && j < (columns - student.getPhone().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getPhone().length() - 1))
						{
							strcpy_s(value, student.phone_number);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// номер группы
				else if (i == 17)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("group name:") + 1))
						{
							strcpy_s(value, "GROUP NAME:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("group name:") && j < (columns - student.getGroupNumber().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getGroupNumber().length() - 1))
						{
							strcpy_s(value, student.group_number);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// название института
				else if (i == 19)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("institut name:") + 1))
						{
							strcpy_s(value, "INSTITUT NAME:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("institut name:") && j < (columns - student.getInstitutName().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getInstitutName().length() - 1))
						{
							strcpy_s(value, student.institution_name);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// место расположения института(страна)
				else if (i == 21)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("country location:") + 1))
						{
							strcpy_s(value, "COUNTRY LOCATION:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("country location:") && j < (columns - student.getInstitutCountry().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getInstitutCountry().length() - 1))
						{
							strcpy_s(value, student.institution_country);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
				// место расположения института(город)
				else if (i == 23)
				{
					if (j == 0 || j == columns - 1)
					{
						index_key = 0;
						index_value = 0;
						human[i][j] = vertical_border;
					}
					else
					{
						if (j > 0 && j < (strlen("city location:") + 1))
						{
							strcpy_s(value, "CITY LOCATION:");
							if (value[index_key])
							{
								human[i][j] = value[index_key];
								++index_key;
							}
						}
						else if (j > strlen("city location:") && j < (columns - student.getInstitutCity().length() - 1))
							human[i][j] = space;
						else if (j >= (columns - student.getInstitutCity().length() - 1))
						{
							strcpy_s(value, student.institution_city);
							if (value[index_value])
							{
								human[i][j] = value[index_value];
								++index_value;
							}
						}
					}
				}
			}
			//
			else if (i == 24)
			{
				if (j == 0 || j == columns - 1)
					human[i][j] = corner;
				// пальцы
				else if (j == (columns / 2 + 4) || j == (columns / 2 + 5))
					human[i][j] = 'o';
				else if (j == (columns / 2 + 6))
					human[i][j] = 'O';
				// дефис
				else
					human[i][j] = horizontal_border;
			}
			// ноги
			else if (i == 25)
			{
				if (j == (columns / 2 - 3) || j == (columns / 2) || j == (columns / 2) + 3)
					human[i][j] = '|';
				else
					human[i][j] = space;
			}
			else if (i == 26)
			{
				if (j == (columns / 2 - 3) || j == (columns / 2) || j == (columns / 2 + 3))
					human[i][j] = '|';
				else if (j == (columns / 2 - 2) || j == (columns / 2 - 1) || j == (columns / 2 + 1) || j == (columns / 2 + 2))
					human[i][j] = '_';
				else
					human[i][j] = space;

			}
			else if (i == 27)
			{
				if (j == (columns / 2 - 2) || j == (columns / 2 - 1) || j == (columns / 2 + 1) || j == (columns / 2 + 2))
					human[i][j] = '|';
				else
					human[i][j] = space;
			}
			else if (i == 28)
			{
				if (j == (columns / 2 - 3))
					human[i][j] = '(';
				else if (j == (columns / 2 + 3))
					human[i][j] = ')';
				else if (j == (columns / 2 - 1))
					human[i][j] = ']';
				else if (j == (columns / 2 + 1))
					human[i][j] = '[';
				else
					human[i][j] = space;
			}
			else
				human[i][j] = '#';
		}
	}
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			output << human[i][j];
		output << std::endl;
	} 
	system("pause");

	return output;
}
