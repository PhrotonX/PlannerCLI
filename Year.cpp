#include "Year.h"

namespace PlannerCLI{
    Year::Year(int year)
    {
        //ctor
        m_bLeapYear = false;
        SetYear(year);
    }

    Year::~Year()
    {
        //dtor
    }
}

