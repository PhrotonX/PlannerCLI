#include "Date.h"

namespace PlannerCLI{
    Date::Date(int year, int month, int day)
    {
        m_year = Year(year);
        m_month = Month(month);
        m_day = Day(day);

        int dayOfTheWeek = CalculateDayOfTheWeek(year, month, day);
        m_day.SetDayOfTheWeekZC(dayOfTheWeek);
    }

    Date::~Date()
    {

    }

    int Date::CalculateDayOfTheWeek(int year, int month, int day){
        if(month == 1){
            month = 13;
            year--;
        }
        if(month == 2){
            month = 14;
            year--;
        }

        int q = day;
        int m = month;
        int j = year / 100; //zero-based year of the century.
        int k = year % 100; //year of the century
        int h = (q + 13 * ((m + 1) / 5) + k + (k / 4) + (j / 4) + 5 * j);
        h = h % 7;

        return h;
    }

    Date Date::GetCurrentDate(){
        int currentYear = 1900;
        int currentMonth;
        int currentDay;
        time_t unixCurrentTime;

        //Get current time
        time(&unixCurrentTime);

        tm* currentTime = localtime(&unixCurrentTime);
        currentYear += currentTime->tm_year;
        currentMonth = currentTime->tm_mon;
        currentDay = currentTime->tm_mday;

        return Date(currentYear, currentMonth, currentDay);
    }

}
