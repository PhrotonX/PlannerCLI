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
}

