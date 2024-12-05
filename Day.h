#ifndef DAY_H
#define DAY_H

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

        protected:

        private:
            int m_nDay;
            DaysOfTheWeek m_nDayOfTheWeek;
    };
}


#endif // DAY_H
