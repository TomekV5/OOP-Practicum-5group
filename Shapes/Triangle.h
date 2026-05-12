#pragma once
#include "Shape.h"
class Triangle:public Shape
{
protected:
	double a;
	double b;
	double c;
public:
	const double& getArea() const;
	Triangle(const std::string& color, double a, double b, double c);
};