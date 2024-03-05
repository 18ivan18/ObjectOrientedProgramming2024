#include "Student.h"

int main()
{
    Student s = initStudent("81631", 4, 6.00);
    printStudent(s);
    deleteStudent(s);

    Student s1 = initStudent("81631", 5, 6.00);
    // Student s1 = initStudent("8163f", 4, 6.00);
    // Student s1 = initStudent("816313", 4, 6.00);
}