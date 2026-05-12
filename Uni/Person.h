#pragma once
#include <string>
#include <iostream>
class Person
{
protected:
	std::string name;
	int age;
public:
	Person(const std::string& name, int age);
	friend std::ostream& operator <<(std::ostream& oc, const Person& person);
};