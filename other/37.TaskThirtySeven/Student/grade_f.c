#include "student.h"
//
void sequential_number_assessment(char* string, const unsigned int index)
{
    const size_t size = 10;

    if(index == 0)
    {
        strcpy_s(string, size - 1, "first");
        string[strlen(string)] = '\0';
    }
    else if(index == 1)
    {
        strcpy_s(string, size - 1, "second");
        string[strlen(string)] = '\0';
    }
    else if(index == 2)
    {
        strcpy_s(string, size - 1, "third");
        string[strlen(string)] = '\0';
    }
    else if(index == 3)
    {
        strcpy_s(string, size - 1, "fourth");
        string[strlen(string)] = '\0';
    }
    else if(index == 4)
    {
        strcpy_s(string, size - 1, "fifth");
        string[strlen(string)] = '\0';
    }
    else if(index == 5)
    {
        strcpy_s(string, size - 1, "sixth");
        string[strlen(string)] = '\0';
    }
    else if(index == 6)
    {
        strcpy_s(string, size - 1, "seventh");
        string[strlen(string)] = '\0';
    }
    else if(index == 7)
    {
        strcpy_s(string, size - 1, "eigth");
        string[strlen(string)] = '\0';
    }
    else if(index == 8)
    {
        strcpy_s(string, size - 1, "ninth");
        string[strlen(string)] = '\0';
    }
    else
    {
        strcpy_s(string, size - 1, "tenth");
        string[strlen(string)] = '\0';
    }
}
//
void data_entry(struct Student* student)
{   
    const size_t length = 128;

    char string[128];

    system("cls");

    printf_s("%s", "enter the last name of the student: ");
    scanf("%s", string);
    student->surname = (char*)malloc(strlen(string) + 1);
    strcpy_s(student->surname, length - 1, string);
    student->surname[strlen(student->surname)] = '\0';
    printf_s("%s", "enter student name: ");
    scanf("%s", string);
    student->name = (char*)malloc(strlen(string) + 1);
    strcpy_s(student->name, length - 1, string);
    student->name[strlen(student->name)] = '\0';
    printf_s("%s", "enter the middle name of the student: ");
    scanf("%s", string);
    student->patronymic = (char*)malloc(strlen(string) + 1);
    strcpy_s(student->patronymic, length - 1, string);
    student->patronymic[strlen(student->patronymic)] = '\0';
}
//
void data_output(const struct Student* student)
{
    const unsigned int columns = 45;
    const unsigned int step_col = 15;

    unsigned int two_zero_three = 4;
    unsigned int grade = 0;

    size_t length = 0;
    //
    printf_s("%c", 201);
    for(size_t i = 0; i < columns + 2; ++i)
    {
        if(i == step_col || i == step_col * 2 + 1)
            printf_s("%c", 203);
        else
            printf_s("%c", 205);
    }
    //
    printf_s("%c\n", 187);
    printf_s("%c", 186);
    length = step_col - strlen(student->surname);
    for(size_t i = 0; i < length / 2; ++i)
        printf_s("%c", ' ');
    printf_s("%s", student->surname);
    if(length % 2 != 0)
        ++length;
    for(size_t i = 0; i < length / 2; ++i)
        printf_s("%c", ' ');
    printf_s("%c", 186);
    length = step_col - strlen(student->name);
    for(size_t i = 0; i < length / 2; ++i)
        printf_s("%c", ' ');
    printf_s("%s", student->name);
    if(length % 2 != 0)
        ++length;
    for(size_t i = 0; i < length / 2; ++i)
        printf_s("%c", ' ');
    printf_s("%c", 186);
    length = step_col - strlen(student->patronymic);
    for(size_t i = 0; i < length / 2; ++i)
        printf_s("%c", ' ');
    printf_s("%s", student->patronymic);
    if(length % 2 != 0)
        ++length;
    for(size_t i = 0; i < length / 2; ++i)
        printf_s("%c", ' ');
    printf_s("%c\n", 186);
    //
    printf_s("%c", 204);
    for(size_t i = 0; i < columns + 2; ++i)
    {
        if(i == step_col || i == step_col * 2 + 1)
            printf_s("%c", 202);
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
        else if(i == step_col || i == step_col * 2 + 1 || i == columns - 1)
            printf_s("%c", 202);
        else
            printf_s("%c", 205);
    }
    printf_s("%c\n", 185);
    //
    printf_s("%c", 186);
    for(size_t i = 0; i < 10; ++i)
    {
        if(i == 0)
            grade = student->grade.first;
        else if(i == 1)
            grade = student->grade.second;
        else if(i == 2)
            grade = student->grade.third;
        else if(i == 3)
            grade = student->grade.fourth;
        else if(i == 4)
            grade = student->grade.fifth;
        else if(i == 5)
            grade = student->grade.sixth;
        else if(i == 6)
            grade = student->grade.seventh;
        else if(i == 7)
            grade = student->grade.eigth;
        else if(i == 8)
            grade = student->grade.ninth;
        else
            grade = student->grade.tenth;

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
    printf_s("%c\n", 188);
}
//
void grading(struct Student* student)
{
    const size_t size = 10;

    unsigned int grade = 0;

    char index[10];

    for(size_t i = 0; i < size; ++i)
    {
        sequential_number_assessment(index, i);
        printf_s("%s%s%s", "enter student's ", index, " grade: ");
        scanf("%i", &grade);

        if(i == 0)
            student->grade.first = grade;
        else if(i == 1)
            student->grade.second = grade;
        else if(i == 2)
            student->grade.third = grade;
        else if(i == 3)
            student->grade.fourth = grade;
        else if(i == 4)
            student->grade.fifth = grade;
        else if(i == 5)
            student->grade.sixth = grade;
        else if(i == 6)
            student->grade.seventh = grade;
        else if(i == 7)
            student->grade.eigth = grade;
        else if(i == 8)
            student->grade.ninth = grade;
        else
            student->grade.tenth = grade;
    }
}
//
unsigned int average_score(struct Grade grades)
{
    unsigned int average_score = 0;
    unsigned int grade = 0;

    for(size_t i = 0; i < 10; ++i)
    {
        if(i == 0)
            grade = grades.first;
        else if(i == 1)
            grade = grades.second;
        else if(i == 2)
            grade = grades.third;
        else if(i == 3)
            grade = grades.fourth;
        else if(i == 4)
            grade = grades.fifth;
        else if(i == 5)
            grade = grades.sixth;
        else if(i == 6)
            grade = grades.seventh;
        else if(i == 7)
            grade = grades.eigth;
        else if(i == 8)
            grade = grades.ninth;
        else
            grade = grades.tenth;
        average_score += grade;
    }

    average_score /= 10;
    return average_score;
}
// освобождение памяти
void destruct(struct Student* student)
{
    free(student->name);
    free(student->surname);
    free(student->patronymic);
}
