#include "Teacher.h"

Teacher::Teacher(const std::string& name, int age, int workExperience, double pension, const std::vector<Subjects>& subjects) :UniversityWorker(name, age, workExperience, pension, DEFAULT_PENSION), subjects(subjects)
{
}

std::ostream& operator<<(std::ostream& oc, const Teacher& teacher)
{
	oc << "Name: " << teacher.name << "\nAge: " << teacher.age << "\nWork experience: " << teacher.workExperience << "\nPension: " << teacher.getPension() << std::endl;
	for (const auto& subj : teacher.subjects) {
		oc << SubjecttoText(subj) << '\n';
	}
	return oc;
}