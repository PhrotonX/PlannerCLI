#ifndef TODOVIEW_H
#define TODOVIEW_H

#include "ToDo.h"
#include <iostream>
#include <queue>

namespace PlannerCLI {

class ToDoView {
public:
    void Display() {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Task\n";
        std::cout << "3. Update Task\n";
        std::cout << "4. Display All Tasks\n";
        std::cout << "5. Remove Task\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
    }
    
    ToDo ShowCreateScreen() {
        std::string description;
        int priority;

        std::cout << "Enter task description: ";
        std::cin.ignore();
        std::getline(std::cin, description);

        std::cout << "Enter task priority: ";
        std::cin >> priority;

        return ToDo(description, priority);
    }

    void ShowTask(ToDo task) {
        std::cout << "Task: " << task.GetDescription() << " | Priority: " << task.GetPriority() << std::endl;
    }

    void ShowAllTasks(std::queue<ToDo> todoQueue) {
        if (todoQueue.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }
        while (!todoQueue.empty()) {
            ToDo task = todoQueue.front();
            ShowTask(task);
            todoQueue.pop();
        }
    }

    std::string ShowUpdateScreen() {
        std::string newDescription;
        std::cout << "Enter new description for the first task: ";
        std::cin.ignore();
        std::getline(std::cin, newDescription);
        return newDescription;
    }

    void ShowMessage(std::string message) {
        std::cout << message << std::endl;
    }
};

} 

#endif
