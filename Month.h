#ifndef MONTH_H
#define MONTH_H
#include <string>
#include "Day.h"

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

            Month(eMonth month);

            /**
                \param The zero-based month value.
            */
            Month(int month);
            virtual ~Month();

            /**
                \param position The zero-index position of the day.
                \return Day*& The reference to a pointer to Day object.
            */
            Day*& GetDay(int position){
                return m_day[position];
            }

            /**
                \return Day** The reference to a pointer to a dynamic array of pointers to Day object.
            */
            Day** GetDays() const{
                return m_day;
            }

            /**
                \return The enumerated month value.
            */
            eMonth GetMonth() const{
                return m_month;
            }

            /**
                \return The zero-based month value.
            */
            int GetMonthID() const;

            std::string GetMonthName() const;

            void SetDay(int position, Day* day){
                m_day[position] = day;
            }

            void SetDays(Day** day){
                m_day = day;
            }

            void SetMonth(eMonth month){
                m_month = month;
            }

            void SetMonth(int month);

        private:
            eMonth m_month;

            //Dynamic array. Length of day differs. It could range from 28 to 31.
            Day** m_day;
    };
}


#endif // MONTH_H
