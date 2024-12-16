#ifndef APP_H
#define APP_H

#include <stdio.h>
#include "typeB/ArrayCalendar.h"
#include "CalendarController.h"
#include "CalendarView.h"
#include "Calendar.h"
#include "SettingsController.h"
#include "Settings.h"

using namespace PlannerCLI::typeB;
namespace PlannerCLI{
    class App
    {
        public:
            inline static const char APP_SHOW_CALENDAR = '1';
            inline static const char APP_SAVE_INFORMATION = '2';
            inline static const char APP_LOAD_INFORMATION = '3';
            inline static const char APP_SETTINGS = '4';
            inline static const char APP_HELP = '5';
            inline static const char APP_EXIT = '6';

            App();
            virtual ~App();

            void Run();

        private:
            ArrayCalendar* m_arrayCalendar;
            CalendarController* m_calendarController;
            SettingsController* m_settingsController;
    };
}


#endif // APP_H
