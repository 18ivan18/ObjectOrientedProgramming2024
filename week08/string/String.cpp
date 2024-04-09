#include "String.h"
#include <cstring>
#include <stdexcept>

void String::resize(size_t capacity)
{
    mCapacity = capacity;
    char *nString = new char[mCapacity];
    strcpy(nString, mString);
    delete[] mString;
    mString = nString;
}

String::String(const char *str) : mSize{strlen(str)}, mCapacity{mSize}, mString{new char[mSize + 1]}
{
    strcpy(mString, str);
}

String::String(const String &other) : String(other.mString)
{
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] mString;
        mSize = other.size();
        mCapacity = mSize;
        mString = new char[mSize + 1];
        strcpy(mString, other.cStr());
    }
    return *this;
}

String::~String()
{
    delete[] mString;
}

const char *String::cStr() const
{
    return mString;
}

String::operator const char *()
{
    return cStr();
}

size_t String::capacity() const
{
    return mCapacity;
}

size_t String::size() const
{
    return mSize;
}

size_t String::length() const
{
    return mSize;
}

char String::at(size_t index) const
{
    if (index >= size())
    {
        throw std::exception();
    }
    return mString[index];
}

char &String::back()
{
    return mString[strlen(mString) - 1];
}

const char &String::back() const
{
    return mString[strlen(mString) - 1];
}

char &String::front()
{
    return mString[0];
}

const char &String::front() const
{
    return mString[0];
}

String &String::operator+=(const String &str)
{
    return operator+=(str.cStr());
}

String &String::operator+=(const char *s)
{
    int sSize = strlen(s);
    if (mCapacity <= sSize + mSize + 1)
    {
        resize(sSize + mSize + 1);
    }

    for (size_t i = 0; i < sSize; i++)
    {
        mString[i + size()] = s[i];
    }
    mSize += sSize;

    mString[size() + sSize] = '\0';

    return *this;
}

String &String::operator+=(char c)
{
    this->pushBack(c);
    return *this;
}

void String::pushBack(char c)
{
    if (mCapacity == mSize)
    {
        resize(2 * mCapacity);
    }
    mString[mSize++] = c;
}
