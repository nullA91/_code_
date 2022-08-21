#ifndef STUDENT_H
#define STUDENT_H

#include "../../Headers/libraries.h"

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
        // конструктор без параметров
        Student();
        // конструктор копирования
        Student(const Student&);
        // деструктор
        ~Student();
        // **************************** //
        // ********** методы ********** //
        // **************************** //
        // ввод данных
        void input();
        // вывод данных
        void output();
        // запись данных в файл
        void write_data_file(const std::string& path);
        // **************************** //
        // ********* аксессоры ******** //
        // **************************** //
        // имя студента
        inline const std::string getName() const { return name; }
        // фамилия студента
        inline const std::string getSurname() const { return surname; }
        // отчество студента
        inline const std::string getPatronymic() const { return patronymic; }
        // дата рождения студента
        inline const std::string getDateBirth() const { return birth_date; }
        // телефонный номер студента
        inline const std::string getPhone() const { return phone_number; }
        // страна рождения студента
        inline const std::string getCountry() const { return country; }
        // город рождения студента
        inline const std::string getCity() const { return city; }
        // названия учебного заведения
        inline const std::string getInstitutName() const { return institution_name; }
        // страна расположения учебного заведения
        inline const std::string getInstitutCountry() const { return institution_country; }
        // город расположения учебного заведения
        inline const std::string getInstitutCity() const { return institution_city; }
        // номер группы
        inline const std::string getGroupNumber() const { return group_number; }
};

#endif // STUDENT_H
