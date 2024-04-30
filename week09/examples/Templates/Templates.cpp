#include <iostream>
#include <cstring>
#include <typeinfo>

// function
template <typename T>
T getMax(T first, T second)
{
    std::cout << "Calling template getMax" << std::endl;
    T result;
    result = (first > second) ? first : second;
    return result;
}

char *getMax(char *first, char *second)
{
    std::cout << "Calling getMax for char*" << std::endl;
    char *result;
    result = (strcmp(first, second) > 0) ? first : second;
    return result;
}

// class tempalte
template <typename T>
class Pair
{
    T values[2];

public:
    Pair(T first = T(), T second = T());
    T getMax();
    bool operator>(const Pair &other);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Pair<U> &);
};

template <typename U>
std::ostream &operator<<(std::ostream &os, const Pair<U> &p)
{
    os << p.values[0] << " " << p.values[1];
    return os;
}

// be careful, syntax...
template <typename T>
Pair<T>::Pair(T first, T second)
{
    values[0] = first;
    values[1] = second;
}

template <typename T>
T Pair<T>::getMax()
{
    T retVal;
    T first = values[0], second = values[1];
    retVal = first > second ? first : second;
    return retVal;
}

template <typename T>
bool Pair<T>::operator>(const Pair &other)
{
    return values[0] > other.values[0] && values[1] > other.values[1];
}

// class template:
template <typename T>
class Container
{
    T element;

public:
    Container(T arg) { element = arg; }
    T increase() { return ++element; }
};

// class template specialization:
template <>
class Container<char>
{
    char element;

public:
    Container(char arg) { element = arg; }
    char uppercase()
    {
        if ((element >= 'a') && (element <= 'z'))
            element += 'A' - 'a';
        return element;
    }
};

// sequence template
template <class T, int N>
class Sequnce
{
    T memblock[N];

public:
    void setMember(int x, T value);
    T getMember(int x);
};

template <class T, int N>
void Sequnce<T, N>::setMember(int x, T value)
{
    memblock[x] = value;
}

template <class T, int N>
T Sequnce<T, N>::getMember(int x)
{
    return memblock[x];
}

int main()
{
    int i = 5, j = 6, k;
    long l = 10, m = 5, n;
    // explicit
    k = getMax<int>(i, j);
    // implicit
    n = getMax(l, m);
    char *t = "abcd", *s = "abce";
    char *u = getMax(t, s);
    std::cout << k << std::endl;
    std::cout << n << std::endl;
    std::cout << u << std::endl;

    Pair<int> obj1(42, 69);
    std::cout << obj1.getMax() << std::endl;
    Pair<int> obj2(43, 70);
    std::cout << obj2.getMax() << std::endl;
    std::cout << getMax(obj1, obj2) << std::endl;

    Container<int> intContainer(7);
    Container<char> charContainer('i');
    std::cout << intContainer.increase() << std::endl;
    // std::cout << charContainer.increase() << std::endl; there is no increase here
    std::cout << charContainer.uppercase() << std::endl;

    Sequnce<int, 5> intSequence;
    Sequnce<float, 5> floatSequnce;
    intSequence.setMember(0, 100);
    floatSequnce.setMember(3, 3.1416f);
    std::cout << intSequence.getMember(0) << std::endl;
    std::cout << floatSequnce.getMember(3) << std::endl;
}