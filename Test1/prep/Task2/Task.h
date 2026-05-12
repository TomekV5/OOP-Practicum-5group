#pragma once
#include <string>
#include "Date.h"
#include "Priority.h"
#include "Status.h"

class Task {
    static int idCounter;

    int id;
    std::string name;
    std::string description;
    Date deadline;
    Status status;
    Priority priority;

public: 
    Task(const std::string& name,
        const std::string description,
        Date deadline,
        Status status,
        Priority priority);


    friend std::ostream& operator<<(std::ostream& os, const Task& task);

    int getId() const;
    const std::string& getName() const;
    const Date& getDeadline() const;
    Status getStatus() const;
    Priority getPriority() const;
};