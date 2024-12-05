#ifndef APP_H
#define APP_H
#include "CalendarController.h"

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
