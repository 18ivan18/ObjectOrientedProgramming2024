#include "ComplexPair.h"
#include <iostream>

void ComplexPair::validate()
{
}

ComplexPair::ComplexPair(const std::string &key, const std::string &value) : SimplePair(key, value), InterpolationPair(key, value), TagPair(key, value)
{
}

void ComplexPair::printValue()
{
    std::cout << replaceTags(interpolate(value)) << '\n';
}

SimplePair *ComplexPair::clone()
{
    return new ComplexPair(*this);
}
