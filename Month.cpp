#include "Month.h"

namespace PlannerCLI{
    Month::Month()
    {
        //ctor
    }

    Month::~Month()
    {
        //dtor
    }

    std::string Month::GetMonthName(){
        switch(m_monthId){
        case eMonth::January:
            return "January";
        case eMonth::February:
            return "February";
        case eMonth::March:
            return "March";
        case eMonth::April:
            return "April";
        case eMonth::May:
            return "May";
        case eMonth::June:
            return "June";
        case eMonth::July:
            return "July";
        case eMonth::August:
            return "August";
        case eMonth::September:
            return "September";
        case eMonth::October:
            return "October";
        case eMonth::November:
            return "November";
        case eMonth::December:
            return "December";
        default:
            break;
        }
    }
}
