#ifndef TODOVIEW_H
#define TODOVIEW_H

#include "ToDo.h"
#include <iostream>
#include <queue>
#include "View.h"

namespace PlannerCLI {

class ToDoView : public View{
    public:
        ToDoView() {}
        ~ToDoView() override {}

        void Display();
    
        ToDo ShowCreateScreen();

        void ShowTask(ToDo task) {
            std::cout << "Task: " << task.GetDescription() << " | Priority: " << task.GetPriority() << std::endl;
        }

        void ShowAllTasks(std::queue<ToDo> todoQueue);

        std::string ShowUpdateScreen();

        void ShowMessage(std::string message) {
            std::cout << message << std::endl;
        }

    protected:
        void DisplayHelpInfo() override {}
    };

} 

#endif
