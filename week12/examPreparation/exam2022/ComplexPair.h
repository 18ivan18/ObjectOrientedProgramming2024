#ifndef COMPLEX_PAIR_H
#define COMPLEX_PAIR_H
#include <string>
#include "InterpolationPair.h"
#include "TagPair.h"

class ComplexPair : public TagPair, public InterpolationPair
{
private:
    void validate() override;

public:
    ComplexPair(const std::string &key, const std::string &value);
    void printValue();
    SimplePair *clone() override;
};

#endif