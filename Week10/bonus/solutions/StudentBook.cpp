#include "StudentBook.h"

/* в случая нищо не ни е казано за конструкторите на StudentBook, така че можем да го оставим с default-ния, генериран от компилатора.
Самият vector, който сме вложили в нашия клас, си има дефиниран конструктор по подразбиране, 
който ще се извика автоматично, така че от нас не се налага да пишем нищо допълнително */

void StudentBook::addGrade(double grade)
{
	grades.push_back(grade);
}

double StudentBook::calcGPA() const
{
	size_t gradeCount = grades.size();
	double result = 0;

	for (int i = 0; i < gradeCount; i++) 
	{
		result += grades[i];
	}


	/* vector ни позволява да напишем цикъла и по този начин
	for (double grade : grades) 
	{
		result += grade;
	}
	и двете са валидни */
	


	return result / gradeCount;
}
