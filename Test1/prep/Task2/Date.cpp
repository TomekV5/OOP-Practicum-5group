#include "Date.h"
#include <compare>

std::strong_ordering Date::operator<=>(const Date& other) const
{
    auto compResult = year <=> other.year;
    if (compResult != 0) {
        return compResult;
    }

    compResult = month <=> other.month;
    if (compResult != 0) {
        return compResult;
    }

    return day <=> other.day;
}

bool Date::operator==(const Date& other) const
{
    return year == other.year
        && month == other.month
        && day == other.day;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    return os << date.year << "/" << date.month << "/" << date.year;
}
