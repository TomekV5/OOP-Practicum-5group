#include "Ward.h"

Ward::Ward(std::string& name) : name(name) { }

void Ward::addPatient(const Patient& patient) {
    for (const auto& p : patients) {
		if (p->getEgn() == patient.getEgn()) {
			return;
		}
	}

	patients.push_back(std::make_shared<Patient>(patient));
}

void Ward::removePatient(const std::string& egn) {
    std::erase_if(patients, [&egn](const std::shared_ptr<Patient>& p) { return p->getEgn() == egn; });
}

Patient* Ward::findPatient(const std::string& egn) const {
    for (const auto& p : patients) {
        if (p->getEgn() == egn) {
            return p.get();
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Ward& w) {
    os << "Ward: " << w.name << "\nPatients:\n";
    for (const auto& p : w.patients) {
        os << *p << "\n";
    }
    return os;
}

Ward& Ward::operator()(const std::string& egn, const std::string& newDiagnose) {
    Patient* patient = findPatient(egn);
    if (patient) {
        patient->setDiagnosis(newDiagnose);
    }
    return *this;
}

Ward::operator bool() const {
    return !patients.empty();
}

const std::vector<std::shared_ptr<Patient>>& Ward::getPatients() const {
    return patients;
}

size_t Ward::patientCount() const {
    return patients.size();
}

const std::string& Ward::getName() const {
    return name;
}