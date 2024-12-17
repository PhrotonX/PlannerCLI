#include "CalendarController.h"

namespace PlannerCLI{
    CalendarController::CalendarController()
    {
        m_calendar = new Calendar();
        m_calendarView = new CalendarView(m_calendar->GetNavigatedDate());
        
        m_eventController = new EventController();
    }

    CalendarController::~CalendarController()
    {
        //Delete m_calendarView first since it has a pointer to an instance of m_calendar.
        if (m_calendarView != nullptr) delete m_calendarView;
        if(m_calendar != nullptr) delete m_calendar;
        m_calendarView = nullptr;
        m_calendar = nullptr;
    }

    /*void CalendarController::Create() {

    }*/

    void CalendarController::HandleInput(){
        bool isRunning = true;

        do{
            m_calendarView->Display();
            m_eventController->IndexWidget(*m_calendar->GetNavigatedDate());
            m_calendarView->DisplayHelp();

            Date date;

            switch(_getch()){
            case 'A':
            case 'a':
                m_calendar->OnNavigatePrevMonth(); 
                break;
            case 'D':
            case 'd':
                m_calendar->OnNavigateNextMonth();
                break;
            case KEY_ESC:
                isRunning = false;
                break;
            case KEY_ENTER:
                m_eventController->Index(*m_calendar->GetNavigatedDate());
                break;
            case 'S':
            case 's':
                m_eventController->Search();
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

            //m_calendar->Debug();

        }while(isRunning);
    }

    void CalendarController::Index(){
        m_calendar->OnNavigateInit();
        HandleInput();

        if(Settings::DebugMode) m_calendar->Debug();
    }

    void CalendarController::Load() {
        m_eventController->Load();
    }
    
    void CalendarController::Store(){
        m_eventController->Store();
    }

}
