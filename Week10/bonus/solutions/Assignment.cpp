#include "Assignment.h"

/* няма проблем да използваме и нормален копиращ конструктор в инициализиращия списък, 
просто не е толкова оптимално както move */
Assignment::Assignment(std::string& title, std::string& description) : title(title), description(description)
{}

std::ostream& operator<<(std::ostream& os, const Assignment& assignment)
{
	os << "Assignment: " << assignment.title << std::endl << assignment.description;

	return os;
}
