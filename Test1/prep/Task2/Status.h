#pragma once
#include <ostream>

enum class Status
{
    TODO,
    IN_PROGRESS,
    DONE
};

std::ostream& operator<<(std::ostream& os, Status s);