#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <exception>
#include <cstring>
#include <iomanip>

enum Course
{
    FIRST = 1,
    SECOND,
    THIRD,
    FOURTH
};

struct Student
{
    char *fn;
    Course course;
    float averageGrade;
};

const int FN_DIGITS = 5;

bool isFnValid(const char *c)
{
    if (strlen(c) != FN_DIGITS)
    {
        return false;
    }

    for (size_t i = 0; i < FN_DIGITS; i++)
    {
        if (!isdigit(c[i]))
        {
            return false;
        }
    }

    return true;
}

Student initStudent(const char *fn, int course, float avgScore)
{
    Course c;
    switch (course)
    {
    case 1:
        c = FIRST;
        break;
    case 2:
        c = SECOND;
        break;
    case 3:
        c = THIRD;
        break;
    case 4:
        c = FOURTH;
        break;

    default:
        throw std::invalid_argument("A student can only be course 1-4.\n");
    }
    if (!isFnValid(fn))
    {
        throw std::invalid_argument("A faculty number must contain 5 digits.\n");
    }
    char *studentFn = new char[strlen(fn) + 1];
    strcpy(studentFn, fn);
    return {studentFn, c, avgScore};
}

void deleteStudent(const Student &s)
{
    delete s.fn;
}

void printStudent(const Student &s)
{
    std::cout << "Hey, my FN is " << s.fn << " and I'm a " << s.course << "th year student with average score of " << std::setprecision(2) << std::fixed << s.averageGrade << '\n';
}

#endif