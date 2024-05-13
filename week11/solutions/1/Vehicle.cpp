#include "Vehicle.h"

Vehicle::Vehicle(const std::string &regnum) : regnum(regnum)
{
}

const std::string &Vehicle::getRegnum()
{
    return regnum;
}

Vehicle::~Vehicle() {}
