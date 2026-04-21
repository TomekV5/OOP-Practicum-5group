#include <iostream>

namespace ImaginaryNums
{
    struct ComplexNum
    {
        double real;
        double imaginary;

        void print()
        {
            std::cout << real << " + " << imaginary << "i";
        }
    };

    ComplexNum add(ComplexNum &a, ComplexNum &b)
    {
        ComplexNum result;
        result.real = a.real + b.real;
        result.imaginary = a.imaginary + b.imaginary;
        return result;
    }

    ComplexNum product(ComplexNum &a, ComplexNum &b)
    {
        ComplexNum result;
        result.real = a.real * b.real - a.imaginary * b.imaginary;
        result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
        return result;
    }

    ComplexNum divide(ComplexNum a, ComplexNum b)
    {
        ComplexNum result;
        double denominator = b.real * b.real + b.imaginary * b.imaginary;

        result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
        result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
        return result;
    }
}