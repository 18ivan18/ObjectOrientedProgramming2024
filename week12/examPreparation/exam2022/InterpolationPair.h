#ifndef INTERPOLATION_PAIR_H
#define INTERPOLATION_PAIR_H
#include "SimplePair.h"
#include <vector>
#include "TextProcessor.h"

class InterpolationPair : virtual public SimplePair
{
private:
    std::vector<TextProcessor::Tag> interpolations;
    void validate() override;
    void validateInterpolatedStringsCorrectness(const std::string &s);

    static std::string sequenceStart, sequenceEnd;

protected:
    std::string interpolate(const std::string &value);

public:
    InterpolationPair(const std::string &key, const std::string &value);
    void printValue();
    SimplePair *clone() override;
};

#endif