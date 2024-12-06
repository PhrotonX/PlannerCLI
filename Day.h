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
            Day(int day, DaysOfTheWeek dayOfTheWeek);
            Day(int day, int weekday);
            virtual ~Day();

            int GetValue(){
                return m_nDay;
            }

            /**
                \brief Set the zero-based day value.

                \param day The zero-based day value.
            */
            void SetValue(int day){
                m_nDay = day;
            }

            void SetDayOftheWeek(DaysOfTheWeek dayOfTheWeek){
                m_nDayOfTheWeek = dayOfTheWeek;
            }

            void SetDayOftheWeek(int dayOfTheWeek);

            int GetDayOfTheWeekID();

            std::string GetDayOfTheWeekName();

        private:
            int m_nDay;
            DaysOfTheWeek m_nDayOfTheWeek;
    };
}


#endif // DAY_H
