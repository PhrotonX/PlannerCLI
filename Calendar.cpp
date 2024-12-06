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

    int Calendar::CalculateDate(Date date){
        int year = date.GetYear();
        int month = date.GetMonth();
        int day = date.GetDay();

        if(month == 1){
            month = 13;
            year--;
        }
        if(month == 2){
            month = 14;
            year--;
        }

        int q = day;
        int m = month;
        int j = year / 100; //zero-based year of the century.
        int k = year % 100; //year of the century
        int h = (q + 13 * ((m + 1) / 5) + k + (k / 4) + (j / 4) + 5 * j);
        h = h % 7;

        std::cout << h << std::endl;
        return h;
    }

    int Calendar::CalculateDayLength(const Year& year, const Month& month){
        switch(month.GetMonth()){
        case Month::February:
            if(year.IsLeapYear())
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

    Date Calendar::GetCurrentDate(){
        int currentYear = 1900;
        int currentMonth;
        int currentDay;
        time_t unixCurrentTime;

        //Get current time
        time(&unixCurrentTime);

        tm* currentTime = localtime(&unixCurrentTime);
        currentYear += currentTime->tm_year;
        currentMonth = currentTime->tm_mon;
        currentDay = currentDay->tm_mday;

        Date date(currentYear, currentMonth, currentDay);

        return date;
    }

    void Calendar::Save(){

    }

    void Calendar::Seed(){
        /*
        //Add 1900 years to each of these variable since tm_year of tm structure
        //uses year 1900 as a base year.
        int minYear = 1900, maxYear = 1900, currentYear = 1900;

        int weekday = 0;

        unsigned int oldInt = 0; //Represents the first date of UNIX epoch.
        unsigned int newInt = -1; //Represents the last date of UNIX epoch.

        time_t unixTimeBegin = oldInt;
        time_t unixTimeEnd = newInt;
        time_t unixCurrentTime;

        //Get current time
        time(&unixCurrentTime);

        std::cout << ctime(&unixTimeBegin) << " from " << unixTimeBegin << std::endl;
        std::cout << ctime(&unixCurrentTime) << " from " << unixCurrentTime << std::endl;
        std::cout << ctime(&unixTimeEnd) << " from " << unixTimeEnd << std::endl;


        //Min
        tm* olderTime = gmtime(&unixTimeBegin);
        minYear += olderTime->tm_year;
        weekday = olderTime->tm_wday;
        std::cout << "Min: " << minYear << " year " << olderTime->tm_year + 1900 << std::endl;

        //Current
        tm* currentTime = localtime(&unixCurrentTime);
        currentYear += currentTime->tm_year;
        std::cout << "Current: " << currentYear << " year " << currentTime->tm_year + 1900 << std::endl;
        std::cout << currentTime->tm_year + 1900 << " " << currentTime->tm_mon + 1 << " "
        << currentTime->tm_yday + 1 << std::endl;

        //Max
        tm* newerTime = gmtime(&unixTimeEnd);
        maxYear += newerTime->tm_year;
        std::cout << "Max: " << maxYear << " year " << newerTime->tm_year + 1900 << std::endl;


        //Get the difference between the minimum year and maximum year.
        int length = (maxYear - minYear) + 1;

        //Allocate a dynamic array (pointer to an array of pointers to a year object) with the size of the difference between
        //the minimum year and the maximum year.
        m_year = (Year**)calloc(length, sizeof(Year**));

        //Set current time data into Year objects.
        if(currentYear <= maxYear){
            for(int i = minYear; i <= maxYear; i++){

                std::cout << i  - minYear << std::endl;
                m_year[i - minYear] = new Year(i);

                //Set months into Year objects.
                for(int j = 0; j < 12; j++){
                    Month* month = new Month(j);
                    int monthSize = CalculateDayLength(*m_year[i - minYear], *month);
                    Day** day = (Day**)calloc(monthSize, sizeof(Day**));
                    for(int k = 0; k < monthSize; k++){
                        day[k] = new Day(k + 1, weekday);
                        weekday++;
                        if(weekday >= 6) weekday = 0;
                    }

                    month->SetDays(day);
                    m_year[i - minYear]->SetMonth(j, month);
                }

            }
        }else{
            //Reallocate the dynamic array
            /*m_year = (Year**)realloc(m_year, 9999 * sizeof(int));
            for(int i = minYear; i <= 9999; i++){
                m_year[i - minYear] = new Year(i);
            }*/
        /*
            //@TODO: Add message for unsupported years (year 2106 and beyond).
        }

        for(int i = minYear; i <= maxYear; i++){
            for(int j = 0; j < 12; j++){
                Month* month = m_year[i - minYear]->GetMonth(j);
                int monthSize = CalculateDayLength(*m_year[i - minYear], *month);
                for(int k = 0; k < monthSize; k++){
                    std::cout << m_year[i - minYear]->GetYear() << ", " << month->GetMonthName() << " " << month->GetDay(k)->GetValue() << std::endl;
                }
            }
            if(m_year[i - minYear]->IsLeapYear()) std::cout << " (leap year)";

            std::cout << "\n";
        }*/

    }
}

