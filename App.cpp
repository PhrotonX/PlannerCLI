#include "App.h"

namespace PlannerCLI{
    App::App()
    {
        //ctor
        m_calendarController = new CalendarController();
    }

    App::~App()
    {
        //dtor
    }

    void App::Run(){
        do{
             int choice = 0;

            //Replace with either Mouse click or Arrow keys
            std::cout << "ษอออออออออออออออออออออออออออป" << std::endl;
            std::cout << "บ                           บ" << std::endl;
            std::cout << "บ         PlannerCLI        บ" << std::endl;
            std::cout << "บ                           บ" << std::endl;
            std::cout << "บ   Choose an option:       บ" << std::endl;
            std::cout << "บ   ======================  บ" << std::endl;
            std::cout << "บ   1. Show Calendar        บ" << std::endl;
            std::cout << "บ   2. Save Information     บ" << std::endl;
            std::cout << "บ   3. Settings             บ" << std::endl;
            std::cout << "บ   4. Help                 บ" << std::endl;
            std::cout << "บ   5. Exit                 บ" << std::endl;
            std::cout << "บ                           บ" << std::endl;
            std::cout << "ศอออออออออออออออออออออออออออผ" << std::endl;
            std::cout << "บ Choice:                   บ" << std::endl;

            std::cin >> choice;

            switch(choice){
            case APP_SHOW_CALENDAR:
                m_calendarController->Index();
                break;
            case APP_EXIT:
                //@TODO: Add exit message here.
                break;
            default:
                break;
            }
        }while(choice != APP_EXIT);
    }

    void App::Close(){
        m_calendarController = nullptr;
        delete m_calendarController;
    }
}
