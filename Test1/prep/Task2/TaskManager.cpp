#include "TaskManager.h"
#include <iostream>
#include <algorithm>

void TaskManager::addUser(const std::string& name)
{
    users.push_back({ name });
}

void TaskManager::removeUser(const std::string& name)
{
    std::erase_if(users, [&name](const User& user) {
        return user.name == name;
    });
}

void TaskManager::addTask(const Task& task, const std::string& name)
{
    auto newTask = std::make_shared<Task>(task);
    tasks.push_back(newTask);

    for (auto& user : users) {
        if (user.name == name) {
            user.tasks.push_back(newTask);
            return;
        }
    }
}

void TaskManager::addTask(const Task& task)
{
    auto newTask = std::make_shared<Task>(task);
    tasks.push_back(newTask);

    for (auto& user : users) {
        user.tasks.push_back(newTask);
    }
}

void TaskManager::removeTask(int id, const std::string& name)
{
    for (auto& user : users) {
        if (user.name == name) {
            std::erase_if(user.tasks, [id](const std::weak_ptr<Task>& task) {
                auto t = task.lock();
                return !t || t->getId() == id;
            });
            return;
        }
    }
}

void TaskManager::removeTask(int id)
{
    std::erase_if(tasks, [id](const std::shared_ptr<Task>& task) {
        return task->getId() == id;
    });
}

std::weak_ptr<Task> TaskManager::findTask(int id) const
{
    for (auto& task : tasks) {
        if (task->getId() == id) {
            return task;
        }
    }
    return {};
}

std::weak_ptr<Task> TaskManager::findTask(int id, const std::string& name) const
{
    for (auto& user : users) {
        if (user.name == name) {
            for (auto& task : user.tasks) {
                if (auto t = task.lock(); t && t->getId() == id) {
                    return task;
                }
            }
            return {};
        }
    }
    return {};
}

void TaskManager::printByName(const std::string& name) const
{
    for (auto& user : users) {
        if (user.name == name) {
            for (auto& task : user.tasks) {
                if (auto t = task.lock()) {
                    std::cout << *t << std::endl;
                }
            }
            return;
        }
    }
}

void TaskManager::printByEndDate(const Date& date) const
{
    for (auto& task : tasks) {
        if (task->getDeadline() == date) {
            std::cout << *task << std::endl;
        }
    }
}

void TaskManager::printAsc(const Date& date) const
{
    std::vector<std::shared_ptr<Task>> filtered(tasks.begin(), tasks.end());

    std::sort(filtered.begin(), filtered.end(), [](const auto& a, const auto& b) {
        return a->getName() < b->getName();
    });

    for (auto& task : filtered) {
        std::cout << *task << "\n";
    }
}

void TaskManager::printInterval(const Date& from, const Date& to) const
{
    for (auto& task : tasks) {
        const Date& d = task->getDeadline();
        if (d >= from && d <= to) {
            std::cout << *task << std::endl;
        }
    }
}

void TaskManager::printByStatus(Status status) const
{
    for (auto& task : tasks) {
        if (task->getStatus() == status) {
            std::cout << *task << std::endl;
        }
    }
}
