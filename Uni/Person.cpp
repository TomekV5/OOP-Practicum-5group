#include "Person.h"

Person::Person(const std::string& name, int age):name(name), age(age)
{
}

std::ostream& operator<<(std::ostream& oc, const Person& person)
{
	return oc << "Name: " << person.name << "\nAge: " << person.age;
}