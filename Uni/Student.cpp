#include "Student.h"

Student::Student(const std::string& name, int age, const std::vector<std::pair<Subjects, double>>& grades) :Person(name, age), grades(grades)
{
}

std::ostream& operator<<(std::ostream& oc, const Student& student)
{
	oc << "Name: " << student.name << "\nAge: " << student.age << std::endl;
	for (const auto& subj : student.grades) {
		oc << SubjecttoText(subj.first) << " - " << subj.second << '\n';
	}
	return oc;
}