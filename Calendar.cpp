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

    Date Calendar::OnNavigateInit(){
        //Get current date.
        Date currentDate = Date::GetCurrentDate();

        //Obtain the date values.
        m_nNavigatedYear = currentDate.GetYear().GetValue();
        m_nNavigatedMonth = currentDate.GetMonth().GetValueN();

        //Get the first day of the month.
        Date firstDayOfTheMonth = Date(m_nNavigatedYear, m_nNavigatedMonth, 1);

        return firstDayOfTheMonth;
    }

    Date Calendar::OnNavigateNext(){
        m_nNavigatedMonth++;
        if (m_nNavigatedMonth > 12) {
            m_nNavigatedMonth = 1;
            m_nNavigatedYear++;
        }

        return Date(m_nNavigatedYear, m_nNavigatedMonth, 1);
    }

    Date Calendar::OnNavigatePrev(){
        m_nNavigatedMonth--;
        if (m_nNavigatedMonth < 1) {
            m_nNavigatedMonth = 12;
            m_nNavigatedYear--;
        }

        return Date(m_nNavigatedYear, m_nNavigatedMonth, 1);
    }

    void Calendar::Save(){

    }
}

