#ifndef MONTH_H
#define MONTH_H
#include <string>

namespace PlannerCLI{
    class Month
    {
        enum eMonth{
            January,
            February,
            March,
            April,
            May,
            June,
            July,
            August,
            September,
            October,
            November,
            December
        };
        public:
            Month();
            virtual ~Month();

            int GetMonthID();

            std::string GetMonthName();

            void SetMonth(eMonth month){
                m_month = month;
            }

        private:
            eMonth m_month;
    };
}


#endif // MONTH_H
