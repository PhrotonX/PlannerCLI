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

    std::string Date::GetFormattedString(bool withDayOfTheWeek)
    {
        std::string strDate;
        std::string space = " ";
        std::string strYear = std::to_string(m_year.GetValue());
        std::string strMonth = m_month.GetMonthName();
        std::string strDay = std::to_string(m_day.GetValue());
        std::string strDayOfTheWeek = m_day.GetDayOfTheWeek().GetName();

        if (withDayOfTheWeek) {
            strDate = strDayOfTheWeek + ", " + strMonth + " " + strDay + ", " + strYear;
        }
        else {
            strDate = strMonth + " " + strDay + ", " + strYear;
        }
        
        return strDate;
    }

    std::string Date::GetString() const {
        std::string space = " ";
        std::string strYear = std::to_string(m_year.GetValue());
        std::string strMonth = std::to_string(m_month.GetValueN());
        std::string strDay = std::to_string(m_day.GetValue());

        if (m_month.GetValueN() < 10) {
            strMonth = space + strMonth;
        }
        if (m_day.GetValue() < 10) {
            strDay = space + strDay;
        }

        std::string strDate = strYear + strMonth + strDay;

        return strDate;
    }

    void Date::SetDate(int year, int month, int day) {
        m_year = Year(year);
        m_month = Month(month);
        m_day = Day(day);

        UpdateDayOfTheWeek();
    }

    void Date::UpdateDayOfTheWeek()
    {
        m_month.GetFirstDayOfTheWeek().SetValueZC(DayOfTheWeek::CalculateDayOfTheWeek(m_year.GetValue(), m_month.GetValueN(), 1));

        m_day.GetDayOfTheWeek().SetValueZC(DayOfTheWeek::CalculateDayOfTheWeek(m_year.GetValue(), m_month.GetValueN(), m_day.GetValue()));
    }

}
