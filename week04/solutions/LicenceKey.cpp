#include "LicenceKey.h"

LicenceKey::LicenceKey() : activationsLeft{new int(MAX_ACTIVATIONS)}
{

    std::random_device rd;                                     // obtain a random number from hardware
    std::mt19937 gen(rd());                                    // seed the generator
    std::uniform_int_distribution<> distr(10000000, 99999999); // define the range
    this->key = distr(gen);
}

LicenceKey::LicenceKey(const LicenceKey &from)
{
    this->key = from.key;
    *this->activationsLeft -= 1;
}

int LicenceKey::activate() const
{
    if (*this->activationsLeft > 0)
    {
        *this->activationsLeft -= 1;
        return this->key;
    }

    return -1;
}

LicenceKey::~LicenceKey()
{
    delete activationsLeft;
}