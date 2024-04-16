#include "Drone.h"
#include <cstring>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cassert>

void Drone::free()
{
    delete[] id;
    id = nullptr;
}

void Drone::copy(const char *id, const char *fileName, double x, double y, int positionIndex)
{
    position.x = x;
    position.y = y;
    this->positionIndex = positionIndex;
    strcpy(this->id, id);
    strcpy(this->fileName, fileName);
}

Drone::Drone(const char *id, const char *fileName, double x, double y, int positionIndex) : position{x, y}, id{new char[strlen(id) + 1]}, positionIndex{positionIndex}
{
    if (strlen(fileName) > MAX_FILE_NAME_SIZE)
    {
        throw std::invalid_argument("File name is too long");
    }
    copy(id, fileName, x, y, positionIndex);
}

Drone::Drone(const Drone &other) : Drone(other.id, other.fileName, other.position.x, other.position.y, other.positionIndex)
{
}

Drone::Drone(Drone &&other) : position{std::move(other.position)}, id{other.id}, positionIndex{other.positionIndex}
{
    strcpy(this->fileName, fileName);

    other.id = nullptr;
}

Drone &Drone::operator=(Drone &&rhs)
{
    free();
    id = std::move(rhs.id);
    position = std::move(rhs.position);
    positionIndex = std::move(rhs.positionIndex);

    strcpy(this->fileName, fileName);

    rhs.id = nullptr;

    return *this;
}

Drone &Drone::operator=(const Drone &rhs)
{
    if (this != &rhs)
    {
        free();

        id = new char[strlen(rhs.id) + 1];
        copy(rhs.id, rhs.fileName, rhs.position.x, rhs.position.y, rhs.positionIndex);
        position = rhs.position;
        positionIndex = rhs.positionIndex;
    }

    return *this;
}

Drone::~Drone()
{
    free();
}

void Drone::printPath()
{
    int numPositions;
    Position *pos = nullptr;

    getPositions(pos, numPositions);

    for (size_t i = 0; i < numPositions; i++)
    {
        std::cout << "(" << pos[i].x << ", " << pos[i].y << ")\n";
    }

    delete[] pos;
}

void Drone::getPositions(Position *&positions, int &numPositions)
{
    assert(positions == nullptr);
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs)
    {
        throw std::runtime_error("Cannot open file");
    }

    std::streampos end = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    std::streampos size = ifs.tellg() - end;
    ifs.seekg(0, std::ios::beg);

    numPositions = size / sizeof(Position);

    positions = new Position[numPositions];

    ifs.read((char *)positions, size);
    ifs.close();
}

void Drone::moveWithOneStep()
{
    int numPositions;
    Position *pos = nullptr;

    getPositions(pos, numPositions);
    if (positionIndex >= numPositions - 1)
    {
        throw std::runtime_error("Position index out of range");
    }

    position = pos[++positionIndex];
    delete[] pos;
}

Position Drone::getPosition()
{
    return position;
}

char *Drone::getId()
{
    return id;
}