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
    }

    void ToDoList::Save()
    {
    }
}

