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

            Date date;

            switch(choice){
            case 'A':
            case 'a':
                date = m_calendar->OnNavigatePrevMonth();
                break;
            case 'D':
            case 'd':
                date = m_calendar->OnNavigateNextMonth();
                break;
            case 'Q':
            case 'q':
                isRunning = false;
                break;
            case KEY_LEFT:
                
            default:
                break;
            }

            m_calendarView->Display(date);

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
