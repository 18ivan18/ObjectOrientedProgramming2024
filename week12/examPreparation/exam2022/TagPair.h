#ifndef TAG_PAIR_H
#define TAG_PAIR_H
#include "SimplePair.h"
#include "TextProcessor.h"
#include <vector>
#include <iostream>

class TagPair : virtual public SimplePair
{
private:
    void validate() override;
    static std::string html, br, hr, b, bClosing;
    const static int dashSize = 20;

protected:
    std::string replaceTags(const std::string &value);

public:
    TagPair(const std::string &key, const std::string &value);
    void printValue();
    SimplePair *clone() override;
};

#endif