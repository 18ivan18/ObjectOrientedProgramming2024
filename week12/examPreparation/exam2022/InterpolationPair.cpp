#include "InterpolationPair.h"
#include <iostream>

std::string InterpolationPair::sequenceStart = "%{", InterpolationPair::sequenceEnd = "}";

void InterpolationPair::validate()
{
    interpolations = TextProcessor(sequenceStart, sequenceEnd).getAllTags(value);

    if (interpolations.empty())
    {
        throw std::runtime_error("Interpolation Pair must contain atleast one interpolation string.\n");
    }

    for (size_t i = 0; i < interpolations.size(); i++)
    {
        validateInterpolatedStringsCorrectness(interpolations[i].tagString);
        for (size_t j = 0; j < interpolations.size(); j++)
        {
            if (i != j && interpolations[i].tagString == interpolations[j].tagString)
            {
                throw std::runtime_error("Interpoltaion strings must be unique.\n");
            }
        }
    }
}

void InterpolationPair::validateInterpolatedStringsCorrectness(const std::string &s)
{
    if (s.size() == sequenceStart.size())
    {
        throw std::runtime_error("Interpolation strings cannot be empty.\n");
    }
    for (size_t i = sequenceStart.size(); i < s.size(); i++)
    {
        if (!islower(s[i]))
        {
            throw std::runtime_error("Interpolation strings must contain only small letters.\n");
        }
    }
}

InterpolationPair::InterpolationPair(const std::string &key, const std::string &value) : SimplePair(key, value)
{
    validate();
}

std::string InterpolationPair::interpolate(const std::string &value)
{
    std::string output;
    std::vector<char[100]> replacements(interpolations.size());
    for (int i = 0; i < interpolations.size(); i++)
    {
        std::cout << interpolations[i].tagString.c_str() + sequenceStart.size() << ": ";
        std::cin.getline(replacements[i], 100);
    }
    int interpolationIndex = 0;
    bool print = true;
    for (auto &&i : value)
    {
        if (i == sequenceStart.front())
        {
            print = false;
            output += replacements[interpolationIndex++];
        }
        if (print)
        {
            output += i;
        }
        if (i == sequenceEnd.front())
        {
            print = true;
        }
    }
    return output;
}

void InterpolationPair::printValue()
{
    std::cout << interpolate(value) << '\n';
}

SimplePair *InterpolationPair::clone()
{
    return new InterpolationPair(*this);
}
