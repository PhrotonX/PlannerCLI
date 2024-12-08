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

    void CalendarController::HandleInput(){
        /*bool isRunning = true;
        char choice;
        do{
            choice = getch();

            switch(choice){
            case 'A':
            default:
                break;
            }
        }while(isRunning);*/
    }

    void CalendarController::Index(){
        Date* currentDate = Date::GetCurrentDate();

        Year currentYear = currentDate->GetYear();
        Month currentMonth = currentDate->GetMonth();

        Date* firstDayOfTheMonth = new Date(currentYear.GetValue(), currentMonth.GetValueN(), 1);

        int dayOfTheWeek = firstDayOfTheMonth->CalculateDayOfTheWeek();
        firstDayOfTheMonth->GetDay().SetDayOftheWeek(dayOfTheWeek);

        m_calendarView->DisplayNew(firstDayOfTheMonth);

    }

    void CalendarController::Store(){

    }

    void CalendarController::Update(){

    }

    void CalendarController::Delete(){

    }

}
