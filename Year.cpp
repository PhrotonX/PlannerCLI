#include "Year.h"

namespace PlannerCLI{
    Year::Year(int year)
    {
        //ctor
        m_bLeapYear = false;
        SetValue(year);
    }

    Year::~Year()
    {
        //dtor
    }

    void Year::SetValue(int year){
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
}

