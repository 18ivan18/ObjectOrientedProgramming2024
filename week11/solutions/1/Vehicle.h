#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

class Vehicle
{
private:
    std::string regnum;

public:
    Vehicle(const std::string &regnum);
    const std::string &getRegnum();
    virtual double getParkingPrice() = 0;
    virtual Vehicle *clone() = 0;
    virtual ~Vehicle();
};

#endif