#ifndef MONTH_H
#define MONTH_H
#include <string>

namespace PlannerCLI{
    /**
        \brief Handles month information.
    */
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

            /**
                \details A function that returns the length of a month
                based on the month value set within the Month object.

                \param leapYear
            */
            int CalculateMonthLength(bool leapYear = false);

            /**
                \details A static, overloaded function that returns the length
                of a month based on the month value set as an argument.

                \param month The 1-based month value.
                \param leapYear
            */
            static int CalculateMonthLength(int month, bool leapYear = false);

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

            /**
                \brief A function that returns the name of the value of
                the Month object.

                \return std::string
            */
            std::string GetMonthName() const;

            /**
                \brief A static, overloaded function that returns the name of
                the value of the month based on month argument.

                \param month The 1-based month value.
            */
            static std::string GetMonthName(int month);


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
