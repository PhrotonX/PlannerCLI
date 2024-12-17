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

            void Debug();

            void OnNavigateDayUp();
            void OnNavigateDayLeft();
            void OnNavigateDayRight();
            void OnNavigateDayDown();

            /**
                \return Date*& The date object which consists of current date
                information.
            */
            void OnNavigateInit();
            void OnNavigateNextMonth();
            void OnNavigatePrevMonth();

            Date* GetNavigatedDate() {
                return &m_navigatedDate;
            }

            void Load() override;

            void Save() override;

        protected:
            Date m_navigatedDate;

            int m_nNavigatedYear;
            int m_nNavigatedMonth;
            int m_nNavigatedDay;
    };
}


#endif // CALENDAR_H
