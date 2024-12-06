#ifndef APP_H
#define APP_H

#include <stdio.h>
#include "CalendarController.h"

#define APP_SHOW_CALENDAR 1
#define APP_SAVE_INFORMATION 2
#define APP_SETTINGS 3
#define APP_HELP 4
#define APP_EXIT 5

namespace PlannerCLI{
    class App
    {
        public:
            App();
            virtual ~App();

            void Run();
            void Close();

        private:

            CalendarController* m_calendarController;
    };
}


#endif // APP_H
