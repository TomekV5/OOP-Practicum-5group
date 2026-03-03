#include <iostream>
#include <fstream>
int strToInt(char* str) {
	int result = 0;
	int i = 0;
	while (str[i] != '\0') {
		result = result * 10 + ((int)str[i] - (int)'0');
		i++;
	}
	return result;
}
double stringToDouble(char* str) {
	double result = 0;
	bool passed = false;
	int couter = 0;
	int i = 0;
	while (str[i]!='\0') {
		if (str[i] == '.') {
			passed = true;
		}
		else {
			result = result * 10 + ((int)str[i] - (int)'0');
		}
		if (passed) {
			couter++;
		}
		i++;
	}
	for (int i = 0; i < couter - 1; i++) {
		result /= 10;
	}
	return result;
}
void STRCopy(char* dest, const char* src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}
enum Position
{
	SoftwareEngineer,
	SeniorSoftwareEngineer,
	EngineeringManager,
	LeadSoftwareEngineer,
	UnknownPosition
};
Position IntToPosition(int x)
{
	switch (x)
	{
	case 0: return SoftwareEngineer;
	case 1: return SeniorSoftwareEngineer;
	case 2: return EngineeringManager;
	case 3: return LeadSoftwareEngineer;
	default: return UnknownPosition;
	}
}

const char* PositionToString(Position p)
{
	switch (p)
	{
	case SoftwareEngineer: return "Software Engineer";
	case SeniorSoftwareEngineer: return "Senior Software Engineer";
	case EngineeringManager: return "Engineering Manager";
	case LeadSoftwareEngineer: return "Lead Software Engineer";
	default: return "Unknown";
	}
}
const int MAX_NAME = 101;

struct Employee
{
	char name[MAX_NAME];
	Position position;
	double salary;
	int skillRating;
};
void InitEmployee(Employee& e, const char* name, Position pos, double salary, int rating)
{
	STRCopy(e.name, name);
	e.position = pos;
	e.salary = salary;
	e.skillRating = rating;
}

void PrintEmployee(const Employee& e)
{
	std::cout << e.name << " | "
		<< PositionToString(e.position) << " | "
		<< e.salary << " | "
		<< e.skillRating << "\n";
}

void ChangeSalary(Employee& e, double newSalary)
{
	e.salary = newSalary;
}

void ChangeRating(Employee& e, int newRating)
{
	e.skillRating = newRating;
}

void ChangePosition(Employee& e, Position newPos)
{
	e.position = newPos;
}
const int MAX_EMP = 100;

struct Company
{
	Employee employees[MAX_EMP];
	int size = 0;
};
double GetAverageSalary(const Company& c)
{
	if (c.size == 0) return 0;

	double sum = 0;
	for (int i = 0; i < c.size; i++)
		sum += c.employees[i].salary;

	return sum / c.size;
}
void SortByName(Employee arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(arr[i].name, arr[j].name) > 0)
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}
void PrintAboveAverage(const Company& c)
{
	double avg = GetAverageSalary(c);

	Employee temp[MAX_EMP];
	int count = 0;

	for (int i = 0; i < c.size; i++)
	{
		if (c.employees[i].salary > avg)
		{
			temp[count++] = c.employees[i];
		}
	}

	SortByName(temp, count);

	for (int i = 0; i < count; i++)
		std::cout << temp[i].name << "\n";
}
void PrintMinMaxRatingByPosition(const Company& c)
{
	for (int p = 0; p < 4; p++)
	{
		int minR = 101, maxR = -1;
		bool found = false;

		for (int i = 0; i < c.size; i++)
		{
			if (c.employees[i].position == p)
			{
				found = true;
				if (c.employees[i].skillRating < minR) minR = c.employees[i].skillRating;
				if (c.employees[i].skillRating > maxR) maxR = c.employees[i].skillRating;
			}
		}

		if (found)
		{
			std::cout << PositionToString((Position)p)
				<< " -> Min: " << minR
				<< " Max: " << maxR << "\n";
		}
	}
}
void PrintAverageSalaryByPosition(const Company& c)
{
	for (int p = 0; p < 4; p++)
	{
		double sum = 0;
		int count = 0;

		for (int i = 0; i < c.size; i++)
		{
			if (c.employees[i].position == p)
			{
				sum += c.employees[i].salary;
				count++;
			}
		}

		if (count > 0)
		{
			std::cout << PositionToString((Position)p)
				<< " -> " << sum / count << "\n";
		}
	}
}
void PrintByPosition(const Company& c, Position p)
{
	for (int i = 0; i < c.size; i++)
		if (c.employees[i].position == p)
			std::cout << c.employees[i].name << "\n";
}
void SortByRating(Employee arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (arr[i].skillRating > arr[j].skillRating)
				std::swap(arr[i], arr[j]);
}
void SortBySalary(Employee arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (arr[i].salary > arr[j].salary)
				std::swap(arr[i], arr[j]);
}
void PrintNamesAndPositionsSorted(const Company& c)
{
	Employee temp[MAX_EMP];
	for (int i = 0; i < c.size; i++)
		temp[i] = c.employees[i];

	SortByName(temp, c.size);

	for (int i = 0; i < c.size; i++)
	{
		std::cout << temp[i].name << " - "
			<< PositionToString(temp[i].position) << "\n";
	}
}
const int EMP_BUFF_SIZE = 256;

class ITCompanySerializer {
public:

	bool setEmployee(Employee& e, char* input) {
		if (input[0] == '\0')
			return false;

		int index = 0;
		int tempIndex = 0;

		char name[MAX_NAME];
		while (input[index] != '\0' && input[index] != ',') {
			name[tempIndex++] = input[index++];
		}
		name[tempIndex] = '\0';

		if (input[index] == ',') index++;
		tempIndex = 0;

		char posStr[20];
		while (input[index] != '\0' && input[index] != ',') {
			posStr[tempIndex++] = input[index++];
		}
		posStr[tempIndex] = '\0';

		if (input[index] == ',') index++;
		tempIndex = 0;

		char salaryStr[30];
		while (input[index] != '\0' && input[index] != ',') {
			salaryStr[tempIndex++] = input[index++];
		}
		salaryStr[tempIndex] = '\0';

		if (input[index] == ',') index++;
		tempIndex = 0;

		char ratingStr[20];
		while (input[index] != '\0') {
			ratingStr[tempIndex++] = input[index++];
		}
		ratingStr[tempIndex] = '\0';

		int posInt = strToInt(posStr);
		double salary = stringToDouble(salaryStr);
		int rating = strToInt(ratingStr);

		InitEmployee(e, name, IntToPosition(posInt), salary, rating);

		return true;
	}

	Employee* readFromFile(const char* filename, int& size) {
		std::ifstream inputfile(filename);
		if (!inputfile.is_open()) {
			std::cout << "Failed to open employee file." << std::endl;
			size = 0;
			return nullptr;
		}

		size = 0;
		char buff[EMP_BUFF_SIZE];

		while (!inputfile.eof()) {
			inputfile.getline(buff, EMP_BUFF_SIZE);
			if (buff[0] != '\0')
				size++;
		}

		inputfile.clear();
		inputfile.seekg(0, std::ios::beg);

		Employee* employees = new Employee[size];
		int index = 0;

		while (!inputfile.eof()) {
			inputfile.getline(buff, EMP_BUFF_SIZE);
			if (buff[0] == '\0') continue;

			setEmployee(employees[index], buff);
			index++;
		}

		inputfile.close();
		return employees;
	}

	bool writeToFile(const char* filename, Employee* employees, int size) {
		std::ofstream outputfile(filename);
		if (!outputfile.is_open()) {
			std::cout << "Failed to open employee file." << std::endl;
			return false;
		}

		for (int i = 0; i < size; i++) {
			outputfile << employees[i].name << ","
				<< employees[i].position << ","
				<< employees[i].salary << ","
				<< employees[i].skillRating;

			if (i != size - 1)
				outputfile << std::endl;
		}

		outputfile.close();
		return true;
	}

	void printEmployees(Employee* employees, int size) {
		for (int i = 0; i < size; i++) {
			PrintEmployee(employees[i]);
		}
	}
};

int main()
{
	int employeeSize = 0;
	ITCompanySerializer companySerializer;
	Employee* employees = companySerializer.readFromFile("employees.txt", employeeSize);
	companySerializer.printEmployees(employees, employeeSize);
	companySerializer.writeToFile("employees.txt", employees, employeeSize);
	delete[] employees;
}