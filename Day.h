#ifndef DAY_H
#define DAY_H
#include <string>

namespace PlannerCLI{
    class Day
    {
        enum DaysOfTheWeek{
            Sunday,
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday
        };
        public:
            Day();
            virtual ~Day();

            int GetDay(){
                return m_nDay;
            }

            void SetDay(int day){
                m_nDay = day;
            }

            int GetDayOfTheWeekN();

            std::string GetDayOfTheWeekStr();

        private:
            int m_nDay;
            DaysOfTheWeek m_nDayOfTheWeek;
    };
}


#endif // DAY_H
