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

        void UpdateToDoDescription(std::string newDescription){
            if (!m_todoQueue.empty()) {
            ToDo updated = m_todoQueue.front();
            updated.SetDescription(newDescription);
            m_todoQueue.pop();
            m_todoQueue.push(updated);
            }
        }

        void Load(){
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

        void Save(){
            std::ofstream file("todo.txt");
            std::queue<ToDo> tempQueue = m_todoQueue;

            while (!tempQueue.empty()) {
                ToDo task = tempQueue.front();
                file << task.GetDescription() << ";" << task.GetPriority() << "\n";
                tempQueue.pop();
            }
        file.close();
        }

    private:
        std::queue<ToDo> m_todoQueue;
    };

}

#endif
