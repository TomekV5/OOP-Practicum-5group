#pragma once
#include "User.h"
#include <vector>
#include <memory>

class TaskManager {
    std::vector<User> users;
    std::vector<std::shared_ptr<Task>> tasks;
public:

    void addUser(const std::string& name);    
    void removeUser(const std::string& name);    
    void addTask(const Task& task, const std::string& name);
    void addTask(const Task& task);
    void removeTask(int id, const std::string& name);
    void removeTask(int id);
    std::weak_ptr<Task> findTask(int id, const std::string& name) const;
    std::weak_ptr<Task> findTask(int id) const;
    void printByName(const std::string& name) const;
    void printByEndDate(const Date& date) const;
    void printAsc(const Date& date) const;
    void printInterval(const Date& from, const Date& to) const;
    void printByStatus(Status status) const;
};