#include "Calendar.h"

namespace PlannerCLI{
    Calendar::Calendar()
    {
        //ctor
    }

    Calendar::~Calendar()
    {
        //dtor
    }

    Date Calendar::OnNavigateInit(){
        //Get current date.
        Date currentDate = Date::GetCurrentDate();

        //Obtain the date objects for easy access.
        Year currentYear = currentDate.GetYear();
        Month currentMonth = currentDate.GetMonth();

        //Get the first day of the month.
        Date firstDayOfTheMonth = Date(currentYear.GetValue(), currentMonth.GetValueN(), 1);

        //Delete currentDate object.
        //delete currentDate;
        //currentDate = nullptr;

        return firstDayOfTheMonth;
    }

    Date*& Calendar::OnNavigateNext(){
        //Unimplemented
        Date* date = nullptr;
        return date;
    }

    Date*& Calendar::OnNavigatePrev(){
        //Unimplemented
        Date* date = nullptr;
        return date;
    }

    void Calendar::Save(){

    }
}

