#include "App.h"
#include <conio.h>
#include "FORMAT.h"

namespace PlannerCLI{
    App::App()
    {
        //ctor
    }

    App::~App()
    {
        //dtor
        m_calendarController = nullptr;

        if(m_arrayCalendar != nullptr) delete m_arrayCalendar;
        if(m_calendarControllerTypeA != nullptr) delete m_calendarControllerTypeA;
        if(m_calendarControllerTypeB != nullptr) delete m_calendarControllerTypeB;

        m_arrayCalendar = nullptr;
        m_calendarControllerTypeA = nullptr;
        m_calendarControllerTypeB = nullptr;
    }

    void App::Run(){
        bool run = true;
        char choice = '0';
        do{
            if (!Settings::ArrayCalendar) {
                if(m_calendarControllerTypeA == nullptr)
                    m_calendarControllerTypeA = new CalendarController();
                m_calendarController = m_calendarControllerTypeA;
            }
            else {
                if (m_calendarControllerTypeB == nullptr)
                    m_calendarControllerTypeB = new CalendarController();
                m_calendarController = m_calendarControllerTypeB;
            }

            //Replace with either Mouse click or Arrow keys
            std::cout << "ษอออออออออออออออออออออออออออป" << std::endl;
            std::cout << "บ                           บ" << std::endl;
            std::cout << "บ         PlannerCLI        บ" << std::endl;
            std::cout << "บ          v1.0.0.2         บ" << std::endl;
            std::cout << "บ                           บ" << std::endl;
            std::cout << "บ   Choose an option:       บ" << std::endl;
            std::cout << "บ   ======================  บ" << std::endl;
            std::cout << "บ   1. Show Calendar        บ" << std::endl;
            std::cout << "บ   2. Show To Do List      บ" << std::endl;
            std::cout << "บ   3. Load Information     บ" << std::endl;
            std::cout << "บ   4. Save Information     บ" << std::endl;
            std::cout << "บ   5. Settings             บ" << std::endl;
            std::cout << "บ   6. Help                 บ" << std::endl;
            std::cout << "บ   7. Exit                 บ" << std::endl;
            std::cout << "บ                           บ" << std::endl;
            std::cout << "ศอออออออออออออออออออออออออออผ" << std::endl;
            std::cout << "Press keys 1-7 to navigate: ";

            switch(_getch()){
            case APP_SHOW_CALENDAR:
                m_calendarController->Index();
                break;
            case APP_SHOW_TODOLIST:
                m_toDoController.Index();
                break;
            case APP_LOAD_INFORMATION:
                std::cout << "Loading..." << std::endl;
                m_calendarController->Load();
                m_toDoController.Load();
                break;
            case APP_SAVE_INFORMATION:
                m_calendarController->Store();
                m_toDoController.Store();
                break;
            case APP_SETTINGS:
                m_settingsController.Index();
                break;
            case APP_HELP:
                break;
            case APP_EXIT:
                std::cout << "Exiting..." << std::endl;
                run = false;
                break;
            default:
                break;
            }

            CLEAR_SCREEN;
        }while(run);
    }
}
