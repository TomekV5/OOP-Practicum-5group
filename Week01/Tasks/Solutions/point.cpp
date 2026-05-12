#include <iostream>
#include <cmath>

namespace PointNS
{
    struct Point
    {
        double x;
        double y;

        void print()
        {
            std::cout << '(' << x << "," << y << ')';
        }

        double findDistanceFromStart()
        {
            return sqrt(x * x + y * y);
        }

        double findDistanceToPoint(Point &p)
        {
            return abs(sqrt(p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
        }

        int findQuadrant()
        {
            if (x > 0 && y > 0)
                return 1;
            if (x < 0 && y > 0)
                return 2;
            if (x > 0 && y < 0)
                return 3;
            if (x < 0 && y < 0)
                return 4;
        }
    };

    Point read()
    {
        Point p;
        std::cin >> p.x >> p.y;
    }

}