#include "KNYAML.h"
#include <iostream>

KNYAML::KNYAML(std::vector<SimplePair *> pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        for (size_t j = i + 1; j < pairs.size(); j++)
        {
            if (pairs[i] == pairs[j])
            {
                throw std::runtime_error("All values must have unique keys.");
            }
        }
        this->pairs.push_back(pairs[i]->clone());
    }
}

KNYAML::KNYAML(const KNYAML &other) : KNYAML(other.pairs) {}

KNYAML &KNYAML::operator=(const KNYAML &rhs)
{
    if (this != &rhs)
    {
        free();
        for (size_t i = 0; i < pairs.size(); i++)
        {
            this->pairs.push_back(pairs[i]->clone());
        }
    }
    return *this;
}

void KNYAML::free()
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        delete pairs[i];
    }

    pairs.clear();
}

KNYAML::~KNYAML()
{
    free();
}

void KNYAML::operator[](const std::string &key)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (*pairs[i] == key)
        {
            pairs[i]->printValue();
        }
    }
}