#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include "Patient.h"
#include "Ward.h"

class Hospital {
private:
    std::string name;
    std::vector<Ward> wards;

    Hospital() = default;   // Singleton
public:
    Hospital(const Hospital&) = delete;             // Singleton
	Hospital operator=(const Hospital&) = delete;   // Singleton

	static Hospital& getInstance();     // Singleton

	void addWard(const std::string& name);
	void removeWard(const std::string& name);

	Ward& operator[](const std::string& name);
	std::vector<Ward> findPatientInWards(const std::string& egn) const;

	size_t totalPatients() const;
	friend std::ostream& operator<<(std::ostream& os, const Hospital& h);
	operator bool() const;
};