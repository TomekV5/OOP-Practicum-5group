#include "Status.h"

std::ostream& operator<<(std::ostream& os, Status s)
{
    switch (s)
    {
        case Status::TODO:
            os << "Todo";
            break;
        case Status::IN_PROGRESS:
            os << "In progress";
            break;
        case Status::DONE:
            os << "Done";
            break;
    }
    return os;
}