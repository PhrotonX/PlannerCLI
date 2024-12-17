#ifndef TODOLIST_H
#define TODOLIST_H

#include "Model.h"
#include "ToDo.h"
#include <queue>
#include <fstream>

namespace PlannerCLI {

    class ToDoList : public Model {
    public:
        void AddToDo(ToDo todo) {
            m_todoQueue.push(todo);
        }

        void RemoveToDo();

        ToDo ViewToDo();

        std::queue<ToDo> GetToDoList() {
            return m_todoQueue;
        }

        void UpdateToDoDescription(std::string newDescription);

        void Load();

        void Save();

    private:
        std::queue<ToDo> m_todoQueue;
    };

}

#endif
