#include "Hospital.h"

Hospital &Hospital::getInstance() {
    static Hospital instance;
    return instance;
}

void Hospital::addWard(const std::string &name) {
    wards.emplace_back(name);
}

void Hospital::removeWard(const std::string& name) {
    std::erase_if(wards, [&name](const Ward& w){ return w.getName() == name; });
}

Ward& Hospital::operator[](const std::string &name) {
    for (auto& w : wards) {
        if (w.getName() == name) {
            return w;
        }
   }
   return wards.emplace_back(name);  // Optional : If not found, add a new ward with the given name and return it
}

std::vector<Ward> Hospital::findPatientInWards(const std::string &egn) const {
    std::vector<Ward> result;
    for (const auto& w : wards) {
        if (w.findPatient(egn)) {
            result.push_back(w);
        }
    }
    return result;
}

size_t Hospital::totalPatients() const {
    size_t res = 0;
    for (const auto& ward : wards) {
        res += ward.patientCount();
    }
    return res;
}

std::ostream &operator<<(std::ostream &os, const Hospital &h) {
    os << "Hospital: " << h.name << "\n";
    for (const auto& w : h.wards) {
        os << w << "\n";
    }
    return os;
}

Hospital::operator bool() const {
    if (wards.empty()) return false;
    
    size_t total = 0;
    for (const auto& ward : wards) {
        total += ward.patientCount();
    }
    return (total / wards.size()) > 20;
}