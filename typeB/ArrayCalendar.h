#ifndef ARRAYCALENDAR_H
#define ARRAYCALENDAR_H

#include "../EventManager.h"
#include "ArrayYear.h"
#include "../Date.h"
#include "../DayOfTheWeek.h"
#include "../Settings.h"
#include <sstream>
#include <iostream>
#include <ctime>
#include <map>
#include <vector>

namespace PlannerCLI::typeB {
    /**
        \details ArrayCalendar is a type B calendar that is an alternative of EventManager.
        This class uses a type B variant or array variant of Year, Month, and Day. As the name implies,
        it uses 2D array to represent a calendar.
    */
	class ArrayCalendar : public EventManager
	{
    public:
        inline static const int MAX_YEAR = 2106;
        inline static const int MIN_YEAR = 1970;

        ArrayCalendar();
        ~ArrayCalendar() override;

        void AddEvent(Event event, Date date) override;
        Event& GetEvent(Date date, size_t position) override;
        std::vector<Event>& GetEventList(Date date) override;
        void RemoveEvent(Date date, size_t position) override;
        std::vector<Event> SearchEvent(const std::string& query) override;
        void UpdateEvent(Event event) override;

        void Init();

        void Load() override;

        void Save() override;

        /**
            \details Fill up data, ranging from 2020-2029 for 30+ MB of RAM.
            \remarks The loaded values can be changed into 1970-2106, but it uses 370MB+ of RAM.
        */
        void Seed();

        void Sort(Date date) override;

    protected:
        inline static const std::string FILE_ARRAY_CALENDAR = "array_calendar.bin";
    private:
        //Handle 137 years. From 1970-2106.
        ArrayYear* m_year[137];
	};
}

#endif ARRAYCALENDAR_H
