#include "Drone.h"
#include <fstream>
#include <iostream>

void test1()
{
    std::ofstream ofs("d1.dat", std::ios::binary);
    if (!ofs)
    {
        throw std::runtime_error("Cannot open d1.dat");
    }
    Position pos[] = {{0, 0}, {1, 2}, {3, 4}, {5, 6}, {7, 8}};
    ofs.write((const char *)&pos, sizeof(pos));

    ofs.close();

    Drone d1{"d1", "d1.dat", 0, 0};

    d1.printPath();
    d1.getPosition().print();
    d1.moveWithOneStep();
    d1.getPosition().print();
}

void test2()
{

    std::ifstream ifs("dronesPath.txt");
    if (!ifs)
    {
        throw std::runtime_error("Cannot open d1.dat");
    }

    char droneId[] = "d0";
    std::ofstream ofs(droneId);
    // check if file was created

    Position pos;
    Position positions;
    int droneId = 0;
    while (ifs >> pos.x >> pos.y)
    {
        pos.print();

        if (ifs.peek() == '\n')
        {
            droneId++;
            std::cout << '\n';
        }
    }
    std::cout << droneId;

    ifs.close();
}

int main()
{
    // test1();
    test2();
}