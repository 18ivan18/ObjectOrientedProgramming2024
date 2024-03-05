#ifndef GROUP
#define GROUP

#include "Student.h"

struct Group
{
    int numberOfStudentsInGroup;
    Student *students;
    float avgGrade;
};

Group initGroupFromStdIn()
{
    Group g;
    std::cin >> g.numberOfStudentsInGroup;
    g.students = new Student[g.numberOfStudentsInGroup];
    char fnBuffer[FN_DIGITS + 1];
    for (size_t i = 0; i < g.numberOfStudentsInGroup; i++)
    {
        std::cout << "Enter Fn:\n";
        std::cin.ignore();
        std::cin.getline(fnBuffer, FN_DIGITS + 1);
        std::cout << "Enter course:\n";
        int c;
        std::cin >> c;
        std::cout << "Enter avgerage grade:\n";
        float grade;
        std::cin >> grade;
        g.avgGrade += grade;
        g.students[i] = initStudent(fnBuffer, c, grade);
    }
    g.avgGrade /= g.numberOfStudentsInGroup;

    return g;
}

void deleteGroup(const Group &g)
{
    for (size_t i = 0; i < g.numberOfStudentsInGroup; i++)
    {
        deleteStudent(g.students[i]);
    }

    delete[] g.students;
}

void scolarship(const Group &g, float grade)
{
    for (size_t i = 0; i < g.numberOfStudentsInGroup; i++)
    {
        if (g.students[i].averageGrade >= grade)
        {
            printStudent(g.students[i]);
        }
    }
}

#endif