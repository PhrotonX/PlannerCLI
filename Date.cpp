#include "Date.h"

namespace PlannerCLI{
    Date::Date(int year, int month, int day)
    {
        SetDate(year, month, day);
    }

    Date::~Date()
    {

    }

    Date Date::GetCurrentDate(){
        int currentYear = 1900;
        int currentMonth = 1;
        int currentDay = 1;
        time_t unixCurrentTime;

        //Get current time
        time(&unixCurrentTime);

        struct tm currentTime;
        localtime_s(&currentTime, &unixCurrentTime);
        currentYear += currentTime.tm_year;
        currentMonth += currentTime.tm_mon;
        currentDay = currentTime.tm_mday;

        return Date(currentYear, currentMonth, currentDay);
    }

    void Date::SetDate(int year, int month, int day) {
        m_year = Year(year);
        m_month = Month(month);
        m_day = Day(day);

        m_month.GetFirstDayOfTheWeek().SetValueZC(DayOfTheWeek::CalculateDayOfTheWeek(year, month, 1));

        m_day.GetDayOfTheWeek().SetValueZC(DayOfTheWeek::CalculateDayOfTheWeek(year, month, day));
    }

}
