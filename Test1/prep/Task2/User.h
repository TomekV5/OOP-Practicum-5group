#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Task.h"

struct User {
    std::string name; 
    std::vector<std::weak_ptr<Task>> tasks;
};