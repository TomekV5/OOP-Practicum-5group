#include "Subjects.h"

std::string SubjecttoText(Subjects subject)
{
	switch (subject)
	{
	case Subjects::Literature:
		return "Literature";
	case Subjects::Math:
		return "Math";
	case Subjects::Geometry:
		return "Geometry";
	case Subjects::Up:
		return "Up";
	case Subjects::OOP:
		return "OOP";
	case Subjects::DSTR:
		return "DSTR";
	case Subjects::DIS:
		return "DIS";
	default:
		return "Problem";
	}
}