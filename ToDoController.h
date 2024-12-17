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

    void Index() override {
        HandleInput();
    }

    void HandleInput() override;

    void Load() override {
        m_todoList.Load();
    }

    void Store() override {
        m_todoList.Save();
    }

private:
    ToDoList m_todoList;
    ToDoView m_view;

    void Create();

    void ViewTask();

    void UpdateTask();

    void DisplayAllTasks();

    void RemoveTask();
};

}

#endif 
