#ifndef YEAR_H
#define YEAR_H

namespace PlannerCLI{
    class Year
    {
        public:
            Year();
            virtual ~Year();

            int GetYear(){
                return m_nYear;
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
    };

}

#endif // YEAR_H
