#pragma once
#include "UniversityWorker.h"
#include "Subjects.h"
#include <vector>
const double DEFAULT_PENSION = 1;
class Teacher:public UniversityWorker
{
private:
	std::vector<Subjects> subjects;
public:
	Teacher(const std::string& name, int age, int workExperience, double pension, const std::vector<Subjects>& subjects);
	friend std::ostream& operator<<(std::ostream& oc, const Teacher& teacher);
};