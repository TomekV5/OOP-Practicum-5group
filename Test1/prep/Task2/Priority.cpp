#include "Priority.h"

std::ostream& operator<<(std::ostream& os, Priority priority)
{
    switch (priority)
    {
    case Priority::LOW:
        os << "Low";
        break;
    case Priority::MEDIUM:
        os << "Medium";
        break;
    case Priority::HIGH:
        os << "High";
        break;
    }
    return os;
}
