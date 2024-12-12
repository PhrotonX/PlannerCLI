#ifndef DAY_H
#define DAY_H
#include <string>
#include "DayOfTheWeek.h"

namespace PlannerCLI{
    /**
        \brief Handles day information.
    */
    class Day
    {
        public:
            

            Day(){}
            Day(int day);
            virtual ~Day();

            DayOfTheWeek GetDayOfTheWeek() const {
                return m_dayOfTheWeek;
            }

            int GetValue() const{
                return m_nDay;
            }

            void SetDayOfTheWeek(const DayOfTheWeek& dayOfTheWeek) {
                m_dayOfTheWeek = dayOfTheWeek;
            }

            /**
                \brief Set the 1-based day value.

                \param day The 1-based day value.
            */
            void SetValue(int day){
                m_nDay = day;
            }

        private:
            int m_nDay;
            
            DayOfTheWeek m_dayOfTheWeek;
    };
}


#endif // DAY_H
