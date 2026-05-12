#include "Square.h"

Square::Square(const std::string& color, double side) :Rectangle(color, side, side), side(side)
{
}
const double& Square::getArea() const {
	return side * side;
}