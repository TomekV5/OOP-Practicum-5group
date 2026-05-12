#pragma once
#include "UniversityWorker.h"
const double DEFAULT_PENSION = 1.5;
class Principal:public UniversityWorker
{
private:
	int room;
public:
	Principal(const std::string& name, int age, int workExperience, double pension, int room);
	friend std::ostream& operator<<(std::ostream& oc, const Principal principal);
};