#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable : 4996) // за да използваме strcpy без предупреждения, тъй като е deprecated в C++17

/* Класът Student, който беше за домашно от първия практикум
За конкретната задача ни трябва да достъпим name, facultyNumber и pass, затова ги правим public. 
За момента още не знаем как да процедираме, така че член-данните да са private и да можем да ги достъпим
*/
class Student
{
public:
    char* name;
    char* facultyNumber;
    char* pass;

    bool validatePassword(const char *password)
    {
        while (*password != '\0' && *pass != '\0')
        {
            if (*password != *pass)
                return false;
        }

        return *pass == *password && pass == "\0";
    }

    void printInfo()
    {
        std ::cout << name << " with fn: " << facultyNumber;
    }

    bool changePassword(const char *password, char *newPassword)
    {
        if (validatePassword(password))
        {
            pass = newPassword;
            return true;
        }
        return false;
    }
};


class StudentSerializer {
public:
    void serialize(const Student& student, const char* filename) {
        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return;
        }

        std::ofstream ofs(filename);
        if (!ofs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        ofs << strlen(student.name) << " " << student.name << std::endl 
            << strlen(student.facultyNumber) << " " << student.facultyNumber << std::endl
            << strlen(student.pass) << " " << student.pass << std::endl;

        ofs.close();
    }

    Student deserialize(const char* filename) {
        Student student;

        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return student;
        }

        std::ifstream ifs(filename);
        if (!ifs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return student;
        }

        int length;

        ifs >> length;
        student.name = new char[length + 1]; // +1 за терминиращата нула
        ifs >> student.name; // потокът може да се ориентира докъде да чете

        ifs >> length;
        student.facultyNumber = new char[length + 1]; // +1 за терминиращата нула
        ifs >> student.facultyNumber;

        ifs >> length;
        student.pass = new char[length + 1]; // +1 за терминиращата нула
        ifs >> student.pass;

        ifs.close();
        return student;
    }
};
