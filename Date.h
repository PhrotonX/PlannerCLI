#ifndef DATE_H
#define DATE_H

namespace PlannerCLI{
    class Date
    {
        public:
            /**
                \param year 1-based value of year.
                \param year 1-based value of month.
                \param year 1-based value of day.
            */
            Date(int year, int month, int day);
            virtual ~Date();

            Year GetYear() const{
                return m_nYear;
            }

            Month GetMonth() const{
                return m_nMonth;
            }

            Day GetDay() const{
                return m_nDay;
            }

        private:
            Year m_nYear;
            Month m_nMonth;
            Day m_nDay;
    };

}

#endif // DATE_H
