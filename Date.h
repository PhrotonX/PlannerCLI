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

        std::string GetFormattedString(bool withDayOfTheWeek = false);
        std::string GetString() const;

        void SetDate(int year, int month, int day);

        /**
            \details Sets the year value and automatically sets the day of the week since
            GetYear().SetValue() does not.

            \param day The 1-based day value.
        */
        void SetYear(int year) {
            m_year.SetValue(year);
            UpdateDayOfTheWeek();
        }

        /**
            \details Sets the month value and automatically sets the day of the week since
            GetMonth().SetMonth() does not.

            \param day The 1-based day value.
        */
        void SetMonth(int month) {
            m_month.SetMonth(month);
            UpdateDayOfTheWeek();
        }

        /**
            \details Sets the day value and automatically sets the day of the week since
            GetDay().SetValue() does not.

            \param day The 1-based day value.
        */
        void SetDay(int day) {
            m_day.SetValue(day);
            UpdateDayOfTheWeek();
        }

        void UpdateDayOfTheWeek();

    private:
        Year m_year;
        Month m_month;
        Day m_day;
    };

}

#endif // DATE_H
