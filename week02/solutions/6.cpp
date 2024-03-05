#include <iostream>
#include <cmath>

struct Quadratic
{

    double a, b, c, discriminant, x1, x2;
};

void findRoots(Quadratic &q)
{
    q.discriminant = q.b * q.b - 4 * q.a * q.c;

    if (q.a == 0)
    {
        return;
    }

    if (q.discriminant > 0)
    {

        q.x1 = (-q.b + sqrt(q.discriminant)) / (2 * q.a);
        q.x2 = (-q.b - sqrt(q.discriminant)) / (2 * q.a);
        return;
    }

    if (q.discriminant == 0)
    {

        q.x1 = (-q.b) / (2 * q.a);
        q.x2 = (-q.b) / (2 * q.a);
    }
}

int main()
{
}