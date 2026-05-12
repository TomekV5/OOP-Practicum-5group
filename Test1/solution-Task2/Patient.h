#include <iostream>
#include <vector>
#pragma once
#include <cstring>

class Patient {
private:
    std::string name;
    std::string egn;
    std::string diagnosis;
    int roomNumber;
    
public:
    Patient(std::string& name, std::string& egn, std::string& diagnosis, int roomNumber);

    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
    auto operator<=>(const Patient& other) const;

    const std::string& getName() const;
    const std::string& getEgn() const;
    const std::string& getDiagnosis() const;

    void setDiagnosis(const std::string& diagnosis);
};