#include "Date.h"

namespace PlannerCLI{
    Date::Date(int year, int month, int day)
    {
        m_year = new Year(year);
        m_month = new Month(month);
        m_day = new Day(day);
    }

    Date::~Date()
    {
        if(m_year != nullptr) delete m_year;
        if(m_month != nullptr) delete m_month;
        if(m_year != nullptr) delete m_day;
        m_year = nullptr;
        m_month = nullptr;
        m_day = nullptr;
    }

    int Date::CalculateDayOfTheWeek(){
        int year = GetYear()->GetValue();
        int month = GetMonth()->GetValueN();
        int day = GetDay()->GetValue();

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

    Date* Date::GetCurrentDate(){
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

        return new Date(currentYear, currentMonth, currentDay);
    }


}
