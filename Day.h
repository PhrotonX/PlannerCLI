#ifndef DAY_H
#define DAY_H
#include <string>

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

        private:
            int m_nDay;
            
    };
}


#endif // DAY_H
