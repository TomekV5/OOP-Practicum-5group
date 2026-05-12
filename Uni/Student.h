#pragma once
#include "Person.h"
#include "Subjects.h"
#include <vector>
class Student:public Person
{
private:
	std::vector<std::pair<Subjects, double>> grades;
public:
	Student(const std::string& name, int age, const std::vector<std::pair<Subjects, double>>& grades);
	friend std::ostream& operator<<(std::ostream& oc, const Student& student);
};