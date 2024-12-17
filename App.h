#ifndef APP_H
#define APP_H

#include <stdio.h>
#include "typeB/ArrayCalendar.h"
#include "CalendarController.h"
#include "CalendarView.h"
#include "Calendar.h"
#include "SettingsController.h"
#include "Settings.h"
#include "ToDoController.h"

using namespace PlannerCLI::typeB;
namespace PlannerCLI{
    class App
    {
        public:
            inline static const char APP_SHOW_CALENDAR = '1';
            inline static const char APP_SHOW_TODOLIST = '2';
            inline static const char APP_LOAD_INFORMATION = '3';
            inline static const char APP_SAVE_INFORMATION = '4';
            inline static const char APP_SETTINGS = '5';
            inline static const char APP_HELP = '6';
            inline static const char APP_EXIT = '7';

            App();
            virtual ~App();

            void Run();

        private:
            ArrayCalendar* m_arrayCalendar;
            CalendarController* m_calendarController;
            CalendarController* m_calendarControllerTypeA = nullptr;
            CalendarController* m_calendarControllerTypeB = nullptr;
            ToDoController* m_toDoController = nullptr;
            SettingsController* m_settingsController;
    };
}


#endif // APP_H
