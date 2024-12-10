#include "Date.h"

namespace PlannerCLI{
    Date::Date(int year, int month, int day)
    {
        SetDate(year, month, day);
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
        int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
        h = h % 7;

        return h;
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

        SetDayOfTheWeekZC(CalculateDayOfTheWeek(year, month, day));
    }

    int Date::GetDayOfTheWeekID() {
        switch (m_nDayOfTheWeek) {
        case DaysOfTheWeek::Sunday:
            return 0;
        case DaysOfTheWeek::Monday:
            return 1;
        case DaysOfTheWeek::Tuesday:
            return 2;
        case DaysOfTheWeek::Wednesday:
            return 3;
        case DaysOfTheWeek::Thursday:
            return 4;
        case DaysOfTheWeek::Friday:
            return 5;
        case DaysOfTheWeek::Saturday:
            return 6;
        default:
            return -1;
            break;
        }
    }

    std::string Date::GetDayOfTheWeekName() {
        switch (m_nDayOfTheWeek) {
        case DaysOfTheWeek::Sunday:
            return "Sunday";
        case DaysOfTheWeek::Monday:
            return "Monday";
        case DaysOfTheWeek::Tuesday:
            return "Tuesday";
        case DaysOfTheWeek::Wednesday:
            return "Wednesday";
        case DaysOfTheWeek::Thursday:
            return "Thursday";
        case DaysOfTheWeek::Friday:
            return "Friday";
        case DaysOfTheWeek::Saturday:
            return "Saturday";
        default:
            break;
        }
    }

    void Date::SetDayOftheWeek(int dayOfTheWeek) {
        switch (dayOfTheWeek) {
        case 0:
            m_nDayOfTheWeek = Sunday;
            break;
        case 1:
            m_nDayOfTheWeek = Monday;
            break;
        case 2:
            m_nDayOfTheWeek = Tuesday;
            break;
        case 3:
            m_nDayOfTheWeek = Wednesday;
            break;
        case 4:
            m_nDayOfTheWeek = Thursday;
            break;
        case 5:
            m_nDayOfTheWeek = Friday;
            break;
        case 6:
            m_nDayOfTheWeek = Saturday;
            break;
        default:
            break;
        }
    }

    void Date::SetDayOfTheWeekZC(int dayOfTheWeek) {
        switch (dayOfTheWeek) {
        case 1:
            m_nDayOfTheWeek = Sunday;
            break;
        case 2:
            m_nDayOfTheWeek = Monday;
            break;
        case 3:
            m_nDayOfTheWeek = Tuesday;
            break;
        case 4:
            m_nDayOfTheWeek = Wednesday;
            break;
        case 5:
            m_nDayOfTheWeek = Thursday;
            break;
        case 6:
            m_nDayOfTheWeek = Friday;
            break;
        case 0:
            m_nDayOfTheWeek = Saturday;
            break;
        default:
            break;
        }
    }

}
