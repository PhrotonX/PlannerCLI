#include "App.h"
#include <conio.h>
#include "FORMAT.h"

namespace PlannerCLI{
    App::App()
    {
        //ctor 
        m_calendarController = new CalendarController();
        m_settingsController = new SettingsController();
    }

    App::~App()
    {
        //dtor
        if(m_arrayCalendar != nullptr) delete m_arrayCalendar;
        if(m_calendarController != nullptr) delete m_calendarController;
        if(m_settingsController != nullptr) delete m_settingsController;
        m_arrayCalendar = nullptr;
        m_calendarController = nullptr;
        m_settingsController = nullptr;
    }

    void App::Run(){
        bool run = true;
        char choice = '0';
        do{
            //Replace with either Mouse click or Arrow keys
            std::cout << "���������������������������ͻ" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "�         PlannerCLI        �" << std::endl;
            std::cout << "�          v1.0.0.2         �" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "�   Choose an option:       �" << std::endl;
            std::cout << "�   ======================  �" << std::endl;
            std::cout << "�   1. Show Calendar        �" << std::endl;
            std::cout << "�   2. Save Information     �" << std::endl;
            std::cout << "�   3. Load Information     �" << std::endl;
            std::cout << "�   4. Settings             �" << std::endl;
            std::cout << "�   5. Help                 �" << std::endl;
            std::cout << "�   6. Exit                 �" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "���������������������������ͼ" << std::endl;
            std::cout << "Press keys 1-6 to navigate: ";

            switch(_getch()){
            case APP_SHOW_CALENDAR:
                
                m_calendarController->Index();
                
                break;
            case APP_SAVE_INFORMATION:
                
                break;
            case APP_LOAD_INFORMATION:
                break;
            case APP_SETTINGS:
                m_settingsController->Index();
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
