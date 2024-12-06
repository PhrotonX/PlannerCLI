#include "CalendarController.h"

namespace PlannerCLI{
    CalendarController::CalendarController()
    {
        m_calendarView = new CalendarView();
        m_calendar = new Calendar();
    }

    CalendarController::~CalendarController()
    {

    }

    void CalendarController::Create(){

    }

    void CalendarController::Index(){
        Date* currentDate = Date::GetCurrentDate();

        int currentDate_dayOfTheWeek = currentDate->CalculateDayOfTheWeek();

        Year* currentYear = std::move(currentDate->GetYear());
        Month* currentMonth = std::move(currentDate->GetMonth());

        Date* firstDayOfTheMonth = new Date(currentYear->GetValue(), currentMonth->GetValueN(), 1);
        int firstDayOfTheMonth_dayOfTheWeek = firstDayOfTheMonth->CalculateDayOfTheWeek();

        Month* month = new Month(currentMonth->GetValueN() - 1);
        month->Populate(firstDayOfTheMonth_dayOfTheWeek, firstDayOfTheMonth->GetYear()->IsLeapYear());

        //@TODO: Add manual memory management.
        //delete currentDate;
        //delete firstDayOfTheMonth;
        //currentDate = nullptr;
        //firstDayOfTheMonth = nullptr;

        m_calendarView->Display();

    }

    void CalendarController::Store(){

    }

    void CalendarController::Update(){

    }

    void CalendarController::Delete(){

    }

}
