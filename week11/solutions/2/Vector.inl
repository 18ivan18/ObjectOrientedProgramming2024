#include "Vector.h"
template <typename T>
Vector<T>::Vector(int capacity) : size(0), capacity(capacity), data{new T[capacity]}
{
}

template <typename T>
Vector<T>::Vector(const Vector &v) : size(v.size), capacity(v.capacity), data{new T[capacity]}
{
    for (size_t i = 0; i < size; i++)
    {
        data[i] = v.data[i];
    }
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &rhs)
{
    if (this != &rhs)
    {
        delete[] data;
        size = rhs.size;
        capacity = rhs.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = v.data[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <typename T>
int Vector<T>::size()
{
    return size;
}

template <typename T>
int Vector<T>::capacity()
{
    return capacity;
}

template <typename T>
void Vector<T>::add(const T &elem)
{
    if (size < capacity)
    {
        data[size++] = elem;
    }
}

template <typename T>
const T &Vector<T>::operator[](int i)
{
    if (i >= 0 && i < capacity)
    {
        return data[i];
    }
    throw "error";
}