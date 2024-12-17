#include "ArrayCalendar.h"

namespace PlannerCLI::typeB {
	ArrayCalendar::ArrayCalendar()
	{
        Init();
	}

	ArrayCalendar::~ArrayCalendar()
	{
        for (int year = 0; year < 137; year++) {
            if (m_year[year] != nullptr) {
                delete m_year[year];
                m_year[year] = nullptr;
            }
        }
	}

    void ArrayCalendar::AddEvent(Event event, Date date) {
        //Date date = event.GetDate();
        int year = date.GetYear().GetValue() - ArrayYear::MIN_YEAR_UNIX;
        int month = date.GetMonth().GetValueN() - 1;
        int day = date.GetDay().GetValue() - 1;

        event.SetDate(date);

        m_year[year]->GetMonth(month)->GetDay(day).AddEvent(event);
    }

    Event& ArrayCalendar::GetEvent(Date date, size_t position)
    {
        int year = date.GetYear().GetValue() - ArrayYear::MIN_YEAR_UNIX;
        int month = date.GetMonth().GetValueN() - 1;
        int day = date.GetDay().GetValue() - 1;

        return m_year[year]->GetMonth(month)->GetDay(day).GetEvent(position);
    }

    std::vector<Event>& ArrayCalendar::GetEventList(Date date)
    {
        int year = date.GetYear().GetValue() - ArrayYear::MIN_YEAR_UNIX;
        int month = date.GetMonth().GetValueN() - 1;
        int day = date.GetDay().GetValue() - 1;

        return m_year[year]->GetMonth(month)->GetDay(day).GetEventList();
    }

    void ArrayCalendar::RemoveEvent(Date date, size_t position)
    {
        int year = date.GetYear().GetValue() - ArrayYear::MIN_YEAR_UNIX;
        int month = date.GetMonth().GetValueN() - 1;
        int day = date.GetDay().GetValue() - 1;

        m_year[year]->GetMonth(month)->GetDay(day).DeleteEvent(position);
    }

    std::vector<Event> ArrayCalendar::SearchEvent(const std::string& query)
    {
        std::vector<Event> results;

        int count = 0;

        for (auto& year : m_year) {
            if (year == nullptr) continue;
            for (int month = 0; month < ArrayMonth::MONTHS; month++) {
                int monthLength = year->GetMonth(month)->GetMonthSize();
                for (int day = 0; day < monthLength; day++) {
                    for (auto& eventItem : year->GetMonth(month)->GetDay(day).GetEventList()) {
                        if (eventItem.GetTitle().find(query) != std::string::npos) {
                            results.push_back(eventItem);

                            count++;
                        }
                    }
                }
            }
        }

        if (count <= 0) {
            results.push_back(m_nullEvent);
        }

        return results;
    }

    void ArrayCalendar::UpdateEvent(Event event)
    {
        Date date = event.GetDate();

        int year = date.GetYear().GetValue() - ArrayYear::MIN_YEAR_UNIX;
        int month = date.GetMonth().GetValueN() - 1;
        int day = date.GetDay().GetValue() - 1;

        m_year[year]->GetMonth(month)->GetDay(day).UpdateEvent(event);
    }

	void ArrayCalendar::Init()
	{
        Seed();
	}

    void ArrayCalendar::Load(){
        std::ifstream file;
        file.open(FILE_CALENDAR, std::ios::in);

        if (file.is_open()) {
            while(!file.eof()) {
                Event event = OnLoadEvent(file);

                if (!event.IsNull()) {
                    Date date = event.GetDate();

                    int year = date.GetYear().GetValue() - ArrayYear::MIN_YEAR_UNIX;
                    int month = date.GetMonth().GetValueN() - 1;
                    int day = date.GetDay().GetValue() - 1;

                    m_year[year]->GetMonth(month)->GetDay(day).AddEvent(event);
                }
                
            }
        }

        file.close();
    }

    void ArrayCalendar::Save(){
        std::ofstream file;
        file.open(FILE_CALENDAR, std::ios::out | std::ios::trunc);
        if (file.is_open()) {
            for (auto& year : m_year) {
                if (year == nullptr) continue;
                for (int month = 0; month < ArrayMonth::MONTHS; month++) {
                    int monthLength = year->GetMonth(month)->GetMonthSize();
                    for (int day = 0; day < monthLength; day++) {
                        for (auto& eventItem : year->GetMonth(month)->GetDay(day).GetEventList()) {
                            OnSaveEvent(file, eventItem);
                        }
                    }
                }
            }
        }
        

        file.close();
    }

    void ArrayCalendar::Seed() {
        //Add 1900 years to each of these variable since tm_year of tm structure
        //uses year 1900 as a base year.
        int minYear = 1900, maxYear = 1900, currentYear = 1900;

        int weekday = 0;

        //unsigned int oldInt = 0; //Represents the first date of UNIX epoch which is January 1, 1970.
        //unsigned int newInt = -1; //Represents the last date of UNIX epoch which is February 7, 2106.

        unsigned int oldInt = 1577836800; //2020
        unsigned int newInt = 1893455999; //2029

        time_t unixTimeBegin = oldInt;
        time_t unixTimeEnd = newInt;
        time_t unixCurrentTime;

        //Get current time
        time(&unixCurrentTime);

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

        //Set current time data into Year objects.
        if(currentYear <= maxYear){
            for(int i = minYear; i <= maxYear; i++){

                m_year[i - ArrayYear::MIN_YEAR_UNIX] = new ArrayYear(i);

                if (Settings::DebugMode)
                    std::cout << "Year: " << i - ArrayYear::MIN_YEAR_UNIX << " i: " << i << " minYear: " << minYear << " ArrayYear: " << m_year[i - ArrayYear::MIN_YEAR_UNIX]->GetValue() << std::endl;

                //Set months into Year objects.
                for(int j = 0; j < 12; j++){
                    ArrayMonth* month = new ArrayMonth(j + 1);
                    if(Settings::DebugMode) std::cout << "Month: " << month->GetValueN() << " " << month->GetMonthName() << std::endl;
                    int monthSize = Month::CalculateMonthLength(month->GetValueN(), m_year[i - ArrayYear::MIN_YEAR_UNIX]->IsLeapYear());
                    month->SetMonthSize(monthSize);
                    for(int k = 0; k < monthSize; k++){
                        ArrayDay day= ArrayDay(k + 1);
                        DayOfTheWeek dayOfTheWeek;
                        dayOfTheWeek.SetValue(weekday);
                        day.SetDayOfTheWeek(dayOfTheWeek);
                        weekday++;
                        if(weekday >= 7) weekday = 0;

                        month->UpdateDay(day);
                    }

                    m_year[i - ArrayYear::MIN_YEAR_UNIX]->SetMonth(std::move(month), j);
                }

            }
        }

        if (Settings::DebugMode) {
            for (int i = minYear; i <= maxYear; i++) {
                for (int j = 0; j < 12; j++) {
                    ArrayMonth* month = m_year[i - ArrayYear::MIN_YEAR_UNIX]->GetMonth(j);
                    std::cout << "Month: " << j << std::endl;
                    int monthSize = Month::CalculateMonthLength(month->GetValueN(), m_year[i - ArrayYear::MIN_YEAR_UNIX]->IsLeapYear());
                    month->SetMonthSize(monthSize);
                    for (int k = 0; k < monthSize; k++) {
                        std::cout << m_year[i - ArrayYear::MIN_YEAR_UNIX]->GetValue() << ", " << month->GetMonthName() << " " << month->GetDay(k).GetValue() << " " << month->GetDay(k).GetDayOfTheWeek().GetName() << std::endl;
                    }
                }
                if (m_year[i - ArrayYear::MIN_YEAR_UNIX]->IsLeapYear()) std::cout << " (leap year)";

                std::cout << "\n";
            }
        }
    }

    void ArrayCalendar::Sort(Date date)
    {
        std::vector<Event> event = GetEventList(date);

        if (event.size() > 1) {
            for (size_t i = 0; i < event.size() - 1; i++) {
                for (size_t j = i; j < event.size() - 1; j++) {
                    Time lowerTime = event.at(j).GetStartTime();
                    Time upperTime = event.at(j + 1).GetStartTime();
                    if (lowerTime.GetHours() > upperTime.GetHours()) {
                        std::swap(event.at(j), event.at(j + 1));
                    }
                }
            }
        }

        for (int i = 0; i < event.size(); i++) {
            event.at(i).SetPosition(i);
        }

    }

}
