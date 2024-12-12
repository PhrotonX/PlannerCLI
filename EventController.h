#ifndef EVENTcONTROLLER_H
#define EVENTcONTROLLER_H
#include "Controller.h"
#include "Event.h"
#include "EventView.h"
#include "EventManager.h"
#include "AddEventView.h"
#include "Date.h"

namespace PlannerCLI {
    class EventController : public Controller
    {
    public:
        EventController();
        ~EventController() override;
        // Inherited via Controller
        void HandleInput() override;
        void Create(Date date);
        void Index() override;
        void Index(Date date);
        void Store();
        void Update();
        void Delete();

    private:
        EventView* m_eventView;
        EventManager* m_eventManager;
    };

    
}

#endif //EVENTcONTROLLER_H