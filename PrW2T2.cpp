// PrW2T2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

const int Max_Letter_Amount = 50;
const int BUFF_SIZE = 100;
struct Student
{
	char name[Max_Letter_Amount]{ '\0' };
	char facultyNumber[Max_Letter_Amount]{ '\0' };
	char password[Max_Letter_Amount]{ '\0' };
	bool setStudent(char* input) {
		if (input[0] == '\0') {
			return false;
		}
		int index = 0;
		int tempindex = 0;
		while (input[index] != '\0' && input[index] != ',') {
			name[tempindex] = input[index];
			tempindex++;
			index++;
		}
		name[tempindex] = '\0';
		tempindex = 0;
		index++;
		while (input[index] != '\0' && input[index] != ',') {
			facultyNumber[tempindex] = input[index];
			tempindex++;
			index++;
		}
		facultyNumber[tempindex] = '\0';
		tempindex = 0;
		index++;
		while (input[index] != '\0') {
			password[tempindex] = input[index];
			tempindex++;
			index++;
		}
		password[tempindex] = '\0';
		return true;
	}
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
	char* getStudentInfo() {
		char* info = new char[Max_Letter_Amount * 3];
		snprintf(info, Max_Letter_Amount*3, "%s,%s,%s", name, facultyNumber, password);
		return info;
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
class StudentSerializer {
public:
	Student* readFromFile(const char* filename, int& size) {
		std::ifstream inputfile(filename);
		if (!inputfile.is_open()) {
			std::cout << "Failed to open file." << std::endl;
		}
		inputfile.seekg(0, std::ios::beg);
		size = 0;
		while (!inputfile.eof()) {
			size++;
			char buff[BUFF_SIZE];
			inputfile.getline(buff, BUFF_SIZE);
		}
		inputfile.seekg(0, std::ios::beg);
		Student* students = new Student[size];
		int index = 0;
		while (!inputfile.eof()) {
			char buff[BUFF_SIZE];
			inputfile.getline(buff, BUFF_SIZE);
			students[index].setStudent(buff);
			index++;
		}
		inputfile.close();
		return students;
	}
	void printAccounts(Student* accounts, int size) {
		for (int i = 0; i < size; i++) {
			char* info = accounts[i].getStudentInfo();
			std::cout << info << std::endl;
			delete[] info;
		}
	}
	bool writeToFile(const char* filename, Student* accounts, int size) {
		std::ofstream outputfile(filename);
		if (!outputfile.is_open()) {
			std::cout << "Failed to open file." << std::endl;
			return false;
		}
		outputfile.seekp(0, std::ios::beg);
		for (int i = 0; i < size; i++) {
			char* info = accounts[i].getStudentInfo();
			if (i != size - 1) {
				outputfile << info << std::endl;
			}
			else {
				outputfile << info;
			}
			delete[] info;
		}
		outputfile.close();
		return true;
	}
};
int main()
{
	int size = 0;
	StudentSerializer serializer;
	Student* students = serializer.readFromFile("studentinfo.txt", size);
	serializer.printAccounts(students, size);
	serializer.writeToFile("studentinfo.txt", students, size);
	delete[] students;
}