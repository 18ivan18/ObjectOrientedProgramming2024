#ifndef BOOK_H
#define BOOK_H
#include <iostream>

class Book
{
private:
    char title[100], authorName[100];
    unsigned circulation;

public:
    Book(const char *title = "", const char *authorName = "", unsigned circulation = 0);
    Book(const Book &);
    Book &operator=(const Book &);

    unsigned getCirculation();

    friend std::ostream &operator<<(std::ostream &os, const Book &);
};

#endif