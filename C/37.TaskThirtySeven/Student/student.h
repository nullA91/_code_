#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grade.h"

struct Student
{
    char* surname;
    char* name;
    char* patronymic;

    struct Grade grade;
};

void data_entry(struct Student* student);
void data_output(const struct Student* student);
void grading(struct Student* student);
unsigned int average_score(struct Grade grades);
void destruct(struct Student* student);

#endif // STUDENT_H
