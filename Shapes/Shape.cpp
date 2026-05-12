#include "Shape.h"

const std::string& Shape::getColor() const
{
	return color;
}

Shape::Shape(const std::string& color) :color(color)
{
}
