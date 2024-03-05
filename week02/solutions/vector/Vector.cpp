#include "Vector.h"
#include <iostream>
#include <cassert>

void allocateMemory(int *&array, size_t capacity)
{
    assert(array == nullptr);

    array = new int[capacity];
}

void freeMemory(int *&array, size_t &size, size_t &capacity)
{
    assert(array != nullptr);

    delete[] array;
    array = nullptr;
    size = 0;
    capacity = 0;
}

bool reallocateMemory(int *&array, size_t size, size_t newCapacity)
{
    assert(array != nullptr);

    int *tempArray = new (std::nothrow) int[newCapacity];

    if (tempArray == nullptr)
    {
        return false;
    }

    for (size_t i = 0; i < size; i++)
    {
        tempArray[i] = array[i];
    }

    delete[] array;
    array = tempArray;
    return true;
}

bool resize(int *&array, size_t size, size_t &capacity)
{
    assert(array != nullptr);

    if (size < capacity)
    {
        return true;
    }
    capacity = capacity * 2;
    return reallocateMemory(array, size, capacity);
}

bool addElement(int *&array, size_t &size, size_t &capacity, int newElem)
{
    assert(array != nullptr);

    if (size == capacity)
    {
        if (!resize(array, size, capacity))
        {
            return false;
        }
    }
    array[size++] = newElem;
    return true;
}

bool addElement(int *&array, size_t &size, size_t &capacity, int newElem, size_t position)
{
    assert(array != nullptr);

    if (position > size)
    {
        return false;
    }
    if (position == size)
    {
        return addElement(array, size, capacity, newElem);
    }

    if (size == capacity)
    {
        if (!resize(array, size, capacity))
        {
            return false;
        }
    }

    for (size_t i = size; i > position; i--)
    {
        array[i] = array[i - 1];
    }

    array[position] = newElem;
    size++;
    return true;
}

void print(const int *array, size_t size, size_t capacity)
{
    assert(array != nullptr);

    std::cout << "Array contents: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

bool removeElement(int *&array, size_t &size, size_t &capacity, size_t position)
{
    assert(array != nullptr);

    if (position >= size)
    {
        return false;
    }
    for (size_t i = position; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }

    size--;

    if (size * 4 < capacity)
    {
        size_t newCapacity = capacity / 2;
        if (!reallocateMemory(array, size, newCapacity))
        {
            return false;
        }
        capacity = newCapacity;
    }

    return true;
}