#include "NaturalNumbers.h"

#include <cstring>

const int BUFFER_SIZE = 256;
const char *DEFAULT_NAME = "Empty Set";

NaturalNumbers::NaturalNumbers() : size{0}, numbers{nullptr}, name{new char[strlen(DEFAULT_NAME) + 1]}
{
    strcpy(name, DEFAULT_NAME);
}

NaturalNumbers::NaturalNumbers(unsigned *numbers, int size, const char *name) : size{size}, numbers{nullptr}, name{new char[strlen(name) + 1]}
{
    strcpy(this->name, name);
    this->size = findNumberOfUniqueItems(numbers, size);
    this->numbers = new unsigned[this->size];
    copyItems(numbers, size);
}

NaturalNumbers::NaturalNumbers(const NaturalNumbers &other) : NaturalNumbers(other.numbers, other.size, other.name) {}
NaturalNumbers &NaturalNumbers::operator=(const NaturalNumbers &rhs)
{
    if (this != &rhs)
    {
        deletePrivateData();
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        size = rhs.size;
        numbers = new unsigned[size];
        for (size_t i = 0; i < size; i++)
        {
            numbers[i] = rhs.numbers[i];
        }
    }
    return *this;
}

NaturalNumbers NaturalNumbers::operator+(const NaturalNumbers &other) const
{
    int newSetSize = size;
    for (size_t i = 0; i < other.size; i++)
    {
        if (!(*this)[other.numbers[i]])
        {
            newSetSize++;
        }
    }

    unsigned *newSet = new unsigned[newSetSize];
    size_t index = 0;
    for (size_t i = 0; i < size; i++)
    {
        newSet[index++] = numbers[i];
    }

    for (size_t i = 0; i < other.size; i++)
    {
        if (!(*this)[other.numbers[i]])
        {
            newSet[index++] = other.numbers[i];
        }
    }
    char *newName = mergeTwoNames(name, other.name);

    NaturalNumbers result(newSet, newSetSize, newName);
    delete[] newName;
    delete[] newSet;

    return result;
}

char *NaturalNumbers::mergeTwoNames(const char *name1, const char *name2) const
{
    int newNameSize = strlen("Union of ") + strlen(name1) + strlen(" and ") + strlen(name2);
    char *newName = new char[newNameSize + 1];
    strcpy(newName, "Union of ");
    strcpy(newName + strlen("Union of "), name1);
    strcpy(newName + strlen("Union of ") + strlen(name1), " and ");
    strcpy(newName + strlen("Union of ") + strlen(name1) + strlen(" and "), name2);

    return newName;
}

NaturalNumbers &NaturalNumbers::operator+=(const NaturalNumbers &rhs)
{
    *this = *this + rhs;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const NaturalNumbers &nn)
{
    os << nn.name << " with " << nn.size << " items\n";
    for (size_t i = 0; i < nn.size; i++)
    {
        os << nn.numbers[i] << " ";
    }
    os << '\n';

    return os;
}

std::istream &operator>>(std::istream &is, NaturalNumbers &nn)
{
    nn.deletePrivateData();
    int size;
    is >> size;
    unsigned *set = new unsigned[size];
    for (size_t i = 0; i < size; i++)
    {
        is >> set[i];
    }
    is.ignore();
    char name[BUFFER_SIZE];
    is.getline(name, BUFFER_SIZE);

    nn.name = new char[strlen(name) + 1];
    strcpy(nn.name, name);
    nn.size = nn.findNumberOfUniqueItems(set, size);
    nn.numbers = new unsigned[nn.size];
    nn.copyItems(set, size);

    return is;
}

bool NaturalNumbers::operator[](unsigned number) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (numbers[i] == number)
        {
            return true;
        }
    }
    return false;
}
NaturalNumbers::~NaturalNumbers()
{
    deletePrivateData();
}

int NaturalNumbers::findNumberOfUniqueItems(unsigned *numbers, int size)
{
    int unique = 1;

    for (int i = 1; i < size; i++)
    {
        int j = 0;
        for (j = 0; j < i; j++)
        {
            if (numbers[i] == numbers[j])
            {
                std::cerr << numbers[i] << " is not unique\n";
                break;
            }
        }

        if (i == j)
        {
            unique++;
        }
    }
    return unique;

    // std::sort(numbers, numbers + size);

    // int unique = 0;
    // for (int i = 0; i < n; i++)
    // {

    //     while (i < n - 1 && numbers[i] == numbers[i + 1])
    //     {
    //         i++;
    //     }

    //     unique++;
    // }

    // return unique;
}
void NaturalNumbers::copyItems(unsigned *numbers, int size)
{
    int index = 0;
    this->numbers[index++] = numbers[0];
    for (int i = 1; i < size; i++)
    {
        int j = 0;
        for (j = 0; j < i; j++)
        {
            if (numbers[i] == numbers[j])
            {
                break;
            }
        }

        if (i == j)
        {
            this->numbers[index++] = numbers[i];
        }
    }
}

void NaturalNumbers::deletePrivateData()
{
    delete[] name;
    name = nullptr;
    delete[] numbers;
    numbers = nullptr;
}
