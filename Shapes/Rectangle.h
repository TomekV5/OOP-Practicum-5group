#pragma once
#include "Shape.h"
class Rectangle:public Shape
{
protected:
	double width;
	double lenght;
public:
	const double& getArea() const;
	Rectangle(const std::string& color, double width, double lenght);
};