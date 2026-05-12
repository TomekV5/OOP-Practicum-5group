#pragma once
#include <string>
#include <iostream>
#include "StudentBook.h"


class Student
{
private:
	static int counter;

	int fn;
	std::string name;
	StudentBook studentBook;

public:
	/*  това, че сме разписали някакъв друг конструктор, приемащ параметри, 
	ще премахне конструктора по подразбиране, генериран от компилатора.
	Все пак ако искате да сте напълно сигурни може да напишете експлицитно
	Student() = delete */

	Student(std::string& name);
	Student(const char* name);

	void addGrade(double grade);
	double calcGPA() const;

	friend std::ostream& operator<<(std::ostream& os, const Student& student);

	bool operator==(const Student& other) const;
	bool operator!=(const Student& other) const;


	/* oprator<=> е доста бъгав/държи се нетрадиционно заради auto - компилаторът не винаги успява да се 
	ореинтира какво точно да върне това auto и директно хвърля грешка. Ако не можете да си компилирате 
	програмата само заради този оператор опитайте да преместите дефиницията в header файла*/
	auto operator<=>(const Student& other) const
	{
		double thisGPA = calcGPA();
		double otherGPA = other.calcGPA();

		/* double е примитивен тип, така че има дефиниран operator<=>, който можем да използваме наготово.
		Като цяло в повечето задачи, освен ако няма много завъртяна логика по сравняване на обектите,
		се опитваме да сведем класа до примитивните типове, от които зависи сравнението и да използваме техния operator<=> */

		return thisGPA <=> otherGPA;
	}

};

