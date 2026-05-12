#pragma once
#include <ostream>

enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

std::ostream& operator<<(std::ostream& os, Priority priority);