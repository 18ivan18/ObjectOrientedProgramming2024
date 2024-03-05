#include "Group.h"

template <typename T>
void swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Student *arr, int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].averageGrade < arr[j + 1].averageGrade)
            {
                swap(arr + j, arr + j + 1);
                swapped = true;
            }
        }
        // optimization: The above function always runs O(n^2) time even if the array is sorted.
        if (!swapped)
        {
            break;
        }
    }
}

void scolarshipSorted(const Group &g, float grade)
{
    int size = g.numberOfStudentsInGroup;
    Student *sts = new Student[size];
    for (size_t i = 0; i < size; i++)
    {
        sts[i] = initStudent(g.students[i].fn, g.students[i].course, g.students[i].averageGrade);
    }

    bubbleSort(sts, size);

    for (size_t i = 0; i < size; i++)
    {
        if (sts[i].averageGrade >= grade)
        {
            std::cout << sts[i].fn << " - " << sts[i].averageGrade << '\n';
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        deleteStudent(sts[i]);
    }
    delete[] sts;
}

int main()
{
    Group g = initGroupFromStdIn();
    scolarshipSorted(g, 5.50f);
    deleteGroup(g);
}