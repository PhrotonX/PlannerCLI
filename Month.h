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

        protected:
            std::string GetMonthName();

            void SetMonth(eMonth month){
                m_monthId = month;
            }

        private:
            eMonth m_monthId;
            std::string m_strMonthName;
    };
}


#endif // MONTH_H
