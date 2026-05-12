#pragma once
#include "Person.h"
class UniversityWorker :public Person
{
protected:
	int workExperience;
	double pension;
	double pensionRate;
public:
	const double getPension() const;
	UniversityWorker(const std::string& name, int age, int workExperience, double pension, double pensionRate);
	friend std::ostream& operator<<(std::ostream& oc, const UniversityWorker& uw);
};

