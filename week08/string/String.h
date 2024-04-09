#ifndef STRING_H
#define STRING_H

#include <cstddef>

class String
{
private:
    size_t mSize, mCapacity;
    char *mString;

    void resize(size_t);

public:
    String(const char *str = "");
    String(const String &other);
    String &operator=(const String &other);
    ~String();

    size_t capacity() const;
    size_t size() const;
    size_t length() const;
    char at(size_t) const;

    char &back();
    const char &back() const;

    char &front();
    const char &front() const;

    String &operator+=(const String &str);
    String &operator+=(const char *s);
    String &operator+=(char c);

    // String &operator+(const String &rhs);
    // String &operator+(int);

    // friend String &operator+(int, const String &);

    // String &append(const String &str);
    // String &append(const String &str, size_t subpos, size_t sublen);
    // String &append(const char *s);
    // String &append(const char *s, size_t n);
    // String &append(size_t n, char c);

    void pushBack(char);

    // String &insert(size_t pos, const String &str);
    // String &insert(size_t pos, const String &str, size_t subpos, size_t sublen);
    // String &insert(size_t pos, const char *s);
    // String &insert(size_t pos, const char *s, size_t n);

    // String &erase(size_t pos, size_t len);

    const char *cStr() const;
    operator const char *();
};

#endif