#include "Calendar.h"

namespace PlannerCLI{
    Calendar::Calendar()
    {
        //Set the default date into the day when this program has been first created.
        m_navigatedDate.SetDate(2024, 12, 4);
    }

    Calendar::~Calendar()
    {
        //dtor
    }

    void Calendar::Debug() {
        std::cout << m_nNavigatedYear << " " << m_nNavigatedMonth << " " << m_nNavigatedDay << std::endl;
    }

    void Calendar::OnNavigateDayUp() {
        m_nNavigatedDay -= 7;

        if (m_nNavigatedDay < 1) {
            int distance = m_nNavigatedDay;
            OnNavigatePrevMonth();
            m_nNavigatedDay += distance;
        }

        m_navigatedDate.SetDay(m_nNavigatedDay);
    }

    void Calendar::OnNavigateDayLeft() {
        m_nNavigatedDay--;

        if (m_nNavigatedDay < 1) {
            OnNavigatePrevMonth();
        }

        m_navigatedDate.SetDay(m_nNavigatedDay);
    }

    void Calendar::OnNavigateDayRight() {
        int formerMonthLength = Month::CalculateMonthLength(m_nNavigatedMonth, Year::IsLeapYear(m_nNavigatedYear));
        m_nNavigatedDay++;

        if (m_nNavigatedDay > formerMonthLength) {
            OnNavigateNextMonth();
        }

        m_navigatedDate.SetDay(m_nNavigatedDay);
    }

    void Calendar::OnNavigateDayDown() {
        int formerMonthLength = Month::CalculateMonthLength(m_nNavigatedMonth, Year::IsLeapYear(m_nNavigatedYear));
        m_nNavigatedDay += 7;

        if (m_nNavigatedDay > formerMonthLength) {
            int distance = m_nNavigatedDay - formerMonthLength;
            OnNavigateNextMonth();
            m_nNavigatedDay = distance;
        }

        m_navigatedDate.SetDay(m_nNavigatedDay);
    }

    void Calendar::OnNavigateInit(){
        //Get current date.
        Date currentDate = Date::GetCurrentDate();

        //Obtain the date values.
        m_nNavigatedYear = currentDate.GetYear().GetValue();
        m_nNavigatedMonth = currentDate.GetMonth().GetValueN();
        m_nNavigatedDay = currentDate.GetDay().GetValue();
        
        m_navigatedDate = Date(m_nNavigatedYear, m_nNavigatedMonth, m_nNavigatedDay);
    }

    void Calendar::OnNavigateNextMonth(){
        m_nNavigatedMonth++;
        m_nNavigatedDay = 1;
        if (m_nNavigatedMonth > 12) {
            m_nNavigatedMonth = 1;
            m_nNavigatedYear++;
        }

        if (Settings::ArrayCalendar) {
            if (m_nNavigatedYear > 2029) {
                m_nNavigatedYear = 2029;
                m_nNavigatedMonth = 12;

                MessageBoxView messageBox = MessageBoxView("ArrayCalendar Error",
                    "Does not support years more than 2029!");
                messageBox.Show();
            }
        }

        m_navigatedDate.SetDate(m_nNavigatedYear, m_nNavigatedMonth, m_nNavigatedDay);
    }

    void Calendar::OnNavigatePrevMonth(){
        m_nNavigatedMonth--;

        //Set day to the new month length.
        m_nNavigatedDay = Month::CalculateMonthLength(m_nNavigatedMonth, Year::IsLeapYear(m_nNavigatedYear));
        if (m_nNavigatedMonth < 1) {
            m_nNavigatedMonth = 12;
            m_nNavigatedYear--;
        }

        if (Settings::ArrayCalendar) {
            if (m_nNavigatedYear < 2020) {
                m_nNavigatedYear = 2020;
                m_nNavigatedMonth = 1;

                MessageBoxView messageBox = MessageBoxView("ArrayCalendar Error",
                    "Does not support years less than 2020!");
                messageBox.Show();
            }
        }

        m_navigatedDate.SetDate(m_nNavigatedYear, m_nNavigatedMonth, m_nNavigatedDay);
    }

    void Calendar::Load()
    {
    }

    void Calendar::Save(){

    }
}

