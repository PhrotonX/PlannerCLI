#include "CalendarView.h"

namespace PlannerCLI{
    CalendarView::CalendarView()
    {
        //ctor
    }

    CalendarView::~CalendarView()
    {
        //dtor
    }

    void CalendarView::Display(){

    }

    void CalendarView::Display(Month*& month){
        //Display the top border.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::cout << "É";
        for(int i = 0; i < (CALENDAR_WIDTH - 2); i++){
            std::cout << "Í";
        }
        std::cout << "»" << ANSI_COLOR_RESET << std::endl;

        //Display the month title and the side border.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::string monthName = month->GetMonthName();
        int monthNameMargin = ((CALENDAR_WIDTH - 2) - monthName.size()) - 1;

        std::cout << "º " << monthName;
        for(int i = 0; i < monthNameMargin; i++){
            std::cout << " ";
        }
        std::cout << "º" << ANSI_COLOR_RESET << std::endl;

        //Display the bottom border.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;
        std::cout << "È";
        for(int i = 0; i < (CALENDAR_WIDTH - 2); i++){
            std::cout << "Í";
        }
        std::cout << "¼" << ANSI_COLOR_RESET << std::endl;
    }

}
