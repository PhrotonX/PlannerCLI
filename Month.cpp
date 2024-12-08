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
        for(int i = 0; i < m_nMonthSize; i++){
            if(m_day[i] != nullptr){
                delete m_day[i];
                m_day[i] = nullptr;
            }

        }
    }

    int Month::CalculateMonthLength(const Month& month, bool leapYear){
        switch(month.GetValue()){
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

    void Month::Clear(){
        m_nMonthSize;

        for(int i = 0; i < m_nMonthSize; i++){

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

    void Month::Populate(int firstDayOfTheWeek, bool leapYear){
        int dayOfTheWeek = firstDayOfTheWeek;

        m_nMonthSize = CalculateMonthLength(*this, leapYear);

        for(int i = 1; i <= m_nMonthSize; i++){
            Day** day = (Day**)calloc(m_nMonthSize, sizeof(Day**));
            for(int k = 0; k < m_nMonthSize; k++){
                day[k] = new Day(k + 1, dayOfTheWeek);
                dayOfTheWeek++;
                if(dayOfTheWeek >= 6) dayOfTheWeek = 0;
            }

            this->SetDays(day);
        }
    }

    void Month::SetMonth(int month){
        switch(month){
        case 1:
            m_month = January;
        case 2:
            m_month = February;
        case 3:
            m_month = March;
        case 4:
            m_month = April;
        case 5:
            m_month = May;
        case 6:
            m_month = June;
        case 7:
            m_month = July;
        case 8:
            m_month = August;
        case 9:
            m_month = September;
        case 10:
            m_month = October;
        case 11:
            m_month = November;
        case 12:
            m_month = December;
        default:
            break;
        }
    }
}
