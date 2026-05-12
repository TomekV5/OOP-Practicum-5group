#pragma once
#include <string>
#include <iostream>

class Assignment
{
private:
	std::string title;
	std::string description;

public:
	Assignment(std::string& title, std::string& description);

	friend std::ostream& operator<<(std::ostream& os, const Assignment& assignment);
};

