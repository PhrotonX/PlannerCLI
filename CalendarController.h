#ifndef CALENDARCONTROLLER_H
#define CALENDARCONTROLLER_H
#include "Controller.h"
#include "CalendarView.h"
#include "Calendar.h"
#include "Date.h"

namespace PlannerCLI{
    class CalendarController : public Controller
    {
        public:
            CalendarController();
            ~CalendarController() override;

            void Create() override;
            void Index() override;
            void Store() override;
            void Update() override;
            void Delete() override;

        private:
            CalendarView* m_calendarView;
            Calendar* m_calendar;
    };
}


#endif // CALENDARCONTROLLER_H
