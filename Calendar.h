#ifndef CALENDAR_H
#define CALENDAR_H
#include "Model.h"
#include "Year.h"
#include "Month.h"
#include "Day.h"
#include "Date.h"
#include <iostream>

namespace PlannerCLI{
    class Calendar : public Model
    {
        public:
            //inline static const int MAX_YEAR = 2106;
            //inline static const int MIN_YEAR = 1970;

            Calendar();
            virtual ~Calendar();

            void OnNavigateDayUp();
            void OnNavigateDayLeft();
            void OnNavigateDayRight();
            void OnNavigateDayDown();

            /**
                \return Date*& The date object which consists of current date
                information.
            */
            Date OnNavigateInit();
            Date OnNavigateNextMonth();
            Date OnNavigatePrevMonth();

            int* GetNavigatedDay() {
                return &m_nNavigatedDay;
            }



            void Save() override;

        private:
            //Date m_navigatedDate;

            int m_nNavigatedYear = 0;
            int m_nNavigatedMonth = 0;
            int m_nNavigatedDay = 1;
    };
}


#endif // CALENDAR_H
