#ifndef NATURAL_NUBERS_H
#define NATURAL_NUBERS_H

#include <iostream>

class NaturalNumbers
{
private:
    int size;
    unsigned *numbers;
    char *name;

    int findNumberOfUniqueItems(unsigned *, int);
    void copyItems(unsigned *, int);
    void deletePrivateData();
    char *mergeTwoNames(const char *, const char *) const;

public:
    NaturalNumbers();
    NaturalNumbers(unsigned *numbers, int size, const char *name);
    NaturalNumbers(const NaturalNumbers &);
    NaturalNumbers &operator=(const NaturalNumbers &);

    NaturalNumbers operator+(const NaturalNumbers &) const;
    NaturalNumbers &operator+=(const NaturalNumbers &);

    friend std::ostream &operator<<(std::ostream &os, const NaturalNumbers &);
    friend std::istream &operator>>(std::istream &os, NaturalNumbers &);

    bool operator[](unsigned number) const;
    ~NaturalNumbers();
};

#endif