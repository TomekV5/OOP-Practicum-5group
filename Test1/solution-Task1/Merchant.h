#include <iostream>
#pragma once
#pragma warning(disable:4996)

class Merchant {
private:
    static constexpr unsigned int NAME_LENGTH = 1024;
    static int idCounter;

    char name[NAME_LENGTH + 1];
    int id;
    double income;
    double dailyIncome;

public:
    Merchant(const char* name, double income, double dailyIncome);
    friend std::ostream& operator<<(std::ostream& os, const Merchant& merchant);
    auto operator<=>(const Merchant& other) const;

    double getIncome() const;
    int getId() const;

    Merchant& operator++();
	Merchant operator++(int dummy);
};

