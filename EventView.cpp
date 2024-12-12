#include "EventView.h"

namespace PlannerCLI {
	void EventView::Display(const std::vector<Event>& event, Date date) {
        CLEAR_SCREEN;

        DrawTopBorder();
        DrawHeading(date.GetFormattedString(true));
        DrawConnectingBorder();

        Time prevTime;

        for (auto& eventItem : event) {
            if (!eventItem.IsNull()) {
                DrawText(" ");
                if (eventItem.GetStartTime().GetHours() >= prevTime.GetHours()) {
                    DrawText(TAB + std::to_string(eventItem.GetStartTime().GetHours()));
                }

                std::string shortenedText = eventItem.GetTitle();
                if (shortenedText.length() > (CONTENT_WIDTH - INDENT_WIDTH)) {
                    DrawText(BULLET + shortenedText.substr(0, (CONTENT_WIDTH - INDENT_WIDTH) - 3) + "...");
                }

                prevTime = eventItem.GetStartTime();
            }
            else {
                DrawText("No events to display");
            }
            
        }

        DrawBottomBorder();
	}

    
}