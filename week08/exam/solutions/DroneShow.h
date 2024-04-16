#ifndef DRONE_SHOW_H
#define DRONE_SHOW_H

#include "Drone.h"

const int MAX_NAME_SIZE = 127;
const int MAX_DRONES = 1024;

class DroneShow
{
    char name[MAX_NAME_SIZE + 1];
    Drone *drones[MAX_DRONES];

    void free();

public:
    DroneShow(const char *name);
    DroneShow(const char *name, Drone **drones);
    DroneShow(const DroneShow &other);
    DroneShow(DroneShow &&other);

    DroneShow &operator=(const DroneShow &rhs);
    DroneShow &operator=(DroneShow &&rhs);

    ~DroneShow();

    bool isEmpty(int idx) const;
    void play();
};

#endif