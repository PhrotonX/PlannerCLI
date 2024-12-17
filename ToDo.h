#ifndef TODO_H
#define TODO_H

#include <string>

namespace PlannerCLI {

class ToDo {
    public:
        ToDo(std::string description = "No task", int priority = 0)
            : m_strDescription(description), m_nPriority(priority) {}

        std::string GetDescription() {
            return m_strDescription;
        
        }
        void SetDescription(std::string description) {
            m_strDescription = description;
        }

        int GetPriority() {
            return m_nPriority;
        }
        void SetPriority(int priority) {
            m_nPriority = priority;
        }

    private:
        std::string m_strDescription;
        int m_nPriority;
    };

}

#endif 
