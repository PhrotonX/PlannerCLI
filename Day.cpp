#include "Day.h"

namespace PlannerCLI{
    Day::Day()
    {
        //ctor
    }

    Day::~Day()
    {
        //dtor
    }

    int Day::GetDayOfTheWeekID(){
        switch(m_nDayOfTheWeek){
        case DaysOfTheWeek.Sunday:
            return 1;
        case DaysOfTheWeek.Monday:
            return 2;
        case DaysOfTheWeek.Tuesday:
            return 3;
        case DaysOfTheWeek.Wednesday:
            return 4;
        case DaysOfTheWeek.Thursday:
            return 5;
        case DaysOfTheWeek.Friday:
            return 6;
        case DaysOfTheWeek.Saturday:
            return 7;
        default:
            break;
        }
    }

    int Day::GetDayOfTheWeekName(){
        switch(m_nDayOfTheWeek){
        case DaysOfTheWeek.Sunday:
            return "Sunday";
        case DaysOfTheWeek.Monday:
            return "Monday";
        case DaysOfTheWeek.Tuesday:
            return "Tuesday;
        case DaysOfTheWeek.Wednesday:
            return "Wednesday";
        case DaysOfTheWeek.Thursday:
            return "Thursday";
        case DaysOfTheWeek.Friday:
            return "Friday";
        case DaysOfTheWeek.Saturday:
            return "Saturday";
        default:
            break;
        }
    }

}
