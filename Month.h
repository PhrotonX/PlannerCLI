#ifndef MONTH_H
#define MONTH_H
#include <string>

namespace PlannerCLI{
    class Month
    {
        public:
            inline static const std::string JANUARY = "January";
            inline static const std::string FEBRUARY = "February";
            inline static const std::string MARCH = "March";
            inline static const std::string APRIL = "April";
            inline static const std::string MAY = "May";
            inline static const std::string JUNE = "June";
            inline static const std::string JULY = "July";
            inline static const std::string AUGUST = "August";
            inline static const std::string SEPTEMBER = "September";
            inline static const std::string OCTOBER = "October";
            inline static const std::string NOVEMBER = "November";
            inline static const std::string DECEMBER = "December";

            Month();
            virtual ~Month();

        protected:

            int GetMonthId(){
                return m_nMonthId;
            }

            void SetMonthId(int month){
                m_nMonthId = month;
            }

        private:
            int m_nMonthId;
            std::string m_strMonthName;
    };
}


#endif // MONTH_H
