#ifndef MONTH_H
#define MONTH_H
#include <string>

namespace PlannerCLI{
    class Month
    {
        public:
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

            Month(){}

            /**
                \details A constructor that calls Populate() method.

                \param month The enumerated month value.
            */
            Month(eMonth month);

            /**
                \details A constructor that calls Populate() method.

                \param month The 1-based month value.
            */
            Month(int month);
            virtual ~Month();

            int CalculateMonthLength(bool leapYear = false);
            int CalculateMonthLength(int month, bool leapYear = false);

            int GetMonthSize() const{
                return m_nMonthSize;
            }

            /**
                \return The enumerated month value.
            */
            eMonth GetValue() const{
                return m_month;
            }

            /**
                \return The 1-based month value.
            */
            int GetValueN() const;

            std::string GetMonthName() const;

            std::string GetMonthName(int month) const;


            void SetMonth(eMonth month){
                m_month = month;
            }

            void SetMonth(int month);

        private:
            eMonth m_month;

            int m_nMonthSize;
    };
}


#endif // MONTH_H
