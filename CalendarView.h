#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H
#include "Year.h"
#include "Month.h"
#include "View.h"
#include "Day.h"
#include "Date.h"
#include "DayOfTheWeek.h"
//#include "ArrayYear.h"

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

            void Display(int year, int month, int day);

            void SetNavigatedDate(Date* navigatedDate) {
                m_pnDate = navigatedDate;
            }
        protected:
            void DisplayHelpInfo() override;

            virtual void OnDisplayTitle();
            virtual void OnDisplayDaysOfTheWeek();
            virtual void OnDisplayCalendarDays();
            virtual void OnDisplayBottomBorder();
        private:
            //Used for normal Zeller's Congruence Algorithm-based Calendar.
            Date* m_pnDate;

            //Used for limited array-based calendar.
            //ArrayYear* m_pCalendar = nullptr;
    };

}

#endif // CALENDARVIEW_H
