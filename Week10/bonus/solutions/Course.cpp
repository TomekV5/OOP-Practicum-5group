#include "Course.h"

/* не можем директно да принтираме enum на конзолата, така че ни трябва помощна фунцкия за това
switch-case е най-добрия начин за това */
std::string Course::getMajor() const
{
    switch (major) 
    {
    case Major::SOFTWARE_ENGINEERING:
        return "Software Engineering";
    case Major::COMPUTER_SCIENCE:
        return "Computer Science";
    case Major::APPLIED_MATHEMATICS:
        return "Applied Mathematics";
    case Major::DATA_ANALYSIS:
        return "Data analysis";
    }
}

Course::Course(std::string& name, int year, Major major) : name(std::move(name)), year(year), major(major)
{}

Course::Course(const char* name, int year, Major major) : name(name), year(year), major(major)
{}

/* не приемаме студент, а shared_ptr! Цялата идея на задачата е, че студентите са общи за предметите, 
така че трябва shared_ptr да следи брояча за студенти. 

Ако бяхме приели Student като аргумент на метода и бяхме използвали make_shared щяхме да създадем
изцяло нов shared_ptr, чийто брояч запова от 1, което обезмился цялата употреба на shared_ptr.

В момента това което се случва е, че отвън ни подават вече съществуващ shared_ptr<Student> за вече 
съществуващ студент, който има някакъв брояч. Добавяйки го в масива просто му създаваме копие и 
увеличаваме брояча, което е именно желания резултат*/
void Course::enroll(const std::shared_ptr<Student>& student)
{
    students.push_back(student);
}

void Course::showTopN(unsigned n)
{
    size_t studentCount = students.size();

    /* Selction Sort; просто ни трябваше някакъв сортиращ алгоритъм за задачата;
    не сте длъжни да го знаете наизуст или да използвате точно този ако ви се налага да сортирате колекиця */
    for (size_t i = 0; i < studentCount - 1; i++) 
    {
        size_t maxIdx = i;
        for (size_t j = i + 1; j < studentCount; j++)
        {
            /* трябва да дереферираме smart pointer-ите, за да извършим действията със самите студенти, а не 
            с указателите, които сочат към тях */
            if (*students[j] > *students[maxIdx])
            {
                maxIdx = j;
            }
        }

        if (i != maxIdx)
        {
            std::swap(students[i], students[maxIdx]);
        }
    }

    /* трябва да вземем първите n студента, така че ще въртим цикъл от 0 до n; 
    ако n е по-голямо от общия ни брой студенти обаче, просто цикълът ни ще бъде от 0 до studentCount, т.е. всички студенти
    за да покрием двата случая си правим помощна променлива */
    size_t end = (n > studentCount ? studentCount : n);

    for (size_t i = 0; i < end; i++) 
    {
        std::cout << *students[i] << std::endl;
    }
}

/* тук вече няма проблем да подадем и нормален const Assignment& assignment, тъй като unique_ptr няма броячи,
така че е без значение дали ще го създадем вътре в класа или извън него.
За всеки случай можем просто да overload-нем функцията с двата случая за аргументи. 
Единствената разлика е какво всъщност правим с тях - в единия случай създаваме нов unique_ptr, 
в другия move-ваме вече същестуващ*/
void Course::addFinalAssignment(const Assignment& assignment)
{
    this->finalAssignment = std::make_unique<Assignment>(assignment);
}

void Course::addFinalAssignment(std::unique_ptr<Assignment>& assignment)
{
    this->finalAssignment = std::move(assignment);
}

std::ostream& operator<<(std::ostream& os, const Course& course)
{
    os << course.name << std::endl << course.getMajor() << ", year " << course.year << std::endl;


    /* ако не сте обръщали вниамние, освен аритметични операции, можете да предефинирате 
    и как даден клас се държи като булева фунцкия. Това става чрез 
    operator bool() const {...вашата реализация...} 
    
    Това се случва и с unique_ptr; Предефиниран е така, че ако указателя, който сочи, е nullptr,
    (т.е. връща ст-ст false в такъв вид проверка), то и самия unique_ptr да върне ст-ст false 
    
    Можете да видите пример в имплементациите на smart pointer-и които сме ви дали */
    if (course.finalAssignment)
    {
        os << *course.finalAssignment << std::endl;
    }
    else
    {
        os << "No final assignment given yet" << std::endl;
    }

    std::cout << "\nStudents:\n";

    for (size_t i = 0; i < course.students.size(); i++)
    {
        /* трябва да дерефирарме указателя, за да можем да принтираме студента, към който сочи, 
        в противен случай ще принтираме адрес */
        std::cout << *course.students[i] << std::endl;
    }

    return os;
}
