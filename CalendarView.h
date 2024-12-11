#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H
#include "Year.h"
#include "Month.h"
#include "View.h"
#include "Day.h"
#include "Date.h"

namespace PlannerCLI{
    class CalendarView : public View
    {
        public:
            inline static const int CALENDAR_WIDTH = 50;
            inline static const int DAYS_OF_THE_WEEK = 7;
            inline static const int ITEM_WIDTH = 7;
            inline static const int ITEM_HEIGHT = 3;

            CalendarView(Date* navigatedDate);
            ~CalendarView() override;

            void Display();

            void SetNavigatedDate(Date* navigatedDate) {
                m_pnDate= navigatedDate;
            }
        private:
            Date* m_pnDate;
    };

}

#endif // CALENDARVIEW_H
