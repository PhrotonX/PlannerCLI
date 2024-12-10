#include "CalendarController.h"

namespace PlannerCLI{
    CalendarController::CalendarController()
    {
        m_calendarView = new CalendarView();
        m_calendar = new Calendar();

        m_calendarView->SetNavigatedDay(m_calendar->GetNavigatedDay());
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
            default:
                switch (_getch()) {
                case KEY_UP:
                    m_calendar->OnNavigateDayUp();
                    break;
                case KEY_LEFT:
                    m_calendar->OnNavigateDayLeft();
                    break;
                case KEY_RIGHT:
                    m_calendar->OnNavigateDayRight();
                    break;
                case KEY_DOWN:
                    m_calendar->OnNavigateDayDown();
                    break;
                default:
                    break;
                }
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
