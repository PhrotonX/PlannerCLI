#ifndef DATE_H
#define DATE_H
#include "Year.h"
#include "Month.h"
#include "Day.h"
#include <iostream>
#include <ctime>

namespace PlannerCLI{
    class Date
    {
        public:
            Date() {}
            /**
                \param year 1-based value of year.
                \param year 1-based value of month.
                \param year 1-based value of day.
            */
            Date(int year, int month, int day);
            virtual ~Date();

            /**
                \details Calculates the day of the week through Zeller's Congruence.
                \param year 1-based year value.
                \param year 1-based month value.
                \param year 1-based day value.
                \return The day of the week (0 = Saturday, 6 = Friday).
            */
            static int CalculateDayOfTheWeek(int year, int month, int day);

            /**
                \remarks Does not include the day of the week.
            */
            static Date GetCurrentDate();

            Year& GetYear(){
                return m_year;
            }

            Month& GetMonth(){
                return m_month;
            }

            Day& GetDay(){
                return m_day;
            }

        private:
            Year m_year;
            Month m_month;
            Day m_day;
    };

}

#endif // DATE_H
