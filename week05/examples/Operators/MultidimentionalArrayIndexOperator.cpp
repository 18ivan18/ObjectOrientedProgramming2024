#include <iostream>

struct Pair
{
    int x, y;

    Pair(int x, int y) : x{x}, y{y}
    {
    }
};

template <typename T>
class Matrix
{
    int x, y;
    T **data;

public:
    Matrix(int x, int y, int initialData = T()) : x{x}, y{y}, data{new T *[x]}
    {
        for (size_t i = 0; i < x; i++)
        {
            data[i] = new int[y]{initialData};
        }
    }
    int &operator[](const Pair idx)
    {
        return data[idx.x][idx.y];
    }
};

int main()
{
    Matrix<int> m(3, 3);
    m[{0, 0}] = 5;
    std::cout << m[{0, 0}] << "\n";
}