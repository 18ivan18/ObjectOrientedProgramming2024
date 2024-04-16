#ifndef POSITION_H
#define POSITION_H

#include <fstream>

struct Position
{
    double x, y;

public:
    friend std::ostream &operator<<(std::ostream &os, const Position &pos);
};

#endif