#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H
#include "View.h"

namespace PlannerCLI{
    class CalendarView : View
    {
        public:
            CalendarView();
            ~CalendarView() override;

            void Display() override;

        private:
    };

}

#endif // CALENDARVIEW_H
