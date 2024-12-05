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

    int Day::GetDayOfTheWeekN(){
        switch(m_nDayOfTheWeek){
        case DaysOfTheWeek.Sunday:
            return 0;
        case DaysOfTheWeek.Monday:
            return 1;
        case DaysOfTheWeek.Tuesday:
            return 2;
        case DaysOfTheWeek.Wednesday:
            return 3;
        case DaysOfTheWeek.Thursday:
            return 4;
        case DaysOfTheWeek.Friday:
            return 5;
        case DaysOfTheWeek.Saturday:
            return 6;
        default:
            break;
        }
    }

    int Day::GetDayOfTheWeekStr(){
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
