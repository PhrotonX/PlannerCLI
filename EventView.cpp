#include "EventView.h"

namespace PlannerCLI {
	void EventView::Display(const std::vector<Event>& event, Date date, int* navigation, int* eventNavigation) {
        CLEAR_SCREEN;

        DrawTopBorder();
        DrawHeading(date.GetFormattedString(true));
        DrawConnectingBorder();

        for (int i = 0; i < BUTTON_COUNT; i++) {
            m_button[i] = new Button(navigation, i);
        }

        m_button[BACK_BUTTON]->SetText("[ BACK ]");
        m_button[ADD_BUTTON]->SetText("[ ADD  ]");

        DrawConnectingBorder();

        Time prevTime;

        m_nNoOfEvents = event.size();

        int i = 0;
        for (auto& eventItem : event) {
            if (!eventItem.IsNull()) {
                std::string time;
                if (eventItem.GetStartTime().GetHours() > prevTime.GetHours() ||
                    eventItem.GetStartTime().GetHours() == 0) {
                    time = std::to_string(eventItem.GetStartTime().GetHours()) + ":00";
                    DrawText(time);
                }

                std::string title = eventItem.GetTitle();
                if (title.length() > (CONTENT_WIDTH - INDENT_WIDTH) - 2) {
                    title = title.substr(0, (CONTENT_WIDTH - INDENT_WIDTH) - 7) + "...";
                }

                if (*eventNavigation == i && *navigation == EVENT_LIST) {
                    SetColor(ANSI_BACKGROUND_COLOR_BLUE, ANSI_TEXT_COLOR_BRIGHT_WHITE);
                    DrawText(BULLET + " " + title);
                    SetColorDefaults();
                }
                else {
                    DrawText(BULLET + " " + title);
                }

                prevTime = eventItem.GetStartTime();

                DrawText(" ");
            }
            else {
                DrawText("No events to display");
            }
            
            i++;
        }

        DrawBottomBorder();

        for (int i = 0; i < BUTTON_COUNT; i++) {
            m_button[i]->Display(false);
            std::cout << " ";
        }
        std::cout << std::endl;

        HelpInfo();
	}

    void EventView::HelpInfo() {
        SetColorDefaults();
        DrawSingleLine();

        std::cout << "<> Button Navigation\t\t^v Event Navigation" << std::endl;
        std::cout << "D - Delete\t\tAny key - Enter/Edit" << std::endl;
    }
    
}