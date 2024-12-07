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

        std::cout << "�";
        for(int i = 0; i < (CALENDAR_WIDTH - PADDING); i++){
            std::cout << "�";
        }
        std::cout << "�" << ANSI_COLOR_RESET << std::endl;

        //Display the month title and the side border.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::string monthName = month->GetMonthName();
        int monthNameMargin = ((CALENDAR_WIDTH - PADDING) - monthName.size()) - 1;

        std::cout << "� " << monthName;
        for(int i = 0; i < monthNameMargin; i++){
            std::cout << " ";
        }
        std::cout << "�" << ANSI_COLOR_RESET << std::endl;

        //Display the bottom border of month name.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;
        std::cout << "�";
        for(int i = 1; i <= (CALENDAR_WIDTH - PADDING_RIGHT); i++){
            int dayOfTheWeekNo = i % ITEM_WIDTH;
            if((dayOfTheWeekNo == 0)){
                if(i == (CALENDAR_WIDTH - PADDING_RIGHT))
                    std::cout << "�" << ANSI_COLOR_RESET << std::endl;
                else
                    std::cout << "�";
            }else{
                std::cout << "�";
            }
        }

        //Display the dates and the side border.
        int monthSize = month->GetMonthSize();
        int dayOfTheWeek = 0;
        int nDay = 1 - month->GetDay(0)->GetDayOfTheWeekIDNormal();

        do{
            std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
            std::cout << ANSI_TEXT_COLOR_BLACK;
            std::cout << "�";

            for(int i = 0; i < DAYS_OF_THE_WEEK; i++){
                if((nDay >= 1) && (nDay <= monthSize)){
                    //Day* day = month->GetDay(nDay - 1);
                    //Replace with dayOfTheWeek++ one redundant Day array
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

                    std::cout << "�";

                    nDay++;
                }else{
                    //Print blank dates
                    for(int j = 0; j < (ITEM_WIDTH - 1); j++){
                        std::cout << " ";
                    }
                    std::cout << "�";
                }

                dayOfTheWeek++;

            }

            std::cout << ANSI_COLOR_RESET << std::endl;
        }while((nDay < monthSize) || (dayOfTheWeek < 6));

        //Display the bottom border of calendar days.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;
        std::cout << "�";
        for(int i = 1; i <= (CALENDAR_WIDTH - PADDING_RIGHT); i++){
            int dayOfTheWeekNo = i % ITEM_WIDTH;
            if((dayOfTheWeekNo == 0)){
                if(i == (CALENDAR_WIDTH - PADDING_RIGHT))
                    std::cout << "�" << ANSI_COLOR_RESET << std::endl;
                else
                    std::cout << "�";
            }else{
                std::cout << "�";
            }
        }
    }
}
