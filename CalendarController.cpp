#include "CalendarController.h"

namespace PlannerCLI{
    CalendarController::CalendarController()
    {
        m_calendar = new Calendar();
        m_calendarView = new CalendarView(m_calendar->GetNavigatedDate());
    }

    CalendarController::~CalendarController()
    {
        //Delete m_calendarView first since it has a pointer to an instance of m_calendar.
        if(m_calendarView != nullptr) delete m_calendarView;
        if(m_calendar != nullptr) delete m_calendar;
        m_calendarView = nullptr;
        m_calendar = nullptr;
    }

    /*void CalendarController::Create() {

    }*/

    void CalendarController::HandleInput(){
        bool isRunning = true;
        char choice;
        do{
            choice = _getch();

            Date date;

            switch(choice){
            case 'A':
            case 'a':
                m_calendar->OnNavigatePrevMonth(); 
                break;
            case 'D':
            case 'd':
                m_calendar->OnNavigateNextMonth();
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

            m_calendarView->Display();

            m_calendar->Debug();

        }while(isRunning);
    }

    void CalendarController::Index(){
        m_calendar->OnNavigateInit();
        m_calendarView->Display();

        m_calendar->Debug();
    }

    /*
    void CalendarController::Store(){

    }

    void CalendarController::Update(){

    }

    void CalendarController::Delete(){

    }*/

}
