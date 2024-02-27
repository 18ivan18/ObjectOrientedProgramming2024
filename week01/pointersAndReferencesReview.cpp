#include <iostream>
#include <cassert>

void testPointersAndReferences()
{
    int x = 5, y = 6;

    int *pointer = nullptr;

    // указател към целочислената променливата x
    // за да извлечем адреса на променлива, използваме оператор &
    int *ptrX = &x;

    // извеждане на адреса на променливата...
    // стойността на променливата ptrX е адресът на променливата x
    std::cout << "Address of x: " << ptrX << std::endl;

    // извеждане на стойността на x
    // извличаме стойността, записана в адреса с оператор *
    std::cout << "\nValue of x: " << *ptrX << std::endl;

    // използваме указателя, за да променим стойността на променливата....
    *ptrX += 5;
    std::cout << "\nNew value of x: " << x << std::endl;

    // указателят може да се пренасочи към друга променлива
    ptrX = &y;
    std::cout << "\nAddress of y: " << &y << ", using pointer: " << ptrX << std::endl;

    // употреба на const

    // указател към константни данни, не можем да променим стойността на x
    // като използваме указателя ...
    const int *pointerToConstData = &x;
    // *pointerToConstData = 5;

    std::cout << "\nValue of pointerToConstData: " << pointerToConstData << std::endl;

    // но може да бъде пренасочен към друга променлива
    pointerToConstData = &y;
    std::cout << "\nNew value of pointerToConstData: " << pointerToConstData << std::endl;

    // константен указател към данни, които могат да бъдат променени
    int *const constPointerToVarData = &x;

    // указателят може да се използва за промяна на стойността на х,
    *constPointerToVarData = 5;
    std::cout << "\nNew value of x (should be 5): " << x << std::endl;

    // но не може да бъде пренасочен към друга променлива
    // constPointerToVarData = &y;

    // константен указател към константни данни
    const int *const constPointerToConstData = &x;

    // не може да се използва за промяна на данните,
    // нито да бъде пренасочен към друга променлива
    // *constPointerToConstData += 5;
    // constPointerToConstData = &y;

    // псевдоними
    // псевдонимът е друго име на съществуваща променлива,
    // трябва да бъде инициализиран веднага
    int &refToX = x;

    // не може да бъде псевдоним на друга променлива
    // записът е еквивалентен на x = y;
    refToX = y;

    // за да се декларира псевдоним към константни данни:
    const int &refToConstData = x;
    // не може да се промени стойността на x през псевдонима
    // refToConstData = 10;
}

/*
    Да се дефинира функция, която разменя стойностите на две целочислени променливи.
*/

// предаване на параметър по стойност
void swapByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// предаване на параметър по псевдоним
void swapByReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// предаване на параметър по указател
void swapByPointer(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void testSwap()
{
    int x = 5, y = 10;

    // обръщение към функцията с предаване на параметър по псевдоним
    std::cout << "Swap by Value" << std::endl;
    std::cout << "Original values x = " << x << ", y = " << y << std::endl;
    swapByValue(x, y);
    std::cout << "New values x = " << x << ", y = " << y << std::endl;

    // обръщение към функцията с предаване на параметър по псевдоним
    std::cout << "Swap by Reference" << std::endl;
    std::cout << "Original values x = " << x << ", y = " << y << std::endl;
    swapByReference(x, y);
    std::cout << "New values x = " << x << ", y = " << y << std::endl;

    // предаване на параметрите по указател
    // подаваме адресите на променливите, чиито стойности искаме да разменим
    std::cout << "Swap by Pointers" << std::endl;
    std::cout << "Original values x = " << x << ", y = " << y << std::endl;
    swapByPointer(&x, &y);
    std::cout << "New values x = " << x << ", y = " << y << std::endl;
}

int main()
{
    testPointersAndReferences();
    testSwap();
}