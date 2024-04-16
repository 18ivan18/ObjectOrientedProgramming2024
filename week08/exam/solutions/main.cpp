#include "Drone.h"
#include "DroneShow.h"
#include <fstream>
#include <iostream>

void writeDronePositionToFile(char *fileName, const Position *pos, int numberOfPositions)
{
    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs)
    {
        throw std::runtime_error("Cannot open");
    }
    ofs.write((const char *)pos, numberOfPositions * sizeof(Position));

    ofs.close();
}

void test1()
{
    char name[] = "d1.dat";
    Position pos[] = {{0, 0}, {1, 2}, {3, 4}, {5, 6}, {7, 8}};
    writeDronePositionToFile(name, pos, sizeof(pos) / sizeof(Position));

    Drone d1{"d1", name, pos[0].x, pos[0].y};

    d1.printPath();
    std::cout << '\n';
    std::cout << d1.getPosition();
    d1.moveWithOneStep();
    std::cout << d1.getPosition();
}

void test2()
{

    std::ifstream ifs("dronesPath.txt");
    if (!ifs)
    {
        throw std::runtime_error("Cannot open dronesPath.txt");
    }

    Position pos;
    int numberOfPositions = 0, numberOfLines = 1;
    while (ifs >> pos.x >> pos.y)
    {
        numberOfPositions++;
        if (ifs.peek() == '\n')
        {
            numberOfPositions = 0;
            numberOfLines++;
        }
    }

    if (numberOfLines > MAX_DRONES)
    {
        throw std::runtime_error("Too many drones");
    }

    Position *positions = new Position[numberOfPositions];
    Drone *drones[MAX_DRONES] = {nullptr};
    int droneIdx = 0;
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    numberOfPositions = 0;

    while (ifs >> pos.x >> pos.y)
    {
        positions[numberOfPositions++] = pos;
        if (ifs.peek() == '\n' or ifs.peek() == EOF)
        {
            char droneName[1024];
            std::cout << "Enter name of the drone " << droneIdx + 1 << std::endl;
            std::cin.getline(droneName, 1024);

            char droneFileName[1024];
            std::cout << "Enter name for drone file " << droneIdx + 1 << std::endl;
            std::cin.getline(droneFileName, 1024);

            writeDronePositionToFile(droneFileName, positions, numberOfPositions);
            drones[droneIdx] = new Drone(droneName, droneFileName, positions[0].x, positions[0].y);
            droneIdx++;
            numberOfPositions = 0;
        }
    }

    char droneShowName[MAX_NAME_SIZE + 1];
    std::cout << "Enter name of the drone show" << std::endl;
    std::cin.getline(droneShowName, MAX_NAME_SIZE);

    DroneShow ds((char *)droneShowName, drones);
    ds.play();

    delete[] positions;
    for (size_t i = 0; i < numberOfLines; i++)
    {
        delete drones[i];
    }

    ifs.close();
}

int main()
{
    // test1();
    test2();
}