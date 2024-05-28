#ifndef SIMPLE_PAIR_H
#define SIMPLE_PAIR_H
#include <string>

class SimplePair
{
protected:
    std::string key, value;
    virtual void validate();

public:
    SimplePair(const std::string &key, const std::string &value);
    virtual void printValue();
    virtual SimplePair *clone();
    bool operator==(const SimplePair &sp);
    bool operator==(const std::string &key);
    virtual ~SimplePair();
};

#endif