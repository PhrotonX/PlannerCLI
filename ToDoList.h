#ifndef TODOLIST_H
#define TODOLIST_H

#include "Model.h"
#include "ToDo.h"
#include <queue>

namespace PlannerCLI {

class ToDoList : public Model {
public:
    void AddToDo(ToDo todo) {
        m_todoQueue.push(todo);
    }

    void RemoveToDo() {
        if (!m_todoQueue.empty()) {
            m_todoQueue.pop();
        }
    }

    ToDo ViewToDo() {
        if (!m_todoQueue.empty()) {
            return m_todoQueue.front();
        }
        return ToDo();
    }

    std::queue<ToDo> GetToDoList() {
        return m_todoQueue;
    }

    void UpdateToDoDescription(std::string newDescription) {
        if (!m_todoQueue.empty()) {
            ToDo updated = m_todoQueue.front();
            updated.SetDescription(newDescription);
            m_todoQueue.pop();
            m_todoQueue.push(updated);
        }
    }

private:
    std::queue<ToDo> m_todoQueue;
};

}

#endif
