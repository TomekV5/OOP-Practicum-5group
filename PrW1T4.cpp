
#include <cstring>
#include <iostream>
const int Max_Letter_Amount = 50;
struct Student
{
	char name[Max_Letter_Amount]{ '\0' };
	char facultyNumber[Max_Letter_Amount]{ '\0' };
	char password[Max_Letter_Amount]{ '\0' };
	bool PasswordCorrect(char input[Max_Letter_Amount]) const {
		for (int i = 0; i < Max_Letter_Amount; i++) {
			if (input[i] != password[i]) {
				return false;
			}
		}
		return true;
	}
	void Print() {
		std::cout << "Name = " << name <<
			"\nFacultyNumber = " << facultyNumber << 
			"\nPassword = " << password;
	}
	bool ChangePassword(char oldpassword[Max_Letter_Amount], char newpassword[Max_Letter_Amount]) {
		if (PasswordCorrect(oldpassword)) {
			for (int i = 0; i < Max_Letter_Amount; i++) {
				password[i] = newpassword[i];
			}
			return true;
		}
		return false;
	}
};
int main()
{
	 Student s;

    strcpy_s(s.name, "Ivan Petrov");
	strcpy_s(s.facultyNumber, "123456");
	strcpy_s(s.password, "pass123");

    std::cout << "Initial data:\n";
    s.Print();

    char testPass1[Max_Letter_Amount] = "pass123\0";
    char testPass2[Max_Letter_Amount] = "wrong\0";

    std::cout << "\nTest PasswordCorrect:\n";
    std::cout << "Correct password -> " << s.PasswordCorrect(testPass1) << "\n"; // 1
    std::cout << "Wrong password -> " << s.PasswordCorrect(testPass2) << "\n";   // 0

    char oldPassWrong[Max_Letter_Amount] = "123";
    char newPass1[Max_Letter_Amount] = "newpass";

    std::cout << "\nChange with wrong old password -> "
              << s.ChangePassword(oldPassWrong, newPass1) << "\n"; 

    char oldPassCorrect[Max_Letter_Amount] = "pass123";
    char newPass2[Max_Letter_Amount] = "newpass";

    std::cout << "Change with correct old password -> "
              << s.ChangePassword(oldPassCorrect, newPass2) << "\n"; // 1

    std::cout << "\nAfter password change:\n";
    s.Print();
}