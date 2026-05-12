#pragma once
#include "Rectangle.h"
class Square:public Rectangle
{
protected:
	double side;
public:
	const double& getArea() const;
	Square(const std::string& color, double side);
};