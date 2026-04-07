#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable : 4996) // за да използваме strcpy без предупреждения, тъй като е deprecated в C++17


/* namespace CompanyNS, който беше за домашно от първия практикум*/
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
            if (employeeCnt >= EMPLOYEE_CNT) return;
            employees[employeeCnt++] = employee;
        }

        void getEmployeesWithMoreThanAvgSalary() {
            char** names = new char* [EMPLOYEE_CNT];
            size_t namesCnt = 0;
            for (size_t i = 0; i < employeeCnt; i++) {
                if (employees[i].salary > avgSalary) {
                    names[namesCnt++] = employees[i].name;
                }
            }
            //Sort names
            while (namesCnt) {
                std::cout << names[namesCnt - 1];
            }
        }

        void getMaxAndMinGrade() {
            int max = INT_MIN;
            int min = INT_MAX;
            for (size_t i = 0; i < employeeCnt; i++) {
                if (employees[i].grade < min) min = employees[i].grade;
                if (employees[i].grade > max) max = employees[i].grade;
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
                switch (employees[i].position) {
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

class ITCompanySerializer {
public:

    void serializeEmployee(const CompanyNS::Employee& employee, const char* filename) {
        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return;
        }

        std::ofstream ofs(filename);

        if (!ofs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        ofs << strlen(employee.name) << " " << employee.name << std::endl;
        ofs << (int)employee.position << std::endl; // записваме числото, което съответства на позицията в enum-а
        ofs << employee.salary << std::endl;
        ofs << employee.grade << std::endl;

        ofs.close();
    }

    void serializeEmployee(const CompanyNS::Employee& employee, std::ofstream& ofs) {
        if (!ofs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        ofs << strlen(employee.name) << " " << employee.name << std::endl;
        ofs << (int)employee.position << std::endl; // записваме числото, което съответства на позицията в enum-а
        ofs << employee.salary << std::endl;
        ofs << employee.grade << std::endl;
    }

    CompanyNS::Employee deserializeEmployee(const char* filename) {
        CompanyNS::Employee employee{};

        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return employee;
        }

        std::ifstream ifs(filename);
        if (!ifs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return employee;
        }

        int nameLength;
        ifs >> nameLength;
        employee.name = new char[nameLength + 1];
        ifs >> employee.name;

        int positionInt; // първо трябва да прочетем числото, което сме записали за позиция
        ifs >> positionInt;
        employee.position = (CompanyNS::Position)positionInt; // след това го cast-нем обратно към Position

        ifs >> employee.salary;
        ifs >> employee.grade;

        ifs.close();
        return employee;
    }

    CompanyNS::Employee deserializeEmployee(std::ifstream& ifs) {
        CompanyNS::Employee employee{};

        if (!ifs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return employee;
        }

        int nameLength;
        ifs >> nameLength;
        employee.name = new char[nameLength + 1];
        ifs >> employee.name;

        int positionInt; // първо трябва да прочетем числото, което сме записали за позиция
        ifs >> positionInt;
        employee.position = (CompanyNS::Position)positionInt; // след това го cast-нем обратно към Position

        ifs >> employee.salary;
        ifs >> employee.grade;

        return employee;
    }

    void serializeEmployeeBinary(const CompanyNS::Employee& employee, std::ofstream& ofs) {
        if (!ofs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        size_t nameLength = strlen(employee.name);
        std::cout << nameLength << std::endl;
        ofs.write((const char*)(&nameLength), sizeof(nameLength)); // записваме дължината на името, която има големина sizeof(nameLength) = sizeof(size_t)
        ofs.write(employee.name, nameLength);
        /* +1 идва заради терминиращата нула;
        тук вече записваме самото име което е масив от char-ове -> има размер от nameLength + 1 символа * sizeof(char) (но sizeof(char) = 1, затова може да го изпуснем)
        ако бяхме написали sizeof(employee.name), това щеше да ни върне размера на указателя, а не на самата дума
        */

        int positionInt = (int)employee.position;
        ofs.write((const char*)(&positionInt), sizeof(positionInt));

        ofs.write((const char*)(&employee.salary), sizeof(double)); // дали ще напишем sizeof(employee.salary) или sizeof(double) не е от значение, тъй като не работим с указатели
        ofs.write((const char*)(&employee.grade), sizeof(employee.grade));
    }

    CompanyNS::Employee deserializeEmployeeBinary(std::ifstream& ifs) {
        CompanyNS::Employee employee{};

        if (!ifs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return employee;
        }

        size_t nameLength;
        ifs.read((char*)(&nameLength), sizeof(nameLength));
        employee.name = new char[nameLength + 1];

        ifs.read(employee.name, nameLength); // employee.name е char*, няма какво да cast-ваме
        employee.name[nameLength] = '\0';

        int positionInt;
        ifs.read((char*)(&positionInt), sizeof(positionInt));
        employee.position = (CompanyNS::Position)positionInt;

        ifs.read((char*)(&employee.salary), sizeof(employee.salary));
        ifs.read((char*)(&employee.grade), sizeof(employee.grade));

        return employee;
    }

    void serializeCompany(const CompanyNS::Company& company, const char* filename) {
        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return;
        }

        std::ofstream ofs(filename);
        if (!ofs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        ofs << company.employeeCnt << std::endl; // първо записваме броя на служителите
        for (size_t i = 0; i < company.employeeCnt; i++) {
            /* затова ни е удобно да изнесем логиката за сериализация на един обект, в случая Employee,
            в отделен метод - сериализацяита на Company се свежда до циклично извикване на serializeEmployee*/
            serializeEmployee(company.employees[i], ofs);
        }

        ofs << company.avgSalary << std::endl;
        ofs.close();
    }

    void serializeCompanyBinary(const CompanyNS::Company& company, const char* filename) {
        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return;
        }

        std::ofstream ofs(filename, std::ios::binary);
        if (!ofs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        ofs.write((const char*)(&company.employeeCnt), sizeof(company.employeeCnt));

        for (size_t i = 0; i < company.employeeCnt; i++) {
            /* затова ни е удобно да изнесем логиката за сериализация на един обект, в случая Employee,
            в отделен метод - сериализацяита на Company се свежда до циклично извикване на serializeEmployee*/
            serializeEmployeeBinary(company.employees[i], ofs);
        }

        ofs.write((const char*)(&company.avgSalary), sizeof(company.avgSalary));
        ofs.close();
    }

    void deserializeCompany(CompanyNS::Company& company, const char* filename) {
        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return;
        }

        std::ifstream ifs(filename);
        if (!ifs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        size_t employeeCnt;
        ifs >> employeeCnt; // първо четем броя на служителите
        for (size_t i = 0; i < employeeCnt; i++) {
            /* както и при serializeCompany, тук използваме override-натия метод, който приема поток, а не име на файл -
            ако не го бяхме направили трябаше да създаваме нов поток към същия файл за всеки Employee.
            Тук също може да видите защо не затваряме поток, подаден като аргумент на метода -
            ако го бяхме затворили в deserializeEmployee, то след първия служител потокът щеше да е затворен и нямаше да можем да прочетем следващите служители*/
            company.addEmployee(deserializeEmployee(ifs));
        }

        ifs >> company.avgSalary;
        ifs.close();
    }

    void deserializeCompanyBinary(CompanyNS::Company& company, const char* filename) {
        if (!filename) {
            std::cout << "Null filename" << std::endl;
            return;
        }

        std::ifstream ifs(filename);
        if (!ifs.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return;
        }

        size_t employeeCnt;
        ifs.read((char*)(&employeeCnt), sizeof(employeeCnt));
        for (size_t i = 0; i < employeeCnt; i++) {
            company.addEmployee(deserializeEmployeeBinary(ifs));
        }

        ifs.read((char*)(&company.avgSalary), sizeof(company.avgSalary));
        ifs.close();
    }
};
