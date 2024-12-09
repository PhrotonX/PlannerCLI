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

            /**
                \return Date*& The date object which consists of current date
                information.
            */
            Date OnNavigateInit();
            Date OnNavigateNext();
            Date OnNavigatePrev();

            void Save() override;

        private:
            int m_nNavigatedYear;
            int m_nNavigatedMonth;
    };
}


#endif // CALENDAR_H
