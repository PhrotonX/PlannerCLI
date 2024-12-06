#ifndef YEAR_H
#define YEAR_H
#include "Month.h"

namespace PlannerCLI{
    class Year
    {
        public:
            Year(int year);
            virtual ~Year();

            /**
                \param position The zero-based month value. E.g. 0 for January,
                1 for February, and so on.
            */
            Month*& GetMonth(int month){
                return m_month[month];
            }

            int GetYear() const{
                return m_nYear;
            }

            bool IsLeapYear() const{
                return m_bLeapYear;
            }

            /**
                \param position The zero-based month value or ID.
                \param month The month object.
            */
            void SetMonth(int position, Month*& month){
                m_month[position] = month;
            }

            void SetYear(int year){
                m_nYear = year;

                if((year % 100) == 0){
                    if((year % 400) == 0){
                        m_bLeapYear = true;
                    }
                }else{
                    if((year % 4) == 0){
                        m_bLeapYear = true;
                    }
                }
            }



        private:
            int m_nYear;
            bool m_bLeapYear;

            Month* m_month[12];
    };

}

#endif // YEAR_H
