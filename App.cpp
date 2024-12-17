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
            std::cout << "���������������������������ͻ" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "�         PlannerCLI        �" << std::endl;
            std::cout << "�          v1.0.0.2         �" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "�   Choose an option:       �" << std::endl;
            std::cout << "�   ======================  �" << std::endl;
            std::cout << "�   1. Show Calendar        �" << std::endl;
            std::cout << "�   2. Show To Do List      �" << std::endl;
            std::cout << "�   3. Load Information     �" << std::endl;
            std::cout << "�   4. Save Information     �" << std::endl;
            std::cout << "�   5. Settings             �" << std::endl;
            std::cout << "�   6. Help                 �" << std::endl;
            std::cout << "�   7. Exit                 �" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "���������������������������ͼ" << std::endl;
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
