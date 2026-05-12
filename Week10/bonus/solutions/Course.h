#pragma once
#include "Student.h"
#include "Assignment.h"
#include <iostream>
#include <vector>

enum class  Major
{
	SOFTWARE_ENGINEERING,
	COMPUTER_SCIENCE,
	APPLIED_MATHEMATICS,
	DATA_ANALYSIS
};

class Course
{
private:
	std::string name;
	int year;
	Major major;

	/* това, че Student няма конструктор по подразбиране означава, че трябва да използваме указатели, 
	ако ще имаме колекция от студенти (каквато имаме в тази задача)
	В такъв случай трябва или ние сами да се грижим за правилната работа с всичката динамична памет, 
	или да използваме някакъв wrapper клас за указатели.
	
	В задачата ни е подсказано, че един студент може да е записан на няколко предмета, така че 
	най-лесно е да използваме shared_ptr и да предадем обработката на динамична памет на него */
	std::vector<std::shared_ptr<Student>> students;

	/* отново по същия начин, Assignment няма констурктор по подразбиране, така че ще трябва да използваме указател.
	Понеже знаем, че всеки предмет има точно 1 финално задание и всяко финално задание е уникално за всеки курс,
	можем да използваме unique_ptr и да си спестим работата с указателите. Ако не се сетите за това можете да 
	ползвате и нормален указател, но тогава ще трябва сами да разпишете Rule of Five*/
	std::unique_ptr<Assignment> finalAssignment;

	std::string getMajor() const;

public:
	Course(std::string& name, int year, Major major);
	Course(const char* name, int year, Major major);

	void enroll(const std::shared_ptr<Student>& student);

	void showTopN(unsigned n);

	void addFinalAssignment(const Assignment& assignment);
	void addFinalAssignment(std::unique_ptr<Assignment>& assignment);

	friend std::ostream& operator<<(std::ostream& os, const Course& course);
};

