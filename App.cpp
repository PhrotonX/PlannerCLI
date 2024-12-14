#include "App.h"
#include <conio.h>
#include "FORMAT.h"

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
        int choice = 0;
        do{
            //Replace with either Mouse click or Arrow keys
            std::cout << "ษอออออออออออออออออออออออออออป" << std::endl;
            std::cout << "บ                           บ" << std::endl;
            std::cout << "บ         PlannerCLI        บ" << std::endl;
            std::cout << "บ          v1.0.0.1         บ" << std::endl;
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
            std::cout << "Choice: ";

            std::cin >> choice;
            std::cin.ignore();

            switch(choice){
            case APP_SHOW_CALENDAR:
                m_calendarController->Index();
                m_calendarController->HandleInput();
                break;
            case APP_EXIT:
                //@TODO: Add exit message here.
                break;
            default:
                break;
            }

            CLEAR_SCREEN;
        }while(choice != APP_EXIT);
    }

    void App::Close(){
        m_calendarController = nullptr;
        delete m_calendarController;
    }
}
