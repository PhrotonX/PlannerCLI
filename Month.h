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

            int CalculateMonthLength(const Month& month, bool leapYear = false);

            /**
                \param position The 1-index position of the day.
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


            /**
                \brief Populate the month with Day objects.

                \param firstDayOfTheWeek The first day of the week (0 = Saturday, 6 = Friday) based on
                Zeller's Congruence algorithm in Calendar::CalculateDate().
                \param leapYear (Optional) Set true if the year of the month is a leap year. Used for
                intercalation of additional day in the month of February.
            */
            void Populate(int firstDayOfTheWeek, bool leapYear = false);

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

            int m_nMonthSize;
    };
}


#endif // MONTH_H
