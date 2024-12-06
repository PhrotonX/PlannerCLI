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
            std::cout << "���������������������������ͻ" << std::endl;
            std::cout << "�                           �" << std::endl;
            std::cout << "�         PlannerCLI        �" << std::endl;
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
            std::cout << "� Choice:                   �" << std::endl;

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
