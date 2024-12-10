#ifndef DATE_H
#define DATE_H
#include "Year.h"
#include "Month.h"
#include "Day.h"
#include "DayOfTheWeek.h"
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
                \remarks Does not include the day of the week.
            */
            static Date GetCurrentDate();

            Year& GetYear(){
                return m_year;
            }

            Month& GetMonth(){
                return m_month;
            }

            Day& GetDay() {
                return m_day;
            }

            void SetDate(int year, int month, int day);

            /**
                \details Sets the day value and automatically sets the day of the week since
                GetDay().SetValue() does not.

                \param day The 1-based day value.
            */
            void SetDay(int day) {
                m_day.SetValue(day);
                m_day.GetDayOfTheWeek().SetValueZC(DayOfTheWeek::CalculateDayOfTheWeek(m_year.GetValue(), m_month.GetValueN(), m_day.GetValue()));
            }

        private:
            Year m_year;
            Month m_month;
            Day m_day;
    };

}

#endif // DATE_H
