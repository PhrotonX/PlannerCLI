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
            enum DaysOfTheWeek {
                Sunday,
                Monday,
                Tuesday,
                Wednesday,
                Thursday,
                Friday,
                Saturday
            };

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

            Day& GetDay() {
                return m_day;
            }

            void SetDate(int year, int month, int day);

            void SetDayOftheWeek(DaysOfTheWeek dayOfTheWeek) {
                m_nDayOfTheWeek = dayOfTheWeek;
            }

            /**
                \brief Set the day of the week.
                \param dayOfTheWeek Set 0 for Sunday and 6 for Saturday.
            */
            void SetDayOftheWeek(int dayOfTheWeek);

            /**
                \brief Sets the day of the week based on Zeller's Congruence Algorithm
                from Date::CalculateDayOfTheWeek().
                \param dayOfTheWeek Set 0 for Saturday and 6 for Friday.
            */
            void SetDayOfTheWeekZC(int dayOfTheWeek);

            /**
                \return Returns 0 for Sunday, 6 for Saturday, and -1 if not available.
            */
            int GetDayOfTheWeekID();

            std::string GetDayOfTheWeekName();

        private:
            Year m_year;
            Month m_month;
            Day m_day;

            DaysOfTheWeek m_nDayOfTheWeek;
    };

}

#endif // DATE_H
