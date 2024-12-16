#include "CalendarView.h"

namespace PlannerCLI{
    CalendarView::CalendarView(Date* navigatedDate)
    {
        //ctor
        SetNavigatedDate(navigatedDate);
    }

    CalendarView::~CalendarView()
    {
        //dtor
        //@NOTE: m_pnDate cannot be deleted because this class is not the owner of that object.
        //Instead, set it to null to avoid dangling pointer.
        m_pnDate = nullptr;
    }

    void CalendarView::Display(){
        CLEAR_SCREEN;

        OnDisplayTitle();

        OnDisplayDaysOfTheWeek();

        OnDisplayCalendarDays();

        OnDisplayBottomBorder();

        DisplayHelpInfo();
    }

    void CalendarView::DisplayHelpInfo()
    {
        DrawSingleLine();
        std::cout << "<>^v Navigation\t\tEnter - OK" << std::endl;
        std::cout << "A - Prev Month\t\tD - Next Month" << std::endl;
        std::cout << "S - Search\t\tEsc - Back" << std::endl;
    }
    void CalendarView::OnDisplayTitle()
    {
        DrawTopBorder();

        //Display the month title and the side border.
        std::string monthName = m_pnDate->GetMonth().GetMonthName() + " " + std::to_string(m_pnDate->GetYear().GetValue());
        DrawHeading(monthName);
    }
    void CalendarView::OnDisplayDaysOfTheWeek()
    {
        //Display the bottom border of month name.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::cout << "Ì";
        for (int i = 1; i <= (CALENDAR_WIDTH - PADDING_RIGHT); i++) {
            int dayOfTheWeekNo = i % ITEM_WIDTH;
            if ((dayOfTheWeekNo == 0)) {
                if (i == (CALENDAR_WIDTH - PADDING_RIGHT))
                    std::cout << "¹" << ANSI_COLOR_RESET << std::endl;
                else
                    std::cout << "Ë";
            }
            else {
                std::cout << "Í";
            }
        }

        //Display the days of the week.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::cout << "º";
        int weekday = 0;
        for (int i = 1; i <= (CALENDAR_WIDTH - PADDING_RIGHT); i++) {
            int dayOfTheWeekNo = i % ITEM_WIDTH;
            if ((dayOfTheWeekNo == 0)) {
                if (i == (CALENDAR_WIDTH - PADDING_RIGHT))
                    std::cout << "º" << ANSI_COLOR_RESET << std::endl;
                else
                    std::cout << "º";
            }
            else if ((dayOfTheWeekNo == 1)) {
                std::string dayOfTheWeekStr = DayOfTheWeek::GetName(weekday);
                std::cout << ANSI_TEXT_COLOR_GRAY << dayOfTheWeekStr.substr(0, 1) << ANSI_TEXT_COLOR_BLACK;
                weekday++;
            }
            else {
                std::cout << " ";
            }
            
        }
    }
    void CalendarView::OnDisplayCalendarDays()
    {
        //Display the dates and the side border.

        int monthSize = m_pnDate->GetMonth().CalculateMonthLength(m_pnDate->GetYear().IsLeapYear());
        int dayOfTheWeek = m_pnDate->GetDay().GetDayOfTheWeek().GetValueN();
        //Decrease day value by the numeric value of the first day of the month's day of the week
        //to show blank dates before day 1 of the calendar.
        int nDay = 1 - m_pnDate->GetMonth().GetFirstDayOfTheWeek().GetValueN();

        do {
            std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
            std::cout << ANSI_TEXT_COLOR_BLACK;
            std::cout << "º";

            for (int i = 0; i < DAYS_OF_THE_WEEK; i++) {
                if ((nDay >= 1) && (nDay <= monthSize)) {
                    //Day* day = month->GetDay(nDay - 1);
                    //Replace with dayOfTheWeek++ once redundant Day array
                    //on Month class are removed.
                    //dayOfTheWeek = day->GetDayOfTheWeekIDNormal(A

                    //Hightlight text if the day is selected.
                    if (nDay == m_pnDate->GetDay().GetValue()) {
                        std::cout << ANSI_BACKGROUND_COLOR_BLUE;
                        std::cout << ANSI_TEXT_COLOR_BRIGHT_WHITE;
                    }

                    std::cout << nDay;

                    if (nDay >= 10) {
                        for (int j = 0; j < (ITEM_WIDTH - 3); j++) {
                            std::cout << " ";
                        }
                    }
                    else {
                        for (int j = 0; j < (ITEM_WIDTH - 2); j++) {
                            std::cout << " ";
                        }
                    }

                    //Unhiglight text if the next day is not selected.
                    if (nDay == m_pnDate->GetDay().GetValue()) {
                        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
                        std::cout << ANSI_TEXT_COLOR_BLACK;
                    }

                    std::cout << "º";

                }
                else {
                    //Print blank dates
                    for (int j = 0; j < (ITEM_WIDTH - 1); j++) {
                        std::cout << " ";
                    }
                    std::cout << "º";
                }

                nDay++;
                dayOfTheWeek++;

            }

            std::cout << ANSI_COLOR_RESET << std::endl;
        } while ((nDay <= monthSize));
    }

    void CalendarView::OnDisplayBottomBorder()
    {
        //Display the bottom border of calendar days.
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;
        std::cout << "È";
        for (int i = 1; i <= (CALENDAR_WIDTH - PADDING_RIGHT); i++) {
            int dayOfTheWeekNo = i % ITEM_WIDTH;
            if ((dayOfTheWeekNo == 0)) {
                if (i == (CALENDAR_WIDTH - PADDING_RIGHT))
                    std::cout << "¼" << ANSI_COLOR_RESET << std::endl;
                else
                    std::cout << "Ê";
            }
            else {
                std::cout << "Í";
            }
        }
    }
}
