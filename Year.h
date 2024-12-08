#ifndef YEAR_H
#define YEAR_H
#include "Month.h"

namespace PlannerCLI{
    /**
        \brief Handles year information.
    */
    class Year
    {
        public:
            Year(){}
            Year(int year);
            virtual ~Year();

            int GetValue() const{
                return m_nYear;
            }

            /**
                \return bool Returns true if the year is a leap year.
            */
            bool IsLeapYear() const{
                return m_bLeapYear;
            }

            /**
                \brief Sets the year value and checks for leap year value.
            */
            void SetValue(int year);

        private:
            int m_nYear;
            bool m_bLeapYear;
    };

}

#endif // YEAR_H
