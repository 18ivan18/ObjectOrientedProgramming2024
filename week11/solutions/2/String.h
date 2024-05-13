#ifndef STRING_H
#define STRING_H

class String
{
private:
    char *cStr;

public:
    String(const char *);
    String(const String &);
    String &operator=(const String &);

    operator const char *();

    ~String();
};

#endif