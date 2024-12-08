#include "Day.h"

namespace PlannerCLI{
    Day::Day(int day){
        SetValue(day);
        SetDayOftheWeek(-1);
    }

    Day::Day(int day, DaysOfTheWeek dayOfTheWeek)
    {
        //ctor
        SetValue(day);
        SetDayOftheWeek(dayOfTheWeek);
    }

    Day::Day(int day, int dayOfTheWeek)
    {
        //ctor
        SetValue(day);
        SetDayOftheWeek(dayOfTheWeek);
    }

    Day::~Day()
    {
        //dtor
    }

    int Day::GetDayOfTheWeekID(){
        switch(m_nDayOfTheWeek){
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

    std::string Day::GetDayOfTheWeekName(){
        switch(m_nDayOfTheWeek){
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

    void Day::SetDayOftheWeek(int dayOfTheWeek){
        switch(dayOfTheWeek){
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

    void Day::SetDayOfTheWeekZC(int dayOfTheWeek){
        switch(dayOfTheWeek){
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
