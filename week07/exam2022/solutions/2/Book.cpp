#include "Book.h"

#include <cstring>
Book::Book(const char *title, const char *authorName, unsigned circulation) : circulation{circulation}
{
    strcpy(this->title, title);
    strcpy(this->authorName, authorName);
}
Book::Book(const Book &other) : Book(other.title, other.authorName, other.circulation) {}
Book &Book::operator=(const Book &rhs)
{
    if (this != &rhs)
    {
        strcpy(title, rhs.title);
        strcpy(authorName, rhs.authorName);

        circulation = rhs.circulation;
    }
    return *this;
}

unsigned Book::getCirculation()
{
    return circulation;
}

std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << book.title << ", " << book.authorName << ", " << book.circulation << '\n';
    return os;
}
