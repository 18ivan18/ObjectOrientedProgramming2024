#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
private:
    int size, capacity;
    T *data;

public:
    Vector(int capacity);
    Vector(const Vector &);
    Vector &operator=(const Vector &);
    ~Vector();
    int size();
    int capacity();
    void add(const T &);
    const T &operator[](int);
};

#include "Vector.inl"

#endif