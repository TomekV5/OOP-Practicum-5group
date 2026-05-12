#pragma once
#include "Shape.h"
class Circle:public Shape
{
protected:
	double radius;
public:
	const double& getArea() const;
	Circle(const std::string& color, double radius);
};