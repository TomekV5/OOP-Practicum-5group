#include <iostream>

const int EMPLOYEE_CNT = 50;

namespace CompanyNS {
    enum Position {
        SoftwareEngineer,
        SeniorSoftwareEngineer,
        EngineerManager,
        LeadSoftwareEngineer
    };

    struct Employee {
        char* name;
        Position position;
        double salary;
        int grade;

        void print() {
            std::cout << name << " - " << position << ", salary: " << salary << ", grade: " << grade << "\n";
        }

        void changeSalary(double newSalary) {
            salary = newSalary;
        }

        void changeGrade(int newGrade) {
            grade = newGrade;
        }

        void changeGrade(Position newPosition) {
            position = newPosition;
        }
    };

    struct Company {
        Employee employees[EMPLOYEE_CNT];
        size_t employeeCnt = 0;
        double avgSalary;

        void addEmployee(Employee employee) {
            if(employeeCnt >= EMPLOYEE_CNT) return;
            employees[employeeCnt++] = employee;
        }

        void getEmployeesWithMoreThanAvgSalary() {
            char** names = new char*[EMPLOYEE_CNT];
            size_t namesCnt = 0;
            for (size_t i = 0; i < employeeCnt; i++) {
                if(employees[i].salary > avgSalary) {
                    names[namesCnt++] = employees[i].name;
                }
            }
            //Sort names
            while(namesCnt) {
                std::cout << names[namesCnt - 1];
            }
        }

        void getMaxAndMinGrade() {
            int max = INT_MIN;
            int min = INT_MAX;
            for (size_t i = 0; i < employeeCnt; i++) {
                if(employees[i].grade < min) min = employees[i].grade;
                if(employees[i].grade > max) max = employees[i].grade;
            }
            std::cout << min << " " << max << "\n";
        }

        void getAvgForEachPosition() {
            double avgSE = 0;
            int SECount = 0;
            double avgSSE = 0;
            int SSECount = 0;
            double avgEM = 0;
            int EMCount = 0;
            double avgLSE = 0;
            int LSECount = 0;

            for (size_t i = 0; i < employeeCnt; i++) {
                switch(employees[i].position) {
                    case SoftwareEngineer:
                        avgSE += employees[i].salary;
                        SECount++;
                        break;
                    case SeniorSoftwareEngineer:
                        avgSSE += employees[i].salary;
                        SSECount++;
                        break;
                    case EngineerManager:
                        avgEM += employees[i].salary;
                        EMCount++;
                        break;
                    case LeadSoftwareEngineer:
                        avgLSE += employees[i].salary;
                        LSECount++;
                        break;
                    default:
                        break;
                }
            }
            std::cout << "SE: " << avgSE / SECount << "\n";
            std::cout << "SSE: " << avgSSE / SSECount << "\n";
            std::cout << "EM: " << avgEM / EMCount << "\n";
            std::cout << "LSE: " << avgLSE / LSECount << "\n";
        }
    };
}