#include "Triangle.h"
Triangle::Triangle(const std::string& color, double a, double b, double c) :Shape(color), a(a), b(b), c(c)
{
}
const double& Triangle::getArea() const {
	double p = a + b + c;
	p /= 2;
	double s = p * (p - a) * (p - b) * (p - c);
	return sqrt(s);
}