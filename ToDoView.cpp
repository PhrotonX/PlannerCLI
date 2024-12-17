#include "ToDoView.h"

namespace PlannerCLI {
	void ToDoView::Display()
	{
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Task\n";
        std::cout << "3. Update Task\n";
        std::cout << "4. Display All Tasks\n";
        std::cout << "5. Remove Task\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
	}

    ToDo ToDoView::ShowCreateScreen()
    {
        std::string description;
        int priority;

        std::cout << "Enter task description: ";
        std::cin.ignore();
        std::getline(std::cin, description);

        std::cout << "Enter task priority (int): ";
        std::cin >> priority;

        std::cout << "Added to the queue!";

        return ToDo(description, priority);
    }

    void ToDoView::ShowAllTasks(std::queue<ToDo> todoQueue)
    {
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

    std::string ToDoView::ShowUpdateScreen()
    {
        std::string newDescription;
        std::cout << "Enter new description for the first task: ";
        std::cin.ignore();
        std::getline(std::cin, newDescription);

        std::cout << "Successfully updated!";

        return newDescription;
    }
}