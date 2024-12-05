#include "App.h"

namespace PlannerCLI{
    App::App()
    {
        //ctor
    }

    App::~App()
    {
        //dtor
    }

    void App::Run(){
        m_calendarController = new CalendarController();
        m_calendarController->Index();
    }

    void App::Close(){
        m_calendarController = nullptr;
        delete m_calendarController;
    }
}
