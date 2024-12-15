#ifndef ARRAYCALENDAR_H
#define ARRAYCALENDAR_H

#include "../EventManager.h"
#include "ArrayYear.h"
#include "../Date.h"
#include "../DayOfTheWeek.h"
#include "../Settings.h"
#include <iostream>
#include <ctime>

namespace PlannerCLI::typeB {
    /**
        \details ArrayCalendar is a type B calendar that is an alternative of EventManager.
        This class uses a type B variant or array variant of Year, Month, and Day. As the name implies,
        it uses 2D array to represent a calendar.
    */
	class ArrayCalendar : private EventManager
	{
    public:
        //inline static const int MAX_YEAR = 2106;
        //inline static const int MIN_YEAR = 1970;

        ArrayCalendar();
        virtual ~ArrayCalendar();

        void AddEvent(Event event) {
            Date date = event.GetDate();
            int year = date.GetYear().GetValue() - ArrayYear::BASE_YEAR;
            int month = date.GetMonth().GetValueN();
        }

        void Init();

        void Save() override{}

        

        /**
            \details Fill up data.
            \deprecated
        */
        void Seed();

    private:
        //Handle 137 years. From 1970-2106.
        ArrayYear* m_year[137];
	};
}

#endif ARRAYCALENDAR_H
