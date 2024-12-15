#include "DayOfTheWeek.h"

namespace PlannerCLI {
    int DayOfTheWeek::CalculateDayOfTheWeek(int year, int month, int day) {
        if (month == 1) {
            month = 13;
            year--;
        }
        if (month == 2) {
            month = 14;
            year--;
        }

        int q = day;
        int m = month;
        int j = year / 100; //zero-based year of the century.
        int k = year % 100; //year of the century
        int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
        h = h % 7;

        return h;
    }

    int DayOfTheWeek::GetValueN() const {
        switch (m_dayOfTheWeek) {
        case DayOfTheWeek::Sunday:
            return 0;
        case DayOfTheWeek::Monday:
            return 1;
        case DayOfTheWeek::Tuesday:
            return 2;
        case DayOfTheWeek::Wednesday:
            return 3;
        case DayOfTheWeek::Thursday:
            return 4;
        case DayOfTheWeek::Friday:
            return 5;
        case DayOfTheWeek::Saturday:
            return 6;
        default:
            return -1;
            break;
        }
    }

    std::string DayOfTheWeek::GetName() const {
        switch (m_dayOfTheWeek) {
        case DayOfTheWeek::Sunday:
            return "Sunday";
        case DayOfTheWeek::Monday:
            return "Monday";
        case DayOfTheWeek::Tuesday:
            return "Tuesday";
        case DayOfTheWeek::Wednesday:
            return "Wednesday";
        case DayOfTheWeek::Thursday:
            return "Thursday";
        case DayOfTheWeek::Friday:
            return "Friday";
        case DayOfTheWeek::Saturday:
            return "Saturday";
        default:
            break;
        }
    }

    void DayOfTheWeek::SetValue(const int& dayOfTheWeek) {
        switch (dayOfTheWeek) {
        case 0:
            m_dayOfTheWeek = Sunday;
            break;
        case 1:
            m_dayOfTheWeek = Monday;
            break;
        case 2:
            m_dayOfTheWeek = Tuesday;
            break;
        case 3:
            m_dayOfTheWeek = Wednesday;
            break;
        case 4:
            m_dayOfTheWeek = Thursday;
            break;
        case 5:
            m_dayOfTheWeek = Friday;
            break;
        case 6:
            m_dayOfTheWeek = Saturday;
            break;
        default:
            break;
        }
    }

    void DayOfTheWeek::SetValueZC(int dayOfTheWeek) {
        switch (dayOfTheWeek) {
        case 1:
            m_dayOfTheWeek = Sunday;
            break;
        case 2:
            m_dayOfTheWeek = Monday;
            break;
        case 3:
            m_dayOfTheWeek = Tuesday;
            break;
        case 4:
            m_dayOfTheWeek = Wednesday;
            break;
        case 5:
            m_dayOfTheWeek = Thursday;
            break;
        case 6:
            m_dayOfTheWeek = Friday;
            break;
        case 0:
            m_dayOfTheWeek = Saturday;
            break;
        default:
            break;
        }
    }
}