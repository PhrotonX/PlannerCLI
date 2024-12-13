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
        
        void Index(Date date);
        void Search(Date date);
        

    protected:
        void Create(Date date);
        void Index();
        void Update(size_t position);
        void Delete(size_t position);

    private:
        EventView* m_eventView;
        EventManager* m_eventManager;

        AddEventController* m_addEventController;

        std::vector<Event> m_event;
        Date m_date;
    };

    
}

#endif //EVENTcONTROLLER_H