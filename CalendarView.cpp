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

    void CalendarView::Display(Date& date){
        CLEAR_SCREEN;

        //Display the top border.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::cout << "É";
        for(int i = 0; i < (CALENDAR_WIDTH - PADDING); i++){
            std::cout << "Í";
        }
        std::cout << "»" << ANSI_COLOR_RESET << std::endl;

        //Display the month title and the side border.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::string monthName = date.GetMonth().GetMonthName() + " " + std::to_string(date.GetYear().GetValue());
        int monthNameMargin = ((CALENDAR_WIDTH - PADDING) - monthName.size()) - 1;

        std::cout << "º " << monthName;
        for(int i = 0; i < monthNameMargin; i++){
            std::cout << " ";
        }
        std::cout << "º" << ANSI_COLOR_RESET << std::endl;

        //Display the bottom border of month name.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;
        std::cout << "Ì";
        for(int i = 1; i <= (CALENDAR_WIDTH - PADDING_RIGHT); i++){
            int dayOfTheWeekNo = i % ITEM_WIDTH;
            if((dayOfTheWeekNo == 0)){
                if(i == (CALENDAR_WIDTH - PADDING_RIGHT))
                    std::cout << "¹" << ANSI_COLOR_RESET << std::endl;
                else
                    std::cout << "Ë";
            }else{
                std::cout << "Í";
            }
        }

        //Display the dates and the side border.

        int monthSize = date.GetMonth().CalculateMonthLength(date.GetYear().IsLeapYear());
        int dayOfTheWeek = date.GetDay().GetDayOfTheWeekID();
        int nDay = 1 - dayOfTheWeek;

        do{
            std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
            std::cout << ANSI_TEXT_COLOR_BLACK;
            std::cout << "º";

            for(int i = 0; i < DAYS_OF_THE_WEEK; i++){
                if((nDay >= 1) && (nDay <= monthSize)){
                    //Day* day = month->GetDay(nDay - 1);
                    //Replace with dayOfTheWeek++ once redundant Day array
                    //on Month class are removed.
                    //dayOfTheWeek = day->GetDayOfTheWeekIDNormal();

                    std::cout << nDay;

                    if(nDay >= 10){
                        for(int j = 0; j < (ITEM_WIDTH - 3); j++){
                            std::cout << " ";
                        }
                    }else{
                        for(int j = 0; j < (ITEM_WIDTH - 2); j++){
                            std::cout << " ";
                        }
                    }

                    std::cout << "º";

                }else{
                    //Print blank dates
                    for(int j = 0; j < (ITEM_WIDTH - 1); j++){
                        std::cout << " ";
                    }
                    std::cout << "º";
                }

                nDay++;
                dayOfTheWeek++;

            }

            std::cout << ANSI_COLOR_RESET << std::endl;
        }while((nDay <= monthSize));

        //Display the bottom border of calendar days.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;
        std::cout << "È";
        for(int i = 1; i <= (CALENDAR_WIDTH - PADDING_RIGHT); i++){
            int dayOfTheWeekNo = i % ITEM_WIDTH;
            if((dayOfTheWeekNo == 0)){
                if(i == (CALENDAR_WIDTH - PADDING_RIGHT))
                    std::cout << "¼" << ANSI_COLOR_RESET << std::endl;
                else
                    std::cout << "Ê";
            }else{
                std::cout << "Í";
            }
        }
    }
}
