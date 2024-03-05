#include "Group.h"

int main()
{
    Group g = initGroupFromStdIn();
    scolarship(g, 5.50f);
    std::cout << g.avgGrade << '\n';
    deleteGroup(g);
}