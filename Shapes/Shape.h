#pragma once
#include <string>
class Shape
{
protected:
	std::string color;
public:
	const std::string& getColor() const;
	Shape(const std::string& color);
};