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
        bool isRunning = true;
        char choice;
        do{
            choice = _getch();

            switch(choice){
            case 'A':
            default:
                break;
            }
        }while(isRunning);
    }

    void CalendarController::Index(){
        Date date = m_calendar->OnNavigateInit();
        m_calendarView->Display(date);
    }

    void CalendarController::Store(){

    }

    void CalendarController::Update(){

    }

    void CalendarController::Delete(){

    }

}
