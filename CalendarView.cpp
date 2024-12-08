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
        for(int i = 0; i < (CALENDAR_WIDTH - PADDING); i++){
            std::cout << "Í";
        }
        std::cout << "»" << ANSI_COLOR_RESET << std::endl;

        //Display the month title and the side border.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::string monthName = month->GetMonthName();
        int monthNameMargin = ((CALENDAR_WIDTH - PADDING) - monthName.size()) - 1;

        std::cout << "º " << monthName;
        for(int i = 0; i < monthNameMargin; i++){
            std::cout << " ";
        }
        std::cout << "º" << ANSI_COLOR_RESET << std::endl;

        //Display the bottom border.
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
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        //int day = 0;
        /*for(int i = 0; i < (CALENDAR_WIDTH - 2); i++){
            if((i % ITEM_WIDTH) == 0){
                std::cout << "º";
            }else{
                if(i >= 10){
                    std::cout << month->GetDay(day)->GetValue();
                    for(int j = 0; j < (ITEM_WIDTH - 2); j++){
                        std::cout << " ";
                    }
                }
            }

            std::cout << ANSI_COLOR_RESET << std::endl;
            day++;
        }*/

        /*
        for(int i = 0; i < month->GetMonthSize(); i++){
            std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
            std::cout << ANSI_TEXT_COLOR_BLACK;
            std::cout << "º";
            for(int j = 0; j < DAYS_OF_THE_WEEK; j++){


                //for(int k = 0; k < ITEM_HEIGHT; k++){
                    if(j == 0/* && k == 0*///){
                        /*std::cout << month->GetDay(i)->GetValue();
                    }else if((j % ITEM_WIDTH) == 0){
                        std::cout << "º";
                    }else if(j >= 1){
                        if(((i + 1) >= 10) && (j == (ITEM_WIDTH - 1)))
                            continue;
                        std::cout << " ";
                    }
                //}
            }
            std::cout << ANSI_COLOR_RESET << std::endl;
        }*/


        int nDay = 0;
        int monthSize = month->GetMonthSize();
        do{
            std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
            std::cout << ANSI_TEXT_COLOR_BLACK;
            std::cout << "º";

            for(int i = 0; i < DAYS_OF_THE_WEEK; i++){
                Day* day = month->GetDay(nDay);
                int dayOfTheWeek = day->GetDayOfTheWeekIDNormal();
                int dayValue = day->GetValue();

                std::cout << dayValue;

                if(dayValue >= 10){
                    for(int j = 0; j < (ITEM_WIDTH - 3); j++){
                        std::cout << " ";
                    }
                }else{
                    for(int j = 0; j < (ITEM_WIDTH - 2); j++){
                        std::cout << " ";
                    }
                }

                std::cout << "º";

                nDay++;
            }

            std::cout << ANSI_COLOR_RESET << std::endl;
        }while(nDay < monthSize);
    }

}
