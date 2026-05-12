#include "Student.h"


// не забравяйте, че static променливите се инициализират в cpp-то
int Student::counter = 1;

/* пример за употреба на std::move, изцяло с цел оптимизация - 
вместо да правим ново копие на подадения стринг "крадем" стойността му.
Student::Student(std::string& name) : name(name) (нормален копиращ конструктор) е напълно валидно, 
просто не е толкова оптимално откъм памет */
Student::Student(std::string& name) : name(std::move(name))
{
    fn = counter;
    counter++;

    /* понеже counter е static, той е общ брояч за целия клас, т.е. всеки студент може да го промени и това да е видимо за останалите. 
    Увеличаваме стойността му, само като създаваме нов студент - 
    така си подсигуряваме, че за всеки студент факултетния номер ще бъде уникален */
}

Student::Student(const char* name) : name(name)
{
    fn = counter;
    counter++;
}

/* както казахме в StudentBook.cpp, пренасяме логиката на тези методи в реализацията на клас StudentBook, 
тъй като зависят изцяло от самата студентска книжка. В Student само ги извикваме*/
void Student::addGrade(double grade)
{
    studentBook.addGrade(grade);
}

double Student::calcGPA() const
{
    return studentBook.calcGPA();
}

bool Student::operator==(const Student& other) const
{
    return calcGPA() == other.calcGPA();
}

bool Student::operator!=(const Student& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "Student: " << student.name << ", FN: " << student.fn;

    return os;
}

/* напомняме, че operator<< и operator>>  са ВИНАГИ freind функции и винаги връщат референция.

Причината да е friend е заради начина, по който работят член-функциите и операторите.
Когато предефинираме оператор, компилатора гледа точния ред на подаване на аргументите, напр.
имаме клас ComplexNum, искаме да можем да го умножим със скалар цяло число

ComplexNum operator*(ComplexNum& num, int scalar) {...реализацяита не ни интересува...}
int main() 
{
    ComplexNum comp(...);

    ComplexNum c = comp * 4;
}
Така разписан operator* можем да извикаме само comp * 4; 4 * comp би хвърлило грешка - въпреки че за нас изглежда
еднакво, за компилатора не е - трябва да следваме точния ред на аргументите

Сега нека припомним как работят член-функциите:
напр. void Student::addGrade(double grade) привидно има само един аргумент, но всъщност са два - 
на първо място винаги седи указател this към текущия обект, т.е void Student::addGrade(const Student* this, double grade)

Така ако operator<< не беше friend щяхме да имаме
std::ostream& operator<<(const Student* this, std::ostream& os)
т.е. 
int main()
{
    Student st(...);

    st << cout -> това е неъзможно, понеже ни трябва поток на първо място, към който да пишем
}

Причината за референцията е, че искаме да chain-ваме няколко последователни извиквания на оператора
os << "Student: " << student.name << ", FN: " << student.fn; е пример за такова chain-ване.
Сега вече ако имаме Student s1 и Student s2 можем да направим
std::cout << s1 << ' ' << s2 << std::endl */
