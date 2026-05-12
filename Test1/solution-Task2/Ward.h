#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Patient.h"

class Ward {
private:
    std::string name;
    std::vector<std::shared_ptr<Patient>> patients;

public:
    Ward(std::string& name);

    void addPatient(const Patient& patient);
    void removePatient(const std::string& egn);
    Patient* findPatient(const std::string& egn) const;

    friend std::ostream& operator<<(std::ostream& os, const Ward& w);
    operator bool() const;
    Ward& operator()(const std::string& egn, const std::string& newDiagnose);

    const std::vector<std::shared_ptr<Patient>>& getPatients() const;
	size_t patientCount() const;
	const std::string& getName() const;
};