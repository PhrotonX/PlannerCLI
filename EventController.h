#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H
#include "Controller.h"
#include "Event.h"
#include "EventView.h"
#include "EventManager.h"
#include "AddEventController.h"
#include "SearchEventView.h"
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
        void Search();
        

    protected:
        void Create(Date date);
        void Index();
        void Update(size_t position);
        void Delete(size_t position);

    private:
        AddEventController* m_addEventController;

        bool m_bIsSearching;

        Date m_date;

        std::vector<Event> m_event;

        EventManager* m_eventManager;
        EventView* m_eventView;

        int m_nNavigation;
        int m_nEventNavigation;

        std::string m_strSearchQuery;
    };

    
}

#endif //EVENTCONTROLLER_H