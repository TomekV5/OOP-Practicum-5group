#include <iostream>
#include "Vector.h"
#include "String.h"

int main()
{
    Vector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (size_t i = 0; i < v.getSize(); i++) {
        std::cout << v[i] << " ";
    }

    std::cout << "\nSize: " << v.getSize();
    std::cout << "\nCapacity: " << v.getCapacity();

    String a("Hello");
    String b(" Alexs");

    String c = a + b;

    std::cout <<std::endl<< c.print() << std::endl;

    c.push_back('!');
    c[6] = 'M';
    c[7] = 'i';
    c[8] = 't';
    c[9] = 'k';
    c[10] = 'o';

    std::cout << c.print() << std::endl;

    return 0;
}