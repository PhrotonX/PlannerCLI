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

        m_bLeapYear = IsLeapYear(year);
    }

    bool Year::IsLeapYear(int year) {
        if((year % 100) == 0){
            if((year % 400) == 0){
                return true;
            }
        }else{
            if((year % 4) == 0){
                return true;
            }
        }

        return false;
    }
}

