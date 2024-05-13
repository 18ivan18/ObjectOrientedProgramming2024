#include "String.h"
#include <cstring>
String::String(const char *str) : cStr{new char[strlen(str) + 1]}
{
    strcpy(cStr, str);
}

String::String(const String &s) : String(s.cStr) {}
String &String::operator=(const String &s)
{
    if (this != &s)
    {
        delete[] cStr;
        cStr = new char[strlen(s.cStr) + 1];
        strcpy(cStr, s.cStr);
    }
    return *this;
}

String::~String()
{
    delete[] cStr;
}

String::operator const char *()
{
    return cStr;
}