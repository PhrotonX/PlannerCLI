#include "CalendarController.h"

namespace PlannerCLI{
    CalendarController::CalendarController()
    {
        m_calendarView = new CalendarView();
        m_calendar = new Calendar();
        m_calendar->Seed();
    }

    CalendarController::~CalendarController()
    {
        //dtor
    }

    void CalendarController::Create(){

    }

    void CalendarController::Index(){
        m_calendarView->Display();
    }

    void CalendarController::Store(){

    }

    void CalendarController::Update(){

    }

    void CalendarController::Delete(){

    }

}
