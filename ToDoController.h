#ifndef TODOCONTROLLER_H
#define TODOCONTROLLER_H

#include "Controller.h"
#include "ToDoList.h"
#include "ToDoView.h"

namespace PlannerCLI {

class ToDoController : public Controller {
public:
    ToDoController() {}
    ~ToDoController() override {}

    void Init() override {
        HandleInput();
    }

    void HandleInput() override {
        bool run = true;
        while (run) {
            m_view.Display();

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    Create();
                    break;
                case 2:
                    ViewTask();
                    break;
                case 3:
                    UpdateTask();
                    break;
                case 4:
                    DisplayAllTasks();
                    break;
                case 5:
                    RemoveTask();
                    break;
                case 6:
                    run = false;
                    break;
                default:
                    m_view.ShowMessage("Invalid choice. Please try again.");
            }
        }
    }

    void Load() override {}
    void Store() override {}

private:
    ToDoList m_todoList;
    ToDoView m_view;

    void Create() {
        ToDo newTask = m_view.ShowCreateScreen();
        m_todoList.AddToDo(newTask);
        m_view.ShowMessage("Task added successfully.");
    }

    void ViewTask() {
        ToDo task = m_todoList.ViewToDo();
        m_view.ShowTask(task);
    }

    void UpdateTask() {
        std::string newDescription = m_view.ShowUpdateScreen();
        m_todoList.UpdateToDoDescription(newDescription);
        m_view.ShowMessage("Task updated successfully.");
    }

    void DisplayAllTasks() {
        m_view.ShowAllTasks(m_todoList.GetToDoList());
    }

    void RemoveTask() {
        m_todoList.RemoveToDo();
        m_view.ShowMessage("First task removed.");
    }
};

}

#endif 
