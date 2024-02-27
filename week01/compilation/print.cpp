#include <iostream> // std::cout, std::endl
#include "sum.h"    // sumI, sumF

void printSum(int a, int b)
{
    std::cout << a << " + " << b << " = " << sumI(a, b) << std::endl;
}

void printSum(float a, float b)
{
    std::cout << a << " + " << b << " = " << sumF(a, b) << std::endl;
}