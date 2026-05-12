#include "Task.h"
#include "Priority.h"
#include "Status.h"

int Task::idCounter = 0;


std::ostream& operator<<(std::ostream& os, const Task& task)
{
    os << "[#" << task.id << "] " << task.name
       << " | deadline: " << task.deadline
       << " | " << task.status
       << " | " << task.priority
       << "\n   " << task.description;
       
    return os;
}

Task::Task(const std::string& name,
    const std::string description,
    Date deadline,
    Status status,
    Priority priority) 
        : id(idCounter),
        name(name),
        description(description),
        deadline(deadline),
        status(status),
        priority(priority)
{
    idCounter++;

}

int Task::getId() const
{
    return id;
}

const std::string& Task::getName() const
{
    return name;
}

const Date& Task::getDeadline() const 
{ 
    return deadline; 
}

Status Task::getStatus() const 
{
     return status; 
}

Priority Task::getPriority() const 
{ 
    return priority; 
}