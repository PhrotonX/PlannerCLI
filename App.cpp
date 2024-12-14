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
            std::cout << "���������������������������ͻ" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "�         PlannerCLI        �" << std::endl;
            std::cout << "�          v1.0.0.1         �" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "�   Choose an option:       �" << std::endl;
            std::cout << "�   ======================  �" << std::endl;
            std::cout << "�   1. Show Calendar        �" << std::endl;
            std::cout << "�   2. Save Information     �" << std::endl;
            std::cout << "�   3. Settings             �" << std::endl;
            std::cout << "�   4. Help                 �" << std::endl;
            std::cout << "�   5. Exit                 �" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "���������������������������ͼ" << std::endl;
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
