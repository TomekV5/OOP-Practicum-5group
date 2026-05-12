#pragma once
#include <compare>
#include <ostream>

struct Date {
    int day;
    int month;
    int year;

public:
    std::strong_ordering operator<=>(const Date& o) const;
    bool operator==(const Date& o) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};