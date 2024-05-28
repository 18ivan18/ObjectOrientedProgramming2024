#include "SimplePair.h"
#include <iostream>

void SimplePair::validate()
{
    if (!islower(key.front()))
    {
        throw std::runtime_error("Simple Pair must begin with small letter");
    }
    for (size_t i = 1; i < key.size(); i++)
    {
        if (!islower(key[i]) && key[i] != '_')
        {
            throw std::runtime_error("Simple Pair must contain only small letters and underscore");
        }
    }
}

SimplePair::SimplePair(const std::string &key, const std::string &value) : key{key}, value{value}
{
    validate();
}

SimplePair *SimplePair::clone()
{
    return new SimplePair(*this);
}

void SimplePair::printValue()
{
    std::cout << value << '\n';
}

bool SimplePair::operator==(const SimplePair &sp)
{
    return key == sp.key;
}

bool SimplePair::operator==(const std::string &key)
{
    return this->key == key;
}

SimplePair::~SimplePair()
{
}
