#ifndef EVENTcONTROLLER_H
#define EVENTcONTROLLER_H
#include "Controller.h"
#include "Event.h"
#include "EventView.h"
#include "EventManager.h"
#include "AddEventController.h"
#include "Date.h"
#include <functional>

namespace PlannerCLI {
    class EventController : public Controller
    {
    public:
        EventController();
        ~EventController() override;
        // Inherited via Controller
        void HandleInput() override;
        void Create(Date date, std::function<void()> saveFunction);
        void Index();
        void Index(Date date);
        void Store();
        void Update(const Event& event, Date date);
        void Delete();

    private:
        EventView* m_eventView;
        EventManager* m_eventManager;

        AddEventController* m_addEventController;
    };

    
}

#endif //EVENTcONTROLLER_H