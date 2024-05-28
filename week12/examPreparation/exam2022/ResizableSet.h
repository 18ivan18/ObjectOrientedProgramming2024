#ifndef RESIZEABLE_SET_H
#define RESIZEABLE_SET_H
#include <stdexcept>

const int defaultCapacity = 8;

template <typename T>
bool defaultComparator(T first, T second)
{
    return first == second;
}

template <typename T>
class ResizableSet
{
protected:
    int size, capacity;
    T *data;

    int find(const T &elem);
    void resize(int newCapacity);
    bool (*comp)(T, T);

public:
    ResizableSet(int capacity = defaultCapacity);
    ResizableSet(bool (*comp)(T, T));
    ResizableSet(const ResizableSet &other) = delete;
    ResizableSet &operator=(const ResizableSet &other) = delete;
    ~ResizableSet();

    bool empty();

    bool operator[](const T &el);

    void add(const T &el);
    bool remove(const T &el);

    T *getData() const;
    int getSize() const;
};

template <typename T>
bool ResizableSet<T>::empty()
{
    return size == 0;
}

template <typename T>
T *ResizableSet<T>::getData() const
{
    return data;
}

template <typename T>
int ResizableSet<T>::getSize() const
{
    return size;
}

template <typename T>
bool ResizableSet<T>::operator[](const T &el)
{
    return find(el) != -1;
}

template <typename T>
int ResizableSet<T>::find(const T &elem)
{
    for (size_t i = 0; i < size; i++)
    {
        if (this->comp(data[i], elem))
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void ResizableSet<T>::resize(int newCapacity)
{
    capacity = newCapacity;
    T *data = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = this->data[i];
    }
    delete[] this->data;
    this->data = data;
}

template <typename T>
ResizableSet<T>::ResizableSet(int capacity) : capacity{capacity}, size{0}, data{new T[capacity]}, comp{defaultComparator<T>} {}

template <typename T>
ResizableSet<T>::ResizableSet(bool (*comp)(T, T)) : capacity{defaultCapacity}, size{0}, data{new T[capacity]}, comp{comp}
{
}

template <typename T>
ResizableSet<T>::~ResizableSet()
{
    delete[] data;
}

template <typename T>
void ResizableSet<T>::add(const T &el)
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }

    if (!empty() && find(el) != -1)
    {
        throw std::runtime_error("Element already in the set.\n");
    }
    data[size++] = el;
}

template <typename T>
bool ResizableSet<T>::remove(const T &el)
{
    int idx = find(el);
    if (idx == -1)
    {
        return false;
    }
    for (size_t i = idx; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;

    return true;
}

#endif