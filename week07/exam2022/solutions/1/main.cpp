#include <iostream>
#include "NaturalNumbers.h"

int main()
{
    NaturalNumbers nn;
    std::cout << nn;
    unsigned numbers[] = {0, 1, 2, 3, 4, 1, 2, 3, 5, 6, 7, 8, 9}, sizeOfNumbers = sizeof(numbers) / sizeof(numbers[0]);
    NaturalNumbers nn1(numbers, sizeOfNumbers, "One digit numbers");
    std::cout << nn1;
    NaturalNumbers nn2 = nn1;
    std::cout << nn2;
    nn = nn2;
    std::cout << nn;

    unsigned numbers2[] = {33, 66, 99}, sizeOfNumbers2 = sizeof(numbers2) / sizeof(numbers2[0]);

    NaturalNumbers nn3(numbers2, sizeOfNumbers2, "Two digit divisible by 33");
    std::cout << nn3;
    std::cout << nn + nn3;

    unsigned numbers3[] = {42, 420, 69}, sizeOfNumbers3 = sizeof(numbers3) / sizeof(numbers3[0]);

    NaturalNumbers nn4(numbers3, sizeOfNumbers3, "Special numbers");
    nn4 += nn;
    std::cout << nn4;

    std::cout << "Is 5 a one digit number? " << std::boolalpha << nn[5] << '\n';
    std::cout << "Is 10 a one digit number? " << std::boolalpha << nn[10] << '\n';

    std::cin >> nn1;
    std::cout << nn1;
}