#include "Circle.h"

Circle::Circle(const std::string& color, double radius):Shape(color),radius(radius)
{
}
const double& Circle::getArea() const {
	double pi = 2 * acos(0.0);
	return radius*radius*pi;
}