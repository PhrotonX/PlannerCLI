#include "ToDoList.h"

namespace PlannerCLI {
    void ToDoList::RemoveToDo(){
        if (!m_todoQueue.empty()) {
            m_todoQueue.pop();
        }
    }

    ToDo ToDoList::ViewToDo()
    {
        if (!m_todoQueue.empty()) {
            return m_todoQueue.front();
        }
        return ToDo();
    }

    void ToDoList::UpdateToDoDescription(std::string newDescription){
        if (!m_todoQueue.empty()) {
            ToDo updated = m_todoQueue.front();
            updated.SetDescription(newDescription);
            m_todoQueue.pop();
            m_todoQueue.push(updated);
        }
	}

    void ToDoList::Load()
    {
        std::ifstream file("todo.txt");
        std::string description;
        int priority;

        m_todoQueue = {};

        while (file.good()) {
            getline(file, description, ';');
            file >> priority;
            file.ignore();

            if (!description.empty()) {
                m_todoQueue.push(ToDo(description, priority));
            }
        }
        file.close();
    }

    void ToDoList::Save()
    {
        std::ofstream file("todo.txt");
        std::queue<ToDo> tempQueue = m_todoQueue;

        while (!tempQueue.empty()) {
            ToDo task = tempQueue.front();
            file << task.GetDescription() << ";" << task.GetPriority() << "\n";
            tempQueue.pop();
        }
        file.close();
    }
}

