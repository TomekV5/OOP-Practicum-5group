#include <iostream>

namespace TrianglesSorter
{
    struct Triangle
    {
        int a, b, c;

        // Heron's formuula for area of triangle
        double area()
        {
            double s = (a + b + c) / 2;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }
    };

    Triangle readTriangle()
    {
        Triangle res;
        std::cin >> res.a >> res.b >> res.c;
        return res;
    }

    Triangle *sortTriangles(Triangle *triangles, size_t size)
    {
        // Sorting algorithm invoking area() for every two triangles
    }
}