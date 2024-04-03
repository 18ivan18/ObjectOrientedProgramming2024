#include <iostream>
#include <fstream>
#include "Book.h"

void saveBooksToBinaryFile(const Book *books, int size, const char *fileName = "library.dat")
{
    if (!books)
    {
        return;
    }
    std::ofstream os(fileName, std::ios::binary);
    os.write((char *)books, size * sizeof(Book));
    os.close();
}

void readBooksFromBinaryFile(Book *&books, int &size, const char *fileName = "library.dat")
{
    std::ifstream is(fileName, std::ios::binary);
    is.seekg(0, std::ios::end);
    size = is.tellg() / sizeof(Book);
    books = new Book[size];
    is.seekg(0, std::ios::beg);
    is.read((char *)books, size * sizeof(Book));
    is.close();
}

int main()
{
    Book books[] = {Book("Harry Potter", "J. K. Rowling", 1000), Book("Harry Potter2", "J. K. Rowling", 2000)};
    saveBooksToBinaryFile(books, sizeof(books) / sizeof(books[0]));

    int size = 0;
    Book *booksReadFromFile = nullptr;

    readBooksFromBinaryFile(booksReadFromFile, size);

    std::ofstream popular("popular.txt");

    for (size_t i = 0; i < size; i++)
    {
        if (booksReadFromFile[i].getCirculation() >= 1000)
        {
            popular << booksReadFromFile[i];
        }
    }
    popular.close();

    delete[] booksReadFromFile;
}