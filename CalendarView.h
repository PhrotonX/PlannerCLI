#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H
#include "Month.h"
#include "View.h"

namespace PlannerCLI{
    class CalendarView : View
    {
        public:
            inline static const int CALENDAR_WIDTH = 42;

            CalendarView();
            ~CalendarView() override;

            void Display() override;

            void Display(Month*& month);

        private:
    };

}

#endif // CALENDARVIEW_H
