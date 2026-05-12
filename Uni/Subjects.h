#pragma once
#include <string>
enum class Subjects
{
	Literature,
	Math,
	Geometry,
	Up,
	OOP,
	DSTR,
	DIS
};
std::string SubjecttoText(Subjects subject);