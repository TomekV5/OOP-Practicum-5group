#pragma once
#include <vector>

class StudentBook
{
private:
	std::vector<double> grades;

public:

	/*	въпреки че в описанието на задачата тези методи ги пише при Student, е очевидно, 
	че това са функционалности на самата студентска книжка.
	Най-лесно е да пренесем самата логика по реализация в този клас, 
	а в Student само ще имаме методи със същото име, които извикват тези

	(най-малкото че grades е private, така че не можем директно да го достъпим през Student) */
	void addGrade(double grade);
	double calcGPA() const;

};

