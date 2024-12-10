#include "Month.h"
#include <iostream>

namespace PlannerCLI{
    Month::Month(eMonth month)
    {
        SetMonth(month);
    }

    Month::Month(int month){
        SetMonth(month);
    }

    Month::~Month()
    {

    }

    int Month::CalculateMonthLength(bool leapYear){
        return CalculateMonthLength(GetValueN(), leapYear);
    }

    int Month::CalculateMonthLength(int month, bool leapYear){
        switch(month - 1){
        case Month::February:
            if(leapYear)
                return 29;
            else
                return 28;
        case Month::April:
        case Month::June:
        case Month::September:
        case Month::November:
            return 30;
        case Month::January:
        case Month::March:
        case Month::May:
        case Month::July:
        case Month::August:
        case Month::October:
        case Month::December:
            return 31;
        default:
            //@TODO: Error handling.
            return 0;
        }
    }

    int Month::GetValueN() const{
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

    std::string Month::GetMonthName() const{
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

    std::string Month::GetMonthName(int month){
        switch(month){
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            break;
        }
    }

    void Month::SetMonth(int month){
        switch(month){
        case 1:
            m_month = January;
            break;
        case 2:
            m_month = February;
            break;
        case 3:
            m_month = March;
            break;
        case 4:
            m_month = April;
            break;
        case 5:
            m_month = May;
            break;
        case 6:
            m_month = June;
            break;
        case 7:
            m_month = July;
            break;
        case 8:
            m_month = August;
            break;
        case 9:
            m_month = September;
            break;
        case 10:
            m_month = October;
            break;
        case 11:
            m_month = November;
            break;
        case 12:
            m_month = December;
            break;
        default:
            break;
        }
    }
}
