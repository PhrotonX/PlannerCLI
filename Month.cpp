#include "Month.h"

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
        //dtor
    }

    int Month::GetMonthID() const{
        switch(m_month){
        case eMonth::January:
            return 0;
        case eMonth::February:
            return 1;
        case eMonth::March:
            return 2;
        case eMonth::April:
            return 3;
        case eMonth::May:
            return 4;
        case eMonth::June:
            return 5;
        case eMonth::July:
            return 6;
        case eMonth::August:
            return 7;
        case eMonth::September:
            return 8;
        case eMonth::October:
            return 9;
        case eMonth::November:
            return 10;
        case eMonth::December:
            return 11;
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

    void Month::SetMonth(int month){
        switch(month){
        case 0:
            m_month = January;
        case 1:
            m_month = February;
        case 2:
            m_month = March;
        case 3:
            m_month = April;
        case 4:
            m_month = May;
        case 5:
            m_month = June;
        case 6:
            m_month = July;
        case 7:
            m_month = August;
        case 8:
            m_month = September;
        case 9:
            m_month = October;
        case 10:
            m_month = November;
        case 11:
            m_month = December;
        default:
            break;
        }
    }
}
