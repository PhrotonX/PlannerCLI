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

    int Month::GetMonthID(){
        switch(m_month){
        case eMonth::January:
            return 1;
        case eMonth::February:
            return 2;
        case eMonth::March:
            return 3;
        case eMonth::April:
            return 4;
        case eMonth::May:
            return 5;
        case eMonth::June:
            return 6;
        case eMonth::July:
            return 7;
        case eMonth::August:
            return 8;
        case eMonth::September:
            return 9;
        case eMonth::October:
            return 10;
        case eMonth::November:
            return 11;
        case eMonth::December:
            return 12;
        default:
            break;
        }
    }

    std::string Month::GetMonthName(){
        switch(m_month){
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
