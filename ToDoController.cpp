#include "ToDoController.h"

namespace PlannerCLI {
	void ToDoController::HandleInput()
	{
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

    void ToDoController::Create()
    {
        ToDo newTask = m_view.ShowCreateScreen();
        m_todoList.AddToDo(newTask);
        m_view.ShowMessage("Task added successfully.");
    }

    void ToDoController::ViewTask()
    {
        ToDo task = m_todoList.ViewToDo();
        m_view.ShowTask(task);
    }

    void ToDoController::UpdateTask()
    {
        std::string newDescription = m_view.ShowUpdateScreen();
        m_todoList.UpdateToDoDescription(newDescription);
        m_view.ShowMessage("Task updated successfully.");
    }

    void ToDoController::DisplayAllTasks()
    {
        m_view.ShowAllTasks(m_todoList.GetToDoList());
    }

    void ToDoController::RemoveTask()
    {
        m_todoList.RemoveToDo();
        m_view.ShowMessage("First task removed.");
    }
}