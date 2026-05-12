#include <iostream>

class Student
{
    char *name;
    char *facultyNumber;
    char *pass;

public:
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