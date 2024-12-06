#ifndef DAY_H
#define DAY_H
#include <string>

namespace PlannerCLI{
    class Day
    {
        public:
            enum DaysOfTheWeek{
                Sunday,
                Monday,
                Tuesday,
                Wednesday,
                Thursday,
                Friday,
                Saturday
            };

            Day(int day);
            Day(int day, DaysOfTheWeek dayOfTheWeek);
            Day(int day, int weekday);
            virtual ~Day();

            int GetValue(){
                return m_nDay;
            }

            /**
                \brief Set the 1-based day value.

                \param day The 1-based day value.
            */
            void SetValue(int day){
                m_nDay = day;
            }

            void SetDayOftheWeek(DaysOfTheWeek dayOfTheWeek){
                m_nDayOfTheWeek = dayOfTheWeek;
            }

            void SetDayOftheWeek(int dayOfTheWeek);

            /**
                \return Returns 0 for Saturday, 6 for Friday, and -1 if not available.
            */
            int GetDayOfTheWeekID();

            std::string GetDayOfTheWeekName();

        private:
            int m_nDay;
            DaysOfTheWeek m_nDayOfTheWeek;
    };
}


#endif // DAY_H
