#include "Principal.h"

Principal::Principal(const std::string& name, int age, int workExperience, double pension, int room) :UniversityWorker(name, age, workExperience, pension, DEFAULT_PENSION), room(room)
{
}

std::ostream& operator<<(std::ostream& oc, const Principal principal)
{
	return oc << "Name: " << principal.name << "\nAge: " << principal.age << "\nWork experience: " << principal.workExperience << "\nPension: " << principal.getPension()
		<< "\nroom: " << principal.room << std::endl;
}
