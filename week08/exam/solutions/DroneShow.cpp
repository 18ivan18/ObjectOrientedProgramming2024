#include "DroneShow.h"
#include <cstring>
#include <iostream>

DroneShow::DroneShow(const char *name)
{
    strcpy(this->name, name);
    for (size_t i = 0; i < MAX_DRONES; i++)
    {
        drones[i] = nullptr;
    }
}

DroneShow::DroneShow(const DroneShow &other)
{
    strcpy(this->name, other.name);
    for (size_t i = 0; i < MAX_DRONES; i++)
    {
        if (other.drones[i] != nullptr)
        {
            drones[i] = new Drone(*other.drones[i]);
            continue;
        }
        drones[i] = nullptr;
    }
}

DroneShow::DroneShow(DroneShow &&other)
{
    strcpy(this->name, other.name);
    for (size_t i = 0; i < MAX_DRONES; i++)
    {
        drones[i] = other.drones[i];
        other.drones[i] = nullptr;
    }
}

DroneShow &DroneShow::operator=(const DroneShow &rhs)
{
    if (this != &rhs)
    {
        free();

        strcpy(this->name, rhs.name);
        for (size_t i = 0; i < MAX_DRONES; i++)
        {
            if (rhs.drones[i] != nullptr)
            {
                drones[i] = new Drone(*rhs.drones[i]);
                continue;
            }

            drones[i] = nullptr;
        }
    }
    return *this;
}

DroneShow &DroneShow::operator=(DroneShow &&rhs)
{
    if (this != &rhs)
    {
        free();
        strcpy(this->name, rhs.name);
        for (size_t i = 0; i < MAX_DRONES; i++)
        {
            drones[i] = rhs.drones[i];
            rhs.drones[i] = nullptr;
        }
    }
    return *this;
}

void DroneShow::free()
{
    for (size_t i = 0; i < MAX_DRONES; i++)
    {
        delete drones[i];
        drones[i] = nullptr;
    }
}

DroneShow::~DroneShow()
{
    free();
}

bool DroneShow::isEmpty(int idx) const
{
    if (idx < 0 || idx >= MAX_DRONES)
    {
        // or throw error
        return true;
    }
    return drones[idx] == nullptr;
}

void DroneShow::play()
{
    try
    {
        while (true)
        {
            for (size_t i = 0; i < MAX_DRONES; i++)
            {
                if (!isEmpty(i))
                {
                    std::cout << drones[i]->getId() << '\n';
                    drones[i]->getPosition().print();
                }
            }

            for (size_t i = 0; i < MAX_DRONES; i++)
            {
                if (!isEmpty(i))
                {
                    drones[i]->moveWithOneStep();
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Show ended\n";
    }
}

DroneShow::DroneShow(const char *name, Drone **drones) : DroneShow(name)
{
    for (size_t i = 0; i < MAX_DRONES; i++)
    {
        if (drones[i] != nullptr)
        {
            this->drones[i] = new Drone(*drones[i]);
        }
    }
}
