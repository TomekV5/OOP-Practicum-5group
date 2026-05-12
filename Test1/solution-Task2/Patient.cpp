#include "Patient.h"

Patient::Patient(std::string& name, std::string& egn, std::string& diagnosis, int roomNumber) :
    name(name), egn(egn), diagnosis(diagnosis), roomNumber(roomNumber) {}

std::ostream &operator<<(std::ostream& os, const Patient& patient) {
    os << "Name: " << patient.name
		<< "EGN: " << patient.egn
		<< "Diagnose: " << patient.diagnosis
		<< "Room Number: " << patient.roomNumber;
	return os;
};

auto Patient::operator<=>(const Patient& other) const {
    return this->egn <=> other.egn;
}

const std::string& Patient::getName() const {
    return name;
}

const std::string& Patient::getEgn() const {
    return egn;
}

const std::string& Patient::getDiagnosis() const {
    return diagnosis;
}

void Patient::setDiagnosis(const std::string& diagnosis) {
    this->diagnosis = diagnosis;
}