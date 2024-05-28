#ifndef KNYAML_SPEC_H
#define KNYAML_SPEC_H
#include "SimplePair.h"
#include "ResizableSet.h"
#include <vector>

template <typename T>
bool comparePtr(T *first, T *second)
{
    return *first == *second;
}

class KNYAMLSpec
{
private:
    ResizableSet<SimplePair *> pairs;
    void free();

public:
    KNYAMLSpec(std::vector<SimplePair *> pairs);
    KNYAMLSpec(const KNYAMLSpec &other);
    KNYAMLSpec &operator=(const KNYAMLSpec &rhs);
    ~KNYAMLSpec();

    void operator[](const std::string &key);
};

#endif