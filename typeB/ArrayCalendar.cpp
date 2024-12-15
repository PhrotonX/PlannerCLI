#include "ArrayCalendar.h"

namespace PlannerCLI::typeB {
	ArrayCalendar::ArrayCalendar()
	{
	}

	ArrayCalendar::~ArrayCalendar()
	{
	}

    Date* ArrayCalendar::OnNavigateInit()
    {
        return nullptr;
    }

    Date* ArrayCalendar::OnNavigateNext()
    {
        return nullptr;
    }

    Date* ArrayCalendar::OnNavigateBack()
    {
        return nullptr;
    }

	void ArrayCalendar::Init()
	{
        Seed();

        
        m_navigatedDate = Date::GetCurrentDate();


        /*
        m_year = std::move(currentDate->GetYear());
        m_month = std::move(currentDate->GetMonth());
        
        Date* firstDayOfTheMonth = new Date(currentYear->GetValue(), currentMonth->GetValueN(), 1);
        int firstDayOfTheMonth_dayOfTheWeek = firstDayOfTheMonth->CalculateDayOfTheWeek();

        Month* month = new Month(currentMonth->GetValueN() - 1);
        month->Populate(firstDayOfTheMonth_dayOfTheWeek, firstDayOfTheMonth->GetYear()->IsLeapYear());

        int monthSize = month->GetMonthSize();
        std::cout << "Month Size: " << monthSize << std::endl;
        for (int i = 0; i < monthSize; i++) {
            std::cout << month->GetMonthName() << " "
                << month->GetDay(i)->GetValue() << ", "
                << currentYear->GetValue() << " "
                << month->GetDay(i)->GetDayOfTheWeekName() << std::endl;
        }

        return m_date;*/
	}

    void ArrayCalendar::Seed() {
        //Add 1900 years to each of these variable since tm_year of tm structure
        //uses year 1900 as a base year.
        int minYear = 1900, maxYear = 1900, currentYear = 1900;

        int weekday = 0;

        //unsigned int oldInt = 0; //Represents the first date of UNIX epoch.
        //unsigned int newInt = -1; //Represents the last date of UNIX epoch.

        unsigned int oldInt = 1577836800; //2020
        unsigned int newInt = 1893455999; //2029

        time_t unixTimeBegin = oldInt;
        time_t unixTimeEnd = newInt;
        time_t unixCurrentTime;

        //Get current time
        time(&unixCurrentTime);

        //std::cout << ctime_s(&unixTimeBegin) << " from " << unixTimeBegin << std::endl;
        //std::cout << ctime_s(&unixCurrentTime) << " from " << unixCurrentTime << std::endl;
        //std::cout << ctime_s(&unixTimeEnd) << " from " << unixTimeEnd << std::endl;


        //Min
        tm olderTime;
        gmtime_s(&olderTime, &unixTimeBegin);
        minYear += olderTime.tm_year;
        weekday = olderTime.tm_wday;
        if (Settings::DebugMode) std::cout << "Min: " << minYear << " year " << olderTime.tm_year + 1900 << std::endl;

        //Current
        tm currentTime;
        localtime_s(&currentTime, &unixCurrentTime);
        currentYear += currentTime.tm_year;
        if (Settings::DebugMode) std::cout << "Current: " << currentYear << " year " << currentTime.tm_year + 1900 << std::endl;
        if (Settings::DebugMode) std::cout << currentTime.tm_year + 1900 << " " << currentTime.tm_mon + 1 << " "
        << currentTime.tm_yday + 1 << std::endl;

        //Max
        tm newerTime;
        gmtime_s(&newerTime, &unixTimeEnd);
        maxYear += newerTime.tm_year;
        if (Settings::DebugMode) std::cout << "Max: " << maxYear << " year " << newerTime.tm_year + 1900 << std::endl;


        //Get the difference between the minimum year and maximum year.
        int length = (maxYear - minYear) + 1;

        //Allocate a dynamic array (pointer to an array of pointers to a year object) with the size of the difference between
        //the minimum year and the maximum year.
        //m_year = (Year**)calloc(length, sizeof(Year**));

        //Set current time data into Year objects.
        if(currentYear <= maxYear){
            for(int i = minYear; i <= maxYear; i++){

                m_year[i - minYear] = new ArrayYear(i);

                if (Settings::DebugMode)
                    std::cout << "Year: " << i - minYear << " i: " << i << " minYear: " << minYear << " ArrayYear: " << m_year[i - minYear]->GetValue() << std::endl;

                //Set months into Year objects.
                for(int j = 0; j < 12; j++){
                    ArrayMonth* month = new ArrayMonth(j);
                    int monthSize = Month::CalculateMonthLength(month->GetValueN(), m_year[i - minYear]->IsLeapYear());
                    month->SetMonthLength(monthSize);
                    for(int k = 0; k < monthSize; k++){
                        ArrayDay day= ArrayDay(k + 1);
                        DayOfTheWeek dayOfTheWeek;
                        dayOfTheWeek.SetValue(weekday);
                        day.SetDayOfTheWeek(dayOfTheWeek);
                        weekday++;
                        if(weekday >= 6) weekday = 0;

                        month->UpdateDay(day);
                    }

                    m_year[i - minYear]->SetMonth(std::move(month), j);
                }

            }
        }else{
            //Reallocate the dynamic array
            /*m_year = (Year**)realloc(m_year, 9999 * sizeof(int));
            for(int i = minYear; i <= 9999; i++){
                m_year[i - minYear] = new Year(i);
            }*/
            
                //@TODO: Add message for unsupported years (year 2106 and beyond).
        }

        for(int i = minYear; i <= maxYear; i++){
            for(int j = 0; j < 12; j++){
                ArrayMonth* month = m_year[i - minYear]->GetMonth(j);
                int monthSize = Month::CalculateMonthLength(month->GetValueN(), m_year[i - minYear]->IsLeapYear());
                month->SetMonthLength(monthSize);
                for(int k = 0; k < monthSize; k++){
                    if (Settings::DebugMode) std::cout << m_year[i - minYear]->GetValue() << ", " << month->GetMonthName() << " " << month->GetDay(k).GetValue() << std::endl;
                }
            }
            if (Settings::DebugMode) if(m_year[i - minYear]->IsLeapYear()) std::cout << " (leap year)";

            if (Settings::DebugMode) std::cout << "\n";
        }
    }

}
