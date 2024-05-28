#ifndef KNYAML_H
#define KNYAML_H
#include "SimplePair.h"
#include <vector>

class KNYAML
{
private:
    std::vector<SimplePair *> pairs;
    void free();

public:
    KNYAML(std::vector<SimplePair *> pairs);
    KNYAML(const KNYAML &other);
    KNYAML &operator=(const KNYAML &rhs);
    ~KNYAML();

    void operator[](const std::string &key);
};

#endif