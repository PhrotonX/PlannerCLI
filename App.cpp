#include "App.h"
#include <conio.h>
#include "FORMAT.h"

namespace PlannerCLI{
    App::App()
    {
        //ctor 
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
        int choice = 0;
        do{
            //Replace with either Mouse click or Arrow keys
            std::cout << "ษอออออออออออออออออออออออออออป" << std::endl;
            std::cout << "บ                           บ" << std::endl;
            std::cout << "บ         PlannerCLI        บ" << std::endl;
            std::cout << "บ          v1.0.0.2         บ" << std::endl;
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
                if (!Settings::ArrayCalendar) {
                    Calendar* model = new Calendar();
                    CalendarView* view = new CalendarView(model->GetNavigatedDate());

                    m_calendarController = new CalendarController(std::move(view), std::move(model));
                    m_calendarController->Index();
                    m_calendarController->HandleInput();
                }
                else {
                    ArrayCalendar* model = new ArrayCalendar();
                    CalendarView* view = new CalendarView(model->GetNavigatedDate());

                    m_calendarController = new CalendarController(std::move(view), std::move(model));
                    m_calendarController->Index();
                    m_calendarController->HandleInput();
                }
                
                break;
            case APP_SETTINGS:
                m_settingsController->Index();
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
}
