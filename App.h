#ifndef APP_H
#define APP_H

#include <stdio.h>
#include "typeB/ArrayCalendar.h"
#include "CalendarController.h"
#include "SettingsController.h"
#include "Settings.h"

using namespace PlannerCLI::typeB;
namespace PlannerCLI{
    class App
    {
        public:
            inline static const int APP_SHOW_CALENDAR = 1;
            inline static const int APP_SAVE_INFORMATION = 2;
            inline static const int APP_SETTINGS = 3;
            inline static const int APP_HELP = 4;
            inline static const int APP_EXIT = 5;

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
