#include "UniversityWorker.h"

const double UniversityWorker::getPension() const
{
	return pension * pensionRate;
}

UniversityWorker::UniversityWorker(const std::string& name, int age, int workExperience, double pension, double pensionRate) :Person(name, age), workExperience(workExperience), pension(pension), pensionRate(pensionRate)
{
}

std::ostream& operator<<(std::ostream& oc, const UniversityWorker& uw)
{
	return oc << "Name: " << uw.name << "\nAge: " << uw.age << "\nWork experience: " << uw.workExperience << "\nPension: " << uw.getPension()
		<< std::endl;
}
