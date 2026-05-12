#include "Rectangle.h"
#include "Triangle.h"

const double& Rectangle::getArea() const
{
    return width * lenght;
}

Rectangle::Rectangle(const std::string& color, double width, double lenght):Shape(color),width(width),lenght(lenght)
{
}
