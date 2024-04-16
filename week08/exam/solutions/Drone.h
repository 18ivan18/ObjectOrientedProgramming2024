#ifndef DRONE_H
#define DRONE_H

#include "Position.h"

const int MAX_FILE_NAME_SIZE = 63;

class Drone
{
private:
    char *id;
    Position position;
    int positionIndex;
    char fileName[MAX_FILE_NAME_SIZE + 1];

    void free();
    void copy(const char *id, const char *fileName, double x, double y, int positionIndex);

    void getPositions(Position *&positions, int &numPositions);

public:
    Drone(const char *id, const char *fileName, double x, double y, int positionIndex = 0);
    Drone(const Drone &);
    Drone(Drone &&);
    Drone &operator=(Drone &&);
    Drone &operator=(const Drone &);

    void printPath();
    void moveWithOneStep();

    Position getPosition();
    char *getId();

    ~Drone();
};

#endif