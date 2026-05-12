#include "Merchant.h"

int Merchant::idCounter = 0;

Merchant::Merchant(const char* name, double income, double dailyIncome) : id(++idCounter), income(income), dailyIncome(dailyIncome) {
    strcpy(this->name, name);
    this->name[NAME_LENGTH] = '\0';
}

auto Merchant::operator<=>(const Merchant& other) const {
    return this->income <=> other.income;
}

std::ostream& operator<<(std::ostream& os, const Merchant& merchant) {
    os << "Merchant: " << merchant.name << ", Income: " << merchant.income << ", Daily Income: " << merchant.dailyIncome;
    return os;
}

double Merchant::getIncome() const {
    return income;
}

int Merchant::getId() const {
    return id;
}

Merchant& Merchant::operator++() {
    income += dailyIncome;
    return *this;
}

Merchant Merchant::operator++(int dummy) {
    Merchant temp = *this;
    income += dailyIncome;
    return temp;
}