#ifndef CALENDARCONTROLLER_H
#define CALENDARCONTROLLER_H
#include "Controller.h"
#include "CalendarView.h"
#include "Calendar.h"
#include "Date.h"
#include "EventController.h"
#include "Settings.h"

namespace PlannerCLI{
    class CalendarController : public Controller
    {
        public:
            CalendarController();
            ~CalendarController() override;

            void HandleInput() override;
            //void Create();
            void Index() override;
            //void Store();
            //void Update();
            //void Delete();

        private:
            CalendarView* m_calendarView;
            Calendar* m_calendar;

            EventController* m_eventController;
    };
}


#endif // CALENDARCONTROLLER_H
