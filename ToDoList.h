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

        void RemoveToDo();

        ToDo ViewToDo();

        std::queue<ToDo> GetToDoList() {
            return m_todoQueue;
        }

        void UpdateToDoDescription(std::string newDescription);

        /**
            \brief Load information from a file.
        */
        void Load() override;

        /**
            \details Save information into a file.
        */
        void Save() override;
    private:
        std::queue<ToDo> m_todoQueue;
    };

}

#endif
