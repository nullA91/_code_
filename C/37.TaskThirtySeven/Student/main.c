#include "student.h"

/*
Задание 1.
Реализуйте структуру, которая хранит ФИО студента
и 10 битовых полей. Каждое поле — это оценка(сдал/не сдал).
Создайте один экземпляр этой структуры и
реализуйте для него следующие действия:
    ■ Заполнить структуру;
    ■ Вывод информации;
    ■ Печать среднего балла.
Создайте массив экземпляров этой структуры и
реализуйте для него следующие действия:
    ■ Добавить студента;
    ■ Проставить оценки студенту;
    ■ Вывод списка студентов;
    ■ Печать оценок конкретного студента;
    ■ Печать должников.
*/

int main(int arg_c, char* arg_v[])
{
    const size_t columns = 45;
    const size_t step_col = 15;

    unsigned int choise = 0;
    unsigned int counter = 0;
    unsigned int grade = 0;
    unsigned int two_zero_three = 4;
    unsigned int debtors = 0;

    struct Student students[256];

    do
    {
        system("cls");

        printf_s("\t%s\n", "menu");
        printf_s("%s\n", "1.Add student");
        printf_s("%s\n", "2.Grade a student");
        printf_s("%s\n", "3.Displaying a list of students");
        printf_s("%s\n", "4.Printing the grades of a specific student");
        printf_s("%s\n", "5.Debtor stamp");
        printf_s("%s\n", "6.Student grade point average");
        printf_s("%s\n", "0.Exit");
        printf_s("%s", "select menu item: ");
        scanf("%i", &choise);

        system("cls");

        switch(choise)
        {
            // добавление студента
            case 1:
                data_entry(&students[counter]);
                ++counter;
                break;
            // выставление оценок студенту
            case 2:
            {
                char surname[256];
                char name[256];

                if(counter)
                {
                    printf_s("%s", "enter student's surname: ");
                    scanf("%s", surname);
                    printf_s("%s", "enter student's name: ");
                    scanf("%s", name);

                    for(size_t i = 0; i < counter; ++i)
                        if( strcmp(surname, students[i].surname) == 0 && strcmp(name, students[i].name) == 0)
                            grading(&students[i]);
                }
                else
                    printf_s("%s\n", "the list of students is empty");
              }
              break;
            // вывод списка студентов
            case 3:
                if(counter)
                    for(size_t i = 0; i < counter; ++i)
                        data_output(&students[i]);
                else
                    printf_s("%s\n", "the list of students is empty");
                break;
            // вывод оценок нужного студента
            case 4:
            {
                char surname[256];
                char name[256];

                if(counter)
                {
                    printf_s("%s", "enter student's surname: ");
                    scanf("%s", surname);
                    printf_s("%s", "enter student's name: ");
                    scanf("%s", name);

                    for(size_t i = 0; i < counter; ++i)
                    {
                        if( strcmp(surname, students[i].surname) == 0 && strcmp(name, students[i].name) == 0)
                        {
                            //#####################################//
                            //************ верх строки ************//
                            //#####################################//
                            printf_s("%c", 201);
                            for(size_t i = 0; i < columns + 2; ++i)
                            {
                                if(i == step_col || i == step_col * 2 + 1)
                                    printf_s("%c", 203);
                                else
                                    printf_s("%c", 205);
                            }
                            for(size_t i = 0; i < columns + 2; ++i)
                                printf_s("%c", '\b');
                            for(size_t i = 0; i < columns + 2; ++i)
                            {
                                if(i == two_zero_three)
                                {
                                    printf_s("%c", 203);
                                    two_zero_three += 5;
                                }
                                else
                                    printf_s("%c", 205);
                            }
                            printf_s("%c\n", 187);
                            //#####################################//
                            //********** середина строки **********//
                            //#####################################//
                            printf_s("%c", 186);
                            for(size_t i = 0; i < 10; ++i)
                            {
                                if(i == 0)
                                    grade = students[i].grade.first;
                                else if(i == 1)
                                    grade = students[i].grade.second;
                                else if(i == 2)
                                    grade = students[i].grade.third;
                                else if(i == 3)
                                    grade = students[i].grade.fourth;
                                else if(i == 4)
                                    grade = students[i].grade.fifth;
                                else if(i == 5)
                                    grade = students[i].grade.sixth;
                                else if(i == 6)
                                    grade = students[i].grade.seventh;
                                else if(i == 7)
                                    grade = students[i].grade.eigth;
                                else if(i == 8)
                                    grade = students[i].grade.ninth;
                                else
                                    grade = students[i].grade.tenth;

                                printf_s("\n%i\n", grade);

                                if(i != 9)
                                {
                                    if(grade < 10)
                                        printf_s("%s", "   ");
                                    else
                                        printf_s("%s", "  ");
                                }
                                else
                                {
                                    if(grade < 10)
                                        printf_s("%c", ' ');
                                }
                                printf_s("%i%c", grade, 186);
                            }
                            printf_s("%c", '\n');
                            //#####################################//
                            //************* низ строки ************//
                            //#####################################//
                            printf_s("%c", 200);
                            for(size_t i = 0; i < columns + 2; ++i)
                                printf_s("%c", 205);
                            printf_s("%c", 188);
                            two_zero_three = 4;
                            for(size_t i = 0; i < columns + 2; ++i)
                                printf_s("%c", '\b');
                            for(size_t i = 0; i < columns + 1; ++i)
                            {
                                if(i == two_zero_three - 1)
                                {
                                    printf_s("%c", 202);
                                    two_zero_three += 5;
                                }
                                else
                                    printf_s("%c", 205);
                            }
                            printf_s("%c\n", 188);break;
                        }
                    }
                }
                else
                    printf_s("%s\n", "the list of students is empty");
                break;
            }
            // вывод должников
            case 5:
                if(counter)
                {
                    for(size_t i = 0; i < counter; ++i)
                    {
                        for(size_t j = 0; j < 10; ++j)
                        {
                            if(j == 0)
                                grade = students[i].grade.first;
                            else if(j == 1)
                                grade = students[i].grade.second;
                            else if(j == 2)
                                grade = students[i].grade.third;
                            else if(j == 3)
                                grade = students[i].grade.fourth;
                            else if(j == 4)
                                grade = students[i].grade.fifth;
                            else if(j == 5)
                                grade = students[i].grade.sixth;
                            else if(j == 6)
                                grade = students[i].grade.seventh;
                            else if(j == 7)
                                grade = students[i].grade.eigth;
                            else if(j == 8)
                                grade = students[i].grade.ninth;
                            else
                                grade = students[i].grade.tenth;

                            if(grade == 0)
                            {
                                ++debtors;
                                data_output(&students[i]);
                                break;
                            }
                        }
                    }
                    printf_s("%s%i\n", "number of debtors: ", debtors);
                    debtors = 0;
                }
                else
                    printf_s("%s\n", "the list of students is empty");
                break;
            case 6:
            {
                char surname[256];
                char name[256];
                unsigned int _average_score = 0;

                if(counter)
                {
                    printf_s("%s", "enter student's surname: ");
                    scanf("%s", surname);
                    printf_s("%s", "enter student's name: ");
                    scanf("%s", name);

                    for(size_t i = 0; i < counter; ++i)
                    {
                        if( strcmp(surname, students[i].surname) == 0 && strcmp(name, students[i].name) == 0)
                        {
                            _average_score = average_score(students[i].grade);
                        }
                    }

                    printf_s("%s%i\n", "student grade point average: ", _average_score);
                }
                else
                    printf_s("%s\n", "the list of students is empty");
                break;
            }
            default:
                printf_s("%s\n", "select the correct menu item");
                break;
        }
        printf_s("%s", "continue(1.yes/0.no): ");
        scanf("%i", &choise);

        if(choise == 0)
        {
            printf_s("%s\n", "goodbye");
        }
    }while(choise);

    if(counter)
    {
        for(size_t i = 0; i < counter; ++i)
            destruct(&students[i]);
    }
    return 0;
}
