#include "Calendar.h"

namespace PlannerCLI{
    Calendar::Calendar()
    {
        //ctor
    }

    Calendar::~Calendar()
    {
        //dtor
    }

    void Calendar::OnNavigateDayUp() {
        m_nNavigatedDay -= 7;

        if (m_nNavigatedDay < 1) {
            int distance = m_nNavigatedDay;
            OnNavigatePrevMonth();
            m_nNavigatedDay -= distance;
        }
    }

    void Calendar::OnNavigateDayLeft() {
        m_nNavigatedDay--;

        if (m_nNavigatedDay < 1) {
            OnNavigatePrevMonth();
        }
    }

    void Calendar::OnNavigateDayRight() {
        m_nNavigatedDay++;

        if (m_nNavigatedDay > Month::CalculateMonthLength(m_nNavigatedMonth, Year::IsLeapYear(m_nNavigatedYear))) {
            OnNavigateNextMonth();
        }
    }

    void Calendar::OnNavigateDayDown() {
        m_nNavigatedDay += 7;

        int monthSize = Month::CalculateMonthLength(m_nNavigatedMonth, Year::IsLeapYear(m_nNavigatedYear));
        if (m_nNavigatedDay > monthSize) {
            int distance = m_nNavigatedDay - monthSize;
            OnNavigateNextMonth();
            m_nNavigatedDay += distance;
        }
    }

    Date Calendar::OnNavigateInit(){
        //Get current date.
        Date currentDate = Date::GetCurrentDate();

        //Obtain the date values.
        m_nNavigatedYear = currentDate.GetYear().GetValue();
        m_nNavigatedMonth = currentDate.GetMonth().GetValueN();
        m_nNavigatedDay = currentDate.GetDay().GetValue();

        //Get the first day of the month.
        Date firstDayOfTheMonth = Date(m_nNavigatedYear, m_nNavigatedMonth, 1);

        return firstDayOfTheMonth;
    }

    Date Calendar::OnNavigateNextMonth(){
        m_nNavigatedMonth++;
        m_nNavigatedDay = 1;
        if (m_nNavigatedMonth > 12) {
            m_nNavigatedMonth = 1;
            m_nNavigatedYear++;
        }

        return Date(m_nNavigatedYear, m_nNavigatedMonth, 1);
    }

    Date Calendar::OnNavigatePrevMonth(){
        m_nNavigatedMonth--;
        m_nNavigatedDay = Month::CalculateMonthLength(m_nNavigatedMonth, Year::IsLeapYear(m_nNavigatedYear));
        if (m_nNavigatedMonth < 1) {
            m_nNavigatedMonth = 12;
            m_nNavigatedYear--;
        }

        return Date(m_nNavigatedYear, m_nNavigatedMonth, m_nNavigatedDay);
    }

    void Calendar::Save(){

    }
}

